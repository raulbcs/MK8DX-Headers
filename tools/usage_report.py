#!/usr/bin/env python3
"""usage_report.py — build the class-usage index for MK8DX-Headers.

Generates (from include/ docblocks + /tmp/full.asm + decomp file_list.yml):
  tools/usage.db        SQLite: classes, anchors, uses
  usage.json            full graph export
  USAGE.md              human-readable usage table
  DECOMP_BRIDGE.md      decomp FUN_* <-> class bridge with rename suggestions

Read-only with respect to the decomp repo; everything is regenerable:

    python3 tools/usage_report.py

Requires: the ELF disassembly at /tmp/full.asm (flat addresses, i.e. text
addresses WITHOUT the 0x7100000000 base; data addresses as-is).
"""

import json
import os
import re
import sqlite3
import sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INCLUDE = os.path.join(ROOT, "include")
DECOMP = os.environ.get("MK8DX_DECOMP", os.path.join(ROOT, "..", "mk8dx-400"))
FULL_ASM = os.environ.get("MK8DX_FULL_ASM", "/tmp/full.asm")
TEXT_BASE = 0x7100000000

ADDR_RE = re.compile(r"0x[0-9a-fA-F]+")


def norm(addr):
    """Normalize an address: text addrs lose the 0x7100000000 base."""
    a = int(addr, 16)
    if a >= TEXT_BASE:
        a -= TEXT_BASE
    return a


# --------------------------------------------------------------------------
# 1. Header parsing
# --------------------------------------------------------------------------

CLASS_RE = re.compile(r"^\s*(?:struct|class)\s+(\w+)", re.M)
VPTR_RE = re.compile(r"vptr\s+0x([0-9a-fA-F]+)")
EXTENT_RE = re.compile(r"(?:extent|total)\s*\(?\s*0x([0-9a-fA-F]+)|\(0x([0-9a-fA-F]+) total")
CTOR_RE = re.compile(r"ctor[s]?(?:\s+pair)?[^.\n]{0,120}?0x([0-9a-fA-F]{7,})")
FACTORY_RE = re.compile(r"factory[^.\n]{0,120}?0x([0-9a-fA-F]{7,})")
CELL_RE = re.compile(r"(?:GOT\s+)?cells?\s+0x([0-9a-fA-F]+)(?:\s*/\s*0x([0-9a-fA-F]+))?")
CONSUMER_RE = re.compile(r"FUN_([0-9a-fA-F]+)")


def docblock_text(path):
    """Concatenate all // comment lines."""
    out = []
    with open(path, encoding="utf-8") as f:
        for line in f:
            s = line.strip()
            if s.startswith("//"):
                out.append(s[2:].strip())
    return "\n".join(out)


def parse_headers():
    classes, anchors, uses = {}, [], []
    for dirpath, _, files in os.walk(INCLUDE):
        for fn in sorted(files):
            if not fn.endswith((".hpp", ".h")):
                continue
            path = os.path.join(dirpath, fn)
            rel = os.path.relpath(path, ROOT)
            text = open(path, encoding="utf-8").read()
            doc = docblock_text(path)
            m = CLASS_RE.search(text)
            if not m or not doc:
                continue
            name = m.group(1)
            vptr = VPTR_RE.search(doc)
            if not vptr:
                continue
            vptr = norm(vptr.group(1))
            ex = EXTENT_RE.search(doc)
            extent = norm("0x" + (ex.group(1) or ex.group(2))) if ex else None
            status = "provisional" if "PROVISIONAL" in doc else "proven"
            classes[vptr] = {
                "vptr": vptr, "name": name, "header": rel,
                "status": status, "extent": extent,
            }
            for a in CTOR_RE.findall(doc):
                anchors.append({"class_vptr": vptr, "kind": "ctor", "addr": norm("0x" + a)})
            for a in FACTORY_RE.findall(doc):
                anchors.append({"class_vptr": vptr, "kind": "factory", "addr": norm("0x" + a)})
            for tup in CELL_RE.findall(doc):
                for a in tup:
                    if a:
                        anchors.append({"class_vptr": vptr, "kind": "cell", "addr": norm("0x" + a)})
            # docblock-cited consumers ("Consumers: FUN_..."), dedup later
            seen = set()
            for line in doc.splitlines():
                if "consumer" in line.lower():
                    for a in CONSUMER_RE.findall(line):
                        addr = norm("0x" + a)
                        if addr not in seen:
                            seen.add(addr)
                            uses.append({
                                "class_vptr": vptr, "consumer_addr": addr,
                                "kind": "references", "evidence": "docblock",
                            })
    return classes, anchors, uses


# --------------------------------------------------------------------------
# 2. Decomp symbol list (file_list.yml, hand-parsed: no pyyaml dependency)
# --------------------------------------------------------------------------

ENTRY_RE = re.compile(
    r"offset:\s*0x([0-9a-fA-F]+)\s*\n\s*size:\s*\d+\s*\n\s*label:\s*(\S+)\s*\n\s*status:\s*(\S+)"
)


def parse_decomp_labels():
    path = os.path.join(DECOMP, "data", "file_list.yml")
    labels = {}
    with open(path, encoding="utf-8") as f:
        data = f.read()
    for off, label, status in ENTRY_RE.findall(data):
        labels[norm("0x" + off)] = (label, status)
    return labels


# --------------------------------------------------------------------------
# 3. Binary analysis over /tmp/full.asm
# --------------------------------------------------------------------------

FUNC_RE = re.compile(r"^([0-9a-f]+) <([^>]+)>:")
BL_RE = re.compile(r"\bbl\s+0x([0-9a-f]+)")
ADRP_RE = re.compile(r"adrp\s+x(\d+),\s+0x([0-9a-f]+)")
ADD_RE = re.compile(r"add\s+x(\d+),\s+x(\d+),\s+#(0x[0-9a-f]+|\d+)")
MEM_RE = re.compile(r"(?:ldr|str)\s+x\d+,\s+\[x(\d+),\s+#(0x[0-9a-f]+|\d+)\]")


def parse_asm(classes, anchors):
    interesting = set(classes)                       # vptr addresses (data)
    interesting |= {a["addr"] for a in anchors if a["kind"] == "cell"}
    anchor_addrs = defaultdict(set)                  # addr -> {(vptr, kind)}
    for a in anchors:
        anchor_addrs[a["addr"]].add((a["class_vptr"], a["kind"]))

    callers = defaultdict(set)                       # callee -> {caller func}
    refs = defaultdict(list)                         # data addr -> [(func, op)]
    cur_func = None
    page = {}                                        # reg -> adrp page

    with open(FULL_ASM, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = FUNC_RE.match(line)
            if m:
                cur_func = int(m.group(1), 16)
                page.clear()
                continue
            if cur_func is None:
                continue
            if " bl\t" in line or "\tbl\t" in line or " bl " in line:
                mb = BL_RE.search(line)
                if mb:
                    callers[int(mb.group(1), 16)].add(cur_func)
                continue
            ma = ADRP_RE.search(line)
            if ma:
                page[int(ma.group(1))] = int(ma.group(2), 16)
                continue
            mm = MEM_RE.search(line)
            if mm:
                base, imm = int(mm.group(1)), int(mm.group(2), 0)
                if base in page:
                    tgt = page[base] + imm
                    if tgt in interesting:
                        refs[tgt].append((cur_func, "mem"))
                page.pop(base, None)
                continue
            mad = ADD_RE.search(line)
            if mad:
                dst, src = int(mad.group(1)), int(mad.group(2))
                if dst == src and src in page:
                    tgt = page[src] + int(mad.group(3), 0)
                    page.pop(src, None)
                    if tgt in interesting:
                        refs[tgt].append((cur_func, "add"))
                    page[dst] = tgt  # resolved addr becomes the new "page"
    return callers, refs, anchor_addrs


# --------------------------------------------------------------------------
# 4. Main
# --------------------------------------------------------------------------

def main():
    classes, anchors, uses = parse_headers()
    labels = parse_decomp_labels()
    print(f"headers parsed: {len(classes)} classes, {len(anchors)} anchors, "
          f"{len(uses)} docblock uses; decomp labels: {len(labels)}")

    callers, refs, anchor_addrs = parse_asm(classes, anchors)
    print(f"binary: {len(callers)} callees with callers, {len(refs)} referenced data addrs")

    def consumer_name(addr):
        if addr in labels:
            return labels[addr][0]
        # real ELF symbol (rare in flat asm, but try callers' known labels)
        return "sub_%x" % addr

    # Build uses rows
    use_rows = []
    for vptr, cls in classes.items():
        for func, op in refs.get(vptr, []):
            if func in anchor_addrs and (vptr, "ctor") in anchor_addrs[func]:
                continue  # class's own ctor storing its vptr
            use_rows.append({
                "class_vptr": vptr, "consumer_addr": func,
                "kind": "holds-pointer" if op == "add" else "reads-cell",
                "evidence": "vptr ref (%s) in full.asm" % op,
            })
    for a in anchors:
        if a["kind"] == "cell":
            for func, op in refs.get(a["addr"], []):
                use_rows.append({
                    "class_vptr": a["class_vptr"], "consumer_addr": func,
                    "kind": "reads-cell" if op == "mem" else "holds-pointer",
                    "evidence": "cell 0x%x ref (%s) in full.asm" % (a["addr"], op),
                })
        else:
            for func in callers.get(a["addr"], []):
                use_rows.append({
                    "class_vptr": a["class_vptr"], "consumer_addr": func,
                    "kind": "instantiates",
                    "evidence": "%s %s 0x%x" % (a["kind"], "call", a["addr"]),
                })
    use_rows += uses

    # dedup
    seen = set()
    dedup = []
    for u in use_rows:
        k = (u["class_vptr"], u["consumer_addr"], u["kind"], u["evidence"])
        if k not in seen:
            seen.add(k)
            u["consumer_name"] = consumer_name(u["consumer_addr"])
            dedup.append(u)
    use_rows = dedup

    # anchor dedup
    aseen, anchor_rows = set(), []
    for a in anchors:
        k = (a["class_vptr"], a["kind"], a["addr"])
        if k not in aseen:
            aseen.add(k)
            anchor_rows.append(a)

    # ---- SQLite ----
    dbpath = os.path.join(ROOT, "tools", "usage.db")
    if os.path.exists(dbpath):
        os.remove(dbpath)
    con = sqlite3.connect(dbpath)
    con.executescript("""
CREATE TABLE classes (
  vptr INTEGER PRIMARY KEY, name TEXT NOT NULL, header TEXT NOT NULL,
  status TEXT NOT NULL, extent INTEGER);
CREATE TABLE anchors (
  class_vptr INTEGER NOT NULL, kind TEXT NOT NULL, addr INTEGER NOT NULL,
  PRIMARY KEY (class_vptr, kind, addr));
CREATE TABLE uses (
  class_vptr INTEGER NOT NULL, consumer_addr INTEGER NOT NULL,
  consumer_name TEXT, kind TEXT NOT NULL, evidence TEXT NOT NULL);
CREATE INDEX idx_uses_class ON uses(class_vptr);
CREATE INDEX idx_uses_consumer ON uses(consumer_addr);
CREATE INDEX idx_uses_kind ON uses(kind);
CREATE INDEX idx_anchors_addr ON anchors(addr);
CREATE INDEX idx_anchors_kind ON anchors(kind);
""")
    con.executemany("INSERT INTO classes VALUES (?,?,?,?,?)",
                    [(c["vptr"], c["name"], c["header"], c["status"], c["extent"])
                     for c in classes.values()])
    con.executemany("INSERT OR IGNORE INTO anchors VALUES (?,?,?)",
                    [(a["class_vptr"], a["kind"], a["addr"]) for a in anchor_rows])
    con.executemany("INSERT INTO uses VALUES (?,?,?,?,?)",
                    [(u["class_vptr"], u["consumer_addr"], u["consumer_name"],
                      u["kind"], u["evidence"]) for u in use_rows])
    con.commit()

    counts = {t: con.execute(f"SELECT count(*) FROM {t}").fetchone()[0]
              for t in ("classes", "anchors", "uses")}
    print("db counts:", counts)

    # ---- usage.json ----
    graph = {
        "classes": [
            {
                **c,
                "anchors": [
                    {"kind": a["kind"], "addr": "0x%x" % a["addr"]}
                    for a in anchor_rows if a["class_vptr"] == c["vptr"]
                ],
                "uses": [
                    {"consumer_addr": "0x%x" % u["consumer_addr"],
                     "consumer_name": u["consumer_name"],
                     "kind": u["kind"], "evidence": u["evidence"]}
                    for u in use_rows if u["class_vptr"] == c["vptr"]
                ],
            }
            for c in sorted(classes.values(), key=lambda c: -len(
                [u for u in use_rows if u["class_vptr"] == c["vptr"]]))
        ]
    }
    with open(os.path.join(ROOT, "usage.json"), "w") as f:
        json.dump(graph, f, indent=1)

    # ---- USAGE.md ----
    uses_by_class = defaultdict(list)
    for u in use_rows:
        uses_by_class[u["class_vptr"]].append(u)
    with_use = [(v, us) for v, us in uses_by_class.items()]
    with_use.sort(key=lambda t: -len(t[1]))
    no_use = [c for v, c in classes.items() if v not in uses_by_class]

    with open(os.path.join(ROOT, "USAGE.md"), "w") as f:
        f.write("# Class usage index\n\n")
        f.write("Generated by `tools/usage_report.py` from header docblocks + "
                "`/tmp/full.asm`. %d vptr-anchored classes (headers without a "
                "docblock vptr — enums, pods, value structs — are out of scope), "
                "%d with at least one known consumer, "
                "%d without.\n\n" % (len(classes), len(with_use), len(no_use)))
        f.write("| Class | Status | Consumers | Evidence |\n|---|---|---|---|\n")
        for v, us in with_use:
            c = classes[v]
            byc = defaultdict(set)
            for u in us:
                byc[u["kind"]].add(u["consumer_name"])
            parts = ["%s x%d" % (k, len(a)) for k, a in
                     sorted(byc.items(), key=lambda t: -len(t[1]))]
            ev = us[0]["evidence"]
            f.write("| [`%s`](%s) | %s | %s | %s |\n" % (
                c["name"], c["header"], c["status"],
                ", ".join(parts)[:200], ev))
        f.write("\n## Classes with no known consumer\n\n")
        f.write("The binary never references the vptr/cell and no ctor/factory "
                "call site was matched (may mean construction through the "
                "factory of a parent, or dead code).\n\n")
        for c in sorted(no_use, key=lambda c: c["name"]):
            f.write("- `%s` (%s, %s)\n" % (c["name"], c["header"], c["status"]))

    # ---- DECOMP_BRIDGE.md ----
    # Rename candidates: anchor functions present in the decomp, grouped by
    # address (a shared ctor legitimately anchors several classes).
    by_addr = {}
    for a in anchor_rows:
        if a["kind"] == "cell":
            continue
        by_addr.setdefault(a["addr"], []).append(a)
    bridge = []
    for addr, alist in by_addr.items():
        lbl = labels.get(addr)
        if not lbl:
            continue
        label, status = lbl
        names = sorted(classes[a["class_vptr"]]["name"] for a in alist)
        kinds = sorted({a["kind"] for a in alist})
        n_uses = max(len(uses_by_class.get(a["class_vptr"], [])) for a in alist)
        shared = " (shared ctor)" if len(names) > 1 else ""
        bridge.append({
            "addr": addr, "label": label, "status": status,
            "cls_names": names, "kind": "+".join(kinds),
            "suggestion": "%s_%s%s" % (names[0], kinds[0], shared),
            "n_uses": n_uses,
        })
    bridge.sort(key=lambda b: (b["status"] != "Matching", -b["n_uses"]))
    ready = [b for b in bridge if b["status"] == "Matching"]
    pct = 100.0 * len(ready) / max(1, len(bridge))
    with open(os.path.join(ROOT, "DECOMP_BRIDGE.md"), "w") as f:
        f.write("# Decomp bridge\n\n")
        f.write("Decomp symbols (from `%s/data/file_list.yml`) crossed by address "
                "with ctor/factory anchors in `tools/usage.db`. "
                "No renames applied — suggestions only.\n\n" % os.path.basename(DECOMP))
        f.write("**Summary: %d rename-ready FUN_* anchors (decompiled, status "
                "Matching), covering %.1f%% of the %d matched anchors.**\n\n"
                % (len(ready), pct, len(bridge)))
        f.write("## Rename-ready (symbol already decompiled)\n\n")
        f.write("| Decomp symbol | Class(es) | Anchor | Suggested name | Uses |\n|---|---|---|---|---|\n")
        for b in ready:
            f.write("| `%s` | %s | %s @ 0x%x | `%s` | %d |\n"
                    % (b["label"], ", ".join("`%s`" % n for n in b["cls_names"]),
                       b["kind"], b["addr"], b["suggestion"], b["n_uses"]))
        f.write("\n## Matched but not yet decompiled\n\n")
        f.write("| Decomp symbol | Status | Class(es) | Anchor | Suggested name |\n|---|---|---|---|---|\n")
        for b in bridge:
            if b["status"] == "Matching":
                continue
            f.write("| `%s` | %s | %s | %s | `%s` |\n"
                    % (b["label"], b["status"],
                       ", ".join("`%s`" % n for n in b["cls_names"]), b["kind"],
                       b["suggestion"]))
        f.write("\n## Consumer-side candidates\n\n")
        f.write("Decompiled functions that instantiate/hold/read a class "
                "(top candidates for `<Class>...` style names):\n\n")
        f.write("| Decomp symbol | Class | Use kind |\n|---|---|---|\n")
        consumer_rows = []
        for u in use_rows:
            lbl = labels.get(u["consumer_addr"])
            if lbl and lbl[1] == "Matching" and u["kind"] != "references":
                consumer_rows.append((lbl[0], u))
        consumer_rows.sort(key=lambda t: t[0])
        for label, u in consumer_rows[:200]:
            f.write("| `%s` | `%s` | %s |\n"
                    % (label, classes[u["class_vptr"]]["name"], u["kind"]))
        if len(consumer_rows) > 200:
            f.write("\n(%d more in usage.json / usage.db)\n" % (len(consumer_rows) - 200))
    print("bridge: %d anchors matched, %d rename-ready (%.1f%%)"
          % (len(bridge), len(ready), pct))

    size = os.path.getsize(dbpath)
    print("usage.db size: %.2f MB" % (size / 1e6))
    con.close()


if __name__ == "__main__":
    sys.exit(main())
