#!/usr/bin/env python3
"""Mine ctor store extents from data/main.elf for headers in the
NO_EXTENT_ALLOWLIST.

For each allowlist header with a citable ctor VA, decode the function and
track stores (STR/STUR/STP, unsigned + unscaled imm) whose base register
holds `this` (x0 at entry, propagated through mov xN,x0). The max store end
is a PROVEN LOWER BOUND for the object extent; it is cited as
"ctor stores reach 0xNNN". The real check_extents run validates the result
(fields must fit; gaps must be padded unproven).

Usage: mine_store_extent.py [--apply] [path-filter ...]
  default: dry run, prints per-header verdicts. --apply rewrites docblocks.
"""
import re, sys, struct, json
from pathlib import Path

ELF = Path("/Users/raul/projects/mk8dx-400/data/main.elf")
ROOT = Path(__file__).resolve().parent.parent
HDR = ROOT / "tools" / "check_extents.py"

CTORS = re.compile(
    r"\bctor\b[^.\n]{0,120}?0x([0-9a-fA-F]{5,12})"
    r"|(?:0x[0-9a-fA-F]{5,12})[^.\n]{0,40}\bctor\b", re.I)


def load_elf():
    f = ELF.read_bytes()
    return f, 0x788, 0xB55750


def func_span(f, off, base, maxspan=0x2000):
    """bytes until first ret"""
    for k in range(maxspan // 4):
        i = off + k * 4
        if i + 4 > len(f):
            break
        if struct.unpack_from('<I', f, i)[0] == 0xD65F03C0:
            return k * 4 + 4
    return maxspan


def max_store_end(f, off, base, ln):
    bases = {0}
    best = 0
    for k in range(ln // 4):
        w = struct.unpack_from('<I', f, off + k * 4)[0]
        if (w & 0xFFFFFFE0) == 0xAA0003E0:  # mov xN, x0
            bases.add(w & 31)
        if (w & 0xFFE0FFE0) == 0xAA0003E0:  # mov xN, xM(0)? too broad; keep x0 only
            pass
        top = (w >> 24) & 0xFF
        if top in (0xA9, 0xA8):  # STP 64-bit imm
            imm = (w >> 15) & 0x7F
            if imm >= 64:
                imm -= 128
            rn = (w >> 5) & 31
            if rn in bases:
                best = max(best, imm * 8 + 16)
        if (w >> 21) == 0x3E0:  # STUR
            imm = (w >> 12) & 0x1FF
            if imm >= 256:
                imm -= 512
            sz = {0: 1, 1: 2, 2: 4, 3: 8}[(w >> 30) & 3]
            rn = (w >> 5) & 31
            if rn in bases:
                best = max(best, imm + sz)
        if top == 0x39:  # STR unsigned imm (any size via opc bits 31-30 held in 23-22? use (w>>30)&3)
            imm = (w >> 10) & 0xFFF
            szm = (w >> 30) & 3
            rn = (w >> 5) & 31
            if rn in bases:
                best = max(best, imm * (1 << szm) + (1 << szm))
    return best


def field_end(module, text):
    best = 0
    for seg in module.struct_segments(text):
        for fld in module.parse_fields(seg):
            if fld["size"]:
                best = max(best, fld["off"] + fld["size"])
    return best


def allowlist():
    t = HDR.read_text()
    return re.findall(r"^#   (\S+)$",
                      re.search(r'NO_EXTENT_ALLOWLIST = """\n(.*?)"""', t, re.S).group(1), re.M)


def main():
    apply = "--apply" in sys.argv
    filters = [a for a in sys.argv[1:] if not a.startswith("--")]
    import importlib.util
    spec = importlib.util.spec_from_file_location("ce", HDR)
    ce = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ce)

    f, base, sz = load_elf()
    out = {}
    for rel in allowlist():
        if filters and not any(x in rel for x in filters):
            continue
        text = (ROOT / rel).read_text()
        fe = field_end(ce, text)
        # ctor VAs from docblock
        vas = []
        for m in re.finditer(r"ctor[^0-9a-fA-F\n]{0,12}(?:0x[0-9a-fA-F]{4,}[^.\n]{0,120}?)?0x([0-9a-fA-F]{5,12})", text):
            vas.append(int(m.group(1), 16))
        if not vas:
            for m in re.finditer(r"\b(0x[0-9a-fA-F]{5,12})[^.\n]{0,60}\bctor\b", text, re.I):
                vas.append(int(m.group(1), 16))
        verdicts = []
        for va in vas:
            if va >= 0x7100000000:
                va -= 0x7100000000
            if va < 0x1000 or va >= sz:
                continue
            ln = func_span(f, base + va, base)
            me = max_store_end(f, base + va, base, ln)
            verdicts.append((va, me))
        ok = [me for _, me in verdicts if fe < me <= 0x4000]
        out[rel] = dict(field_end=hex(fe), verdicts=[(hex(a), hex(b)) for a, b in verdicts],
                        chosen=hex(max(ok)) if ok else None)
        if apply and ok:
            me = max(ok)
            va, _ = [v for v in verdicts if v[1] == me][0]
            cite = (f"// extent: ctor stores reach 0x{me:X} (lower bound; "
                    f"allocation end unproven) — ctor 0x{va:X}")
            t2 = text.rstrip("\n") + "\n" + cite + "\n"
            (ROOT / rel).write_text(t2)
        print(f"{rel}: fields_end={fe:#x} " +
              " ".join(f"ctor{a:#x}->{b:#x}" for a, b in verdicts) +
              (f" CHOSEN={max(ok):#x}" if ok else ""))
    json.dump(out, open("/tmp/mine_out.json", "w"), indent=1)


if __name__ == "__main__":
    main()
