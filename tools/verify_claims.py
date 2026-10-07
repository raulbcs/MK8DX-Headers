#!/usr/bin/env python3
"""Mechanical --verify engine for comment_audit.py (imported, not run directly).

Verifies claims from tools/claims.db against:
  - /tmp/full.asm       (flat disassembly, llvm-objdump style)
  - ELF phdrs of main.elf (LOAD2 off 0xb55ed8 va 0xb56000, LOAD3 off 0x11ac370 va 0x11ad000)
  - /tmp/relocs.txt     (llvm-objdump -R dump; generated if missing)

Statuses: ok / bad / warn / skip. detail column gets "VERIFY: ..." annotation.

One-time indexes (instruction addresses, labels, bl-target counts) are pickled
under /tmp/comment_audit_cache/ for fast reruns.
"""

import os
import pickle
import re
import sqlite3
import struct
import subprocess
from bisect import bisect_right
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INCLUDE = os.path.join(ROOT, "include")
ELF_PATH = "/Users/raul/projects/mk8dx-400/data/main.elf"
ASM_PATH = "/tmp/full.asm"
RELOCS_PATH = "/tmp/relocs.txt"
CACHE_DIR = "/tmp/comment_audit_cache"

# Address normalization: runtime flat .text base.
RUNTIME_BASE = 0x7100000000

MIN_ADDR = 0x10000

ADDR_TOKEN_RE = re.compile(r"0x[0-9a-fA-F]+")
INST_LINE_RE = re.compile(r"^\s*([0-9a-f]+): ([0-9a-f]{8})\b")
LABEL_LINE_RE = re.compile(r"^([0-9a-f]{12,16}) <([^>]+)>:")
BL_RE = re.compile(r"\bbl\s+0x([0-9a-f]+)")
STORE_RE = re.compile(r"\b(st|stp|stlr|stlrb|stlrh|stnp)\b")
ADRP_RE = re.compile(r"adrp\tx(\d+), 0x([0-9a-f]+)")


# ---------------------------------------------------------------- ELF phdrs --
def _load_segments():
    """[(vaddr, filesz, offset)] for PT_LOAD segments."""
    with open(ELF_PATH, "rb") as f:
        hdr = f.read(64)
        e_phoff = struct.unpack_from("<Q", hdr, 0x20)[0]
        e_phentsize = struct.unpack_from("<H", hdr, 0x36)[0]
        e_phnum = struct.unpack_from("<H", hdr, 0x38)[0]
        f.seek(e_phoff)
        phdrs = f.read(e_phentsize * e_phnum)
    segs = []
    for i in range(e_phnum):
        p = phdrs[i * e_phentsize:(i + 1) * e_phentsize]
        p_type = struct.unpack_from("<I", p, 0)[0]
        p_offset = struct.unpack_from("<Q", p, 0x08)[0]
        p_vaddr = struct.unpack_from("<Q", p, 0x10)[0]
        p_filesz = struct.unpack_from("<Q", p, 0x20)[0]
        p_memsz = struct.unpack_from("<Q", p, 0x28)[0]
        if p_type == 1:  # PT_LOAD
            segs.append((p_vaddr, p_filesz, p_memsz, p_offset))
    segs.sort()
    return segs


_SEGMENTS = None


def va_to_off(va):
    global _SEGMENTS
    if _SEGMENTS is None:
        _SEGMENTS = _load_segments()
    for vaddr, filesz, _memsz, offset in _SEGMENTS:
        if vaddr <= va < vaddr + filesz:
            return offset + (va - vaddr)
    return None


def is_bss(va):
    global _SEGMENTS
    if _SEGMENTS is None:
        _SEGMENTS = _load_segments()
    for vaddr, filesz, memsz, _offset in _SEGMENTS:
        if vaddr + filesz <= va < vaddr + memsz:
            return True
    return False


def read_qword(va):
    off = va_to_off(va)
    if off is None:
        return None
    with open(ELF_PATH, "rb") as f:
        f.seek(off)
        b = f.read(8)
        if len(b) < 8:
            return None
        return struct.unpack("<Q", b)[0]


# ------------------------------------------------------------------- relocs --
def load_relocs():
    if not os.path.exists(RELOCS_PATH):
        out = subprocess.run(
            ["llvm-objdump", "-R", ELF_PATH],
            capture_output=True, text=True)
        if out.returncode != 0:
            out = subprocess.run(["objdump", "-R", ELF_PATH],
                                 capture_output=True, text=True)
        with open(RELOCS_PATH, "w") as f:
            f.write(out.stdout)
    relocs = {}
    rx = re.compile(r"^([0-9a-f]+)\s+R_AARCH64_RELATIVE\s+\*ABS\*\+0x([0-9a-f]+)")
    with open(RELOCS_PATH) as f:
        for line in f:
            m = rx.match(line)
            if m:
                relocs[int(m.group(1), 16)] = int(m.group(2), 16)
    return relocs


# ------------------------------------------------------------------ asm index --
def _build_asm_index():
    inst_addrs = set()
    labels = []          # (addr, line_no) sorted by addr
    bl_counts = Counter()
    with open(ASM_PATH, errors="replace") as f:
        for ln, line in enumerate(f, 1):
            m = LABEL_LINE_RE.match(line)
            if m:
                labels.append((int(m.group(1), 16), ln))
                continue
            m = INST_LINE_RE.match(line)
            if m:
                a = int(m.group(1), 16)
                inst_addrs.add(a)
                m2 = BL_RE.search(line)
                if m2:
                    bl_counts[int(m2.group(1), 16)] += 1
    labels.sort()
    return inst_addrs, labels, bl_counts


class AsmIndex:
    def __init__(self):
        cache = os.path.join(CACHE_DIR, "asm_index.pkl")
        if os.path.exists(cache):
            with open(cache, "rb") as f:
                self.inst_addrs, self.labels, self.bl_counts = pickle.load(f)
        else:
            self.inst_addrs, self.labels, self.bl_counts = _build_asm_index()
            os.makedirs(CACHE_DIR, exist_ok=True)
            with open(cache, "wb") as f:
                pickle.dump((self.inst_addrs, self.labels, self.bl_counts), f)
        self._label_addrs = [a for a, _ in self.labels]
        self._body_cache = {}

    def is_text(self, addr):
        return addr in self.inst_addrs

    def enclosing_label(self, addr):
        i = bisect_right(self._label_addrs, addr) - 1
        if i < 0:
            return None
        return self.labels[i]

    def next_label(self, addr):
        i = bisect_right(self._label_addrs, addr)
        if i < len(self.labels):
            return self.labels[i]
        return None

    def function_body(self, addr):
        """(start_line, end_line_exclusive) of the enclosing 'function'."""
        lab = self.enclosing_label(addr)
        if lab is None:
            return None
        nxt = self.next_label(addr)
        start = lab[1]
        end = nxt[1] if nxt else start + 1
        key = (start, end)
        if key not in self._body_cache:
            with open(ASM_PATH, errors="replace") as f:
                f.seek(0)
                lines = []
                for ln, line in enumerate(f, 1):
                    if ln > end:
                        break
                    if ln >= start:
                        lines.append(line)
                self._body_cache[key] = lines
            if len(self._body_cache) > 32:
                self._body_cache.pop(next(iter(self._body_cache)))
        return self._body_cache[key]

    def body_text(self, addr):
        lab = self.enclosing_label(addr)
        if lab is None:
            return None
        nxt = self.next_label(addr)
        start, end = lab[1], (nxt[1] if nxt else lab[1] + 1)
        key = (start, end)
        if key not in self._body_cache:
            with open(ASM_PATH, errors="replace") as f:
                f.seek(0)
                lines = []
                for ln, line in enumerate(f, 1):
                    if ln > end:
                        break
                    if ln >= start:
                        lines.append(line)
                self._body_cache[key] = lines
            if len(self._body_cache) > 16:
                self._body_cache.pop(next(iter(self._body_cache)))
        return "".join(self._body_cache[key])


# -------------------------------------------------------------- identifiers --
def _build_identifiers():
    ident = set()
    rx = re.compile(r"\b([A-Z][A-Za-z0-9_]{2,})\b")
    for dirpath, _d, files in os.walk(INCLUDE):
        for fn in files:
            if not fn.endswith((".hpp", ".h")):
                continue
            with open(os.path.join(dirpath, fn), errors="replace") as f:
                for m in rx.finditer(f.read()):
                    ident.add(m.group(1))
    return ident


def load_identifiers():
    cache = os.path.join(CACHE_DIR, "idents.pkl")
    if os.path.exists(cache):
        with open(cache, "rb") as f:
            return pickle.load(f)
    idents = _build_identifiers()
    os.makedirs(CACHE_DIR, exist_ok=True)
    with open(cache, "wb") as f:
        pickle.dump(idents, f)
    return idents


# --------------------------------------------------------------- verification --
class Verifier:
    def __init__(self):
        self.asm = AsmIndex()
        self.relocs = load_relocs()
        self.idents = load_identifiers()
        self.rev = defaultdict(list)
        for off, add in self.relocs.items():
            self.rev[add].append(off)

    def vtable_confirmed(self, a):
        """True if reloc cell(s) point at a (vtable base, ctor adds 0x10) or a+0x10."""
        return bool(self.rev.get(a) or self.rev.get(a + 0x10)), self.rev.get(a) or self.rev.get(a + 0x10)

    @staticmethod
    def norm(addr):
        if addr >= RUNTIME_BASE:
            return addr - RUNTIME_BASE
        if 0x710000000 <= addr < RUNTIME_BASE:
            # 9-digit runtime form (base 0x710000000)
            return addr - 0x710000000
        return addr

    def data_addr_ok(self, va):
        return va_to_off(va) is not None

    # ---- ADDR (local-context routed) ----
    def data_probe(self, a):
        """('reloc',addend) | ('raw',qword) | ('bss',0) | ('zero',0) | ('unmapped',0)"""
        addend = self.relocs.get(a)
        if addend is not None:
            return "reloc", addend
        if va_to_off(a) is None:
            if is_bss(a):
                return "bss", 0
            return "unmapped", 0
        q = read_qword(a)
        if q:
            return "raw", q
        return "zero", 0

    def verify_vptr(self, a, comment):
        if self.asm.is_text(a):
            return "ok", f"addr 0x{a:x} is .text (dispatch-thunk style anchor), present"
        kind, val = self.data_probe(a)
        if kind == "unmapped":
            return "bad", f"vptr 0x{a:x} not mapped in ELF"
        if kind == "bss":
            ok, cells = self.vtable_confirmed(a)
            if ok:
                return "ok", (f"vtable base 0x{a:x} confirmed via reloc cell(s) "
                              f"{', '.join(f'0x{c:x}' for c in cells[:3])}")
            return "bad", f"vptr 0x{a:x}: bss (zero-init), no vtable there"
        if kind == "zero":
            ok, cells = self.vtable_confirmed(a)
            if ok:
                return "ok", (f"vtable base 0x{a:x} confirmed via reloc cell(s) "
                              f"{', '.join(f'0x{c:x}' for c in cells[:3])}")
            return "bad", f"vptr 0x{a:x}: no reloc, zero qword (not a vtable)"
        if kind == "reloc":
            tgt = "text" if val in self.asm.inst_addrs else "data"
            if tgt == "text":
                has_top = self.relocs.get(a - 0x10) is not None
                has_ti = self.relocs.get(a - 0x8) is not None
                if has_top and has_ti:
                    return "ok", f"vptr 0x{a:x}: reloc addend 0x{val:x} (text), vt shape ok"
                return "warn", (f"vptr 0x{a:x}: addend 0x{val:x} (text) but vt shape "
                                f"(-0x10:{has_top} -0x8:{has_ti}) incomplete")
            # pointer-to-vtable cell: addend is data — chain-verify it as vtable base
            st2, msg2 = self.verify_vptr(val, "")
            if st2 in ("ok", "warn"):
                return "ok", f"vptr-table entry 0x{a:x} -> vtable base 0x{val:x} ({msg2})"
            return "bad", f"vptr 0x{a:x}: reloc addend 0x{val:x} is data, not a verifiable vtable"
        # raw file qword
        if val in self.asm.inst_addrs:
            has_top = self.relocs.get(a - 0x10) is not None
            has_ti = self.relocs.get(a - 0x8) is not None
            if has_top and has_ti:
                return "ok", f"vptr 0x{a:x}: qword->text 0x{val:x}, vt shape ok"
            return "warn", f"vptr 0x{a:x}: qword->text 0x{val:x}, vt shape incomplete"
        return "bad", f"vptr 0x{a:x}: qword 0x{val:x} not a .text address, no reloc"

    def verify_cell(self, a, comment):
        if self.asm.is_text(a):
            return "ok", f"addr 0x{a:x} is .text anchor, present"
        kind, val = self.data_probe(a)
        if kind == "unmapped":
            return "bad", f"cell 0x{a:x} not mapped in ELF"
        if kind == "reloc":
            tgt = "text" if val in self.asm.inst_addrs else "data"
            for tok in ADDR_TOKEN_RE.findall(comment):
                if local_subtype(comment, tok) != "vptr":
                    continue
                if int(tok, 16) < MIN_ADDR:
                    continue
                vt = self.norm(int(tok, 16))
                if vt != val and abs(vt - val) > 0x40:
                    return "bad", (f"cell 0x{a:x}: reloc addend 0x{val:x} contradicts "
                                   f"cited vptr 0x{vt:x}")
            return "ok", f"cell 0x{a:x}: RELATIVE reloc addend 0x{val:x} ({tgt})"
        if kind == "bss":
            return "warn", f"cell 0x{a:x}: bss, zero at rest (runtime-filled)"
        if kind == "zero":
            return "warn", f"cell 0x{a:x}: no reloc, zero qword"
        if val in self.asm.inst_addrs:
            return "warn", f"cell 0x{a:x}: no reloc but raw qword ->text 0x{val:x}"
        return "warn", f"cell 0x{a:x}: no reloc, qword 0x{val:x}"

    def verify_data_generic(self, a, what=""):
        kind, val = self.data_probe(a)
        if kind == "reloc":
            return "ok", f"{what}0x{a:x}: reloc addend 0x{val:x}"
        if kind == "raw":
            tgt = "text" if val in self.asm.inst_addrs else "data"
            return "ok", f"{what}0x{a:x}: file qword 0x{val:x} ({tgt})"
        if kind == "bss":
            return "ok", f"{what}0x{a:x}: bss (zero-init)"
        if kind == "zero":
            return "ok", f"{what}0x{a:x}: mapped, zero qword (constant zero)"
        return "bad", f"{what}0x{a:x}: not mapped in ELF"

    def verify_addr_generic(self, av, comment):
        a = self.norm(av)
        if self.asm.is_text(a):
            return "ok", "text addr present in full.asm"
        if a >= 0xb50000 and (va_to_off(a) is not None or is_bss(a)):
            return self.verify_data_generic(a)
        if a < 0x194:
            return "skip", "address below .text start"
        if CONSTANT_RE.search(comment[-80:]):
            return "skip", f"0x{a:x} looks like a constant, not an address"
        return "warn", f"0x{a:x} not found in .text nor mapped data (may be a constant)"

    def verify_ctor(self, addr_val, subtype, comment):
        a = self.norm(addr_val)
        inst_addrs = self.asm.inst_addrs
        if a in inst_addrs:
            return "ok", "text addr present in full.asm"
        # maybe data?
        if va_to_off(a) is not None and a >= 0xb50000:
            return self._verify_data_addr(a, addr_val, subtype, comment)
        # not text, not mapped data
        if a < 0x194:
            return "skip", "address below .text start"
        return "bad", f"addr 0x{a:x} not found in full.asm .text nor mapped in ELF"

    def _verify_data_addr(self, a, orig, subtype, comment):
        if subtype == "vptr":
            q = read_qword(a)
            if q is None:
                return "skip", "vptr: va unreadable"
            if q in self.asm.inst_addrs:
                # vtable shape: relocs at -0x10 (offset-to-top) and -0x8 (typeinfo)
                has_top = self.relocs.get(a - 0x10) is not None
                has_ti = self.relocs.get(a - 0x8) is not None
                if has_top and has_ti:
                    return "ok", f"vptr 0x{a:x}: qword->text 0x{q:x}, vt shape ok (-0x10/-0x8 relocs)"
                return "warn", (f"vptr 0x{a:x}: qword->text 0x{q:x} but vt shape "
                                f"(relocs -0x10:{has_top} -0x8:{has_ti}) incomplete")
            return "bad", f"vptr 0x{a:x}: qword 0x{q:x} not a .text address"
        if subtype == "cell":
            addend = self.relocs.get(a)
            if addend is not None:
                tgt = "text" if addend in self.asm.inst_addrs else "data"
                # contradiction: if the same comment cites a vptr and addend != it
                for tok in ADDR_TOKEN_RE.findall(comment):
                    v = self.norm(int(tok, 16))
                    if v in self.asm.inst_addrs and v != addend and abs(v - addend) > 0x40:
                        return "bad", (f"cell 0x{a:x}: reloc addend 0x{addend:x} contradicts "
                                       f"cited vptr 0x{v:x}")
                return "ok", f"cell 0x{a:x}: RELATIVE reloc addend 0x{addend:x} ({tgt})"
            q = read_qword(a)
            if q == 0:
                return "warn", f"cell 0x{a:x}: no reloc, zero qword"
            if q in self.asm.inst_addrs:
                return "warn", f"cell 0x{a:x}: no reloc but raw qword ->text 0x{q:x}"
            return "warn", f"cell 0x{a:x}: no reloc, qword 0x{q:x}"
        # other/data
        return "ok", f"data addr 0x{a:x} mapped in ELF"

    def verify_ctor(self, addr_val, subtype, comment):
        a = self.norm(addr_val)
        if not self.asm.is_text(a):
            # rodata / data copy source or other data cite
            if a >= 0xb50000 and (va_to_off(a) is not None or is_bss(a)):
                st, msg = self.verify_data_generic(a)
                return st, f"{subtype} cites data: {msg}"
            if CONSTANT_RE.search(comment[-80:]):
                return "skip", f"{subtype}: 0x{a:x} looks like a constant, not an address"
            return "bad", f"{subtype} addr 0x{a:x} not in full.asm .text nor mapped data"
        # cited data cells in the same comment should be touched by the fn
        body = self.asm.body_text(a)
        if body is None:
            return "warn", f"{subtype} 0x{a:x}: no enclosing label"
        cells = []
        for tok in ADDR_TOKEN_RE.findall(comment):
            v = self.norm(int(tok, 16))
            if v >= 0xb50000 and va_to_off(v) is not None:
                cells.append(v)
        if not cells:
            return "ok", f"{subtype} 0x{a:x} present; no data cells cited to cross-check"
        misses = []
        for c in cells:
            page = c & ~0xFFF
            off = c & 0xFFF
            touched = (f"0x{page:x}" in body and
                       re.search(rf"#0x{off:x}\b", body))
            if not touched:
                misses.append(f"0x{c:x}")
        if misses:
            return "warn", f"{subtype} 0x{a:x}: no adrp+add to {','.join(misses)} in body"
        return "ok", f"{subtype} 0x{a:x} touches cited cell(s)"

    # ---- BEHAVIOR ----
    def verify_behavior(self, subtype, comment):
        toks = [self.norm(int(t, 16)) for t in ADDR_TOKEN_RE.findall(comment)]
        text_addrs = [t for t in toks if self.asm.is_text(t)]
        if subtype == "writes-nothing":
            if not text_addrs:
                return "warn", "writes-nothing: no verifiable fn addr in comment"
            body = self.asm.body_text(text_addrs[0])
            if body is None:
                return "warn", "writes-nothing: no enclosing function"
            stores = [l.strip() for l in body.splitlines() if STORE_RE.search(l)]
            if stores:
                return "warn", f"writes-nothing: {len(stores)} store insns in body (check targets)"
            return "ok", "writes-nothing: zero store insns in function body"
        if subtype == "stlr":
            # width claim: instruction at cited addr must be 32-bit (stlr w)
            for t in text_addrs:
                body = self.asm.body_text(t)
                if body is None:
                    continue
                for line in body.splitlines():
                    m = re.match(r"\s*%x:" % t, line)
                    if m:
                        if re.search(r"\bstlr\s+w", line):
                            return "ok", f"stlr w (u32) at 0x{t:x}"
                        if re.search(r"\bstlr\s+x", line):
                            return "bad", f"stlr x (64-bit) at 0x{t:x}, claim says u32"
                        return "warn", f"instruction at 0x{t:x} is not stlr w: {line.strip()[:60]}"
                return "warn", f"stlr: addr 0x{t:x} not in enclosing body slice"
            return "warn", "stlr: no verifiable addr in comment"
        if subtype in ("news", "alloc"):
            if text_addrs:
                return "ok", f"fn addr 0x{text_addrs[0]:x} present"
            return "skip", f"{subtype}: needs judgment"
        if subtype == "sole-caller":
            if not text_addrs:
                return "warn", "sole-caller: no fn addr in comment"
            t = text_addrs[0]
            n = self.asm.bl_counts.get(t, 0)
            if n <= 1:
                return "ok", f"sole-caller: {n} bl to 0x{t:x} in full.asm"
            return "bad", f"sole-caller claim wrong: {n} bl sites to 0x{t:x}"
        return "skip", f"{subtype}: needs judgment"

    # ---- XREF ----
    def verify_xref(self, subtype, token):
        if subtype == "header-ref":
            name = token.replace(".hpp", "")
            for dirpath, _d, files in os.walk(INCLUDE):
                if name + ".hpp" in files:
                    return "ok", f"header {name}.hpp exists"
            return "bad", f"header {name}.hpp not found under include/"
        # explicit-xref / name-mention: identifier must exist in some header
        name = token.split("::")[-1]
        if name in self.idents:
            return "ok", f"name {name} present in headers"
        return "warn", f"name {name} not found in any header"

    # ---- INTERP ----
    def verify_interp(self, subtype, comment):
        toks = [self.norm(int(t, 16)) for t in ADDR_TOKEN_RE.findall(comment)]
        missing = [f"0x{t:x}" for t in toks
                   if not self.asm.is_text(t) and not (t >= 0xb50000 and va_to_off(t) is not None)]
        if missing:
            return "warn", f"INTERP ({subtype}) judgment required; missing anchors: {','.join(missing)}"
        return "warn", f"INTERP ({subtype}) judgment required; cited anchors present"


LOCAL_HINTS = [
    (re.compile(r"\bti\b|typeinfo", re.I), "typeinfo"),
    (re.compile(r"\bbss\b", re.I), "bss"),
    (re.compile(r"rodata|ro data", re.I), "rodata"),
    (re.compile(r"\bcell\b|c[eé]lula|GOT", re.I), "cell"),
    (re.compile(r"vptr|vtable|vt ptr|vtable ptr", re.I), "vptr"),
    (re.compile(r"\bctor\b|constructor|construtor", re.I), "ctor"),
    (re.compile(r"factory|f[aá]brica", re.I), "factory"),
    (re.compile(r"\bsite\b|call site|chamada em|instanti", re.I), "site"),
]
CONSTANT_RE = re.compile(r"\bsets\b|\bpacks\b|\bmask\b|attrFlags|\b==\s|float|\bzeroes\b", re.I)


def local_subtype(comment, token):
    """Re-classify an address using ~50 chars of context before the token."""
    i = comment.find(token)
    if i < 0:
        i = 0
    window = comment[max(0, i - 50):i]
    for rx, sub in LOCAL_HINTS:
        if rx.search(window):
            return sub
    return "other"


def run_verify(db_path):
    v = Verifier()
    conn = sqlite3.connect(db_path)
    conn.execute("UPDATE claims SET status='pending', detail=detail "
                 "WHERE detail NOT LIKE 'VERIFY:%'")
    rows = conn.execute(
        "SELECT id, kind, addr, claim_text, detail, status FROM claims").fetchall()
    counts = Counter()
    for cid, kind, addr, comment, detail, status in rows:
        try:
            if kind == "ADDR":
                av = int(addr, 16)
                sub = local_subtype(comment, addr)
                if sub in ("ctor", "factory", "site"):
                    st, msg = v.verify_ctor(av, sub, comment)
                elif sub in ("typeinfo", "bss", "rodata"):
                    st, msg = v.verify_data_generic(v.norm(av), f"({sub}) ")
                elif sub == "vptr":
                    st, msg = v.verify_vptr(v.norm(av), comment)
                elif sub == "cell":
                    st, msg = v.verify_cell(v.norm(av), comment)
                else:
                    st, msg = v.verify_addr_generic(av, comment)
                if sub in ("ctor", "factory", "site", "vptr", "cell"):
                    msg = f"({sub}) " + msg
            elif kind == "BEHAVIOR":
                st, msg = v.verify_behavior(addr, comment)
            elif kind == "XREF":
                # db: addr col = subtype, detail col = referenced token
                if not detail or not detail[0].isalpha():
                    st, msg = "skip", "xref token is not a name"
                else:
                    st, msg = v.verify_xref(addr, detail)
            elif kind == "INTERP":
                st, msg = v.verify_interp(addr, comment)
            else:
                st, msg = "skip", "unknown kind"
        except Exception as e:  # noqa
            st, msg = "warn", f"verifier error: {e!r}"
        note = f"VERIFY[{st}] {msg}"
        base = detail if detail and not detail.startswith("VERIFY") else ""
        new_detail = (base + "; " + note) if base else note
        conn.execute("UPDATE claims SET status=?, detail=? WHERE id=?",
                     (st, new_detail, cid))
        counts[(kind, st)] += 1
    conn.commit()
    return conn, counts
