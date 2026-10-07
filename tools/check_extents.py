#!/usr/bin/env python3
"""Mechanical extent checker for MK8DX-Headers.

For every .hpp under include/:
  1. Extract the largest field offset cited in the header (trailing
     `//0xNNN` / `// 0xNNN` offset comments, `pad_XXX` array names, and
     "extent fixed by <field> at 0xNNN" citations).
  2. Extract the class extent proven in the docblock, from patterns such as
     "extent ... 0xNNN", "allocation proof ... size 0xNNN", "concrete size
     0xNNN", "size 0xNNN (allocation site ...)", "factory news[0xNNN]".
  3. Validate: max_offset <= extent + 0x10 alignment slack.

Headers with no provable extent ("extent unknown", "extent >= 0xNNN" lower
bounds only, no docblock citation) are SKIPPED, not flagged.

sizeof(field type) is not derived (would require compiling each header);
the fixed 0x10 slack covers small trailing fields. Known limitation.

Exit codes: 0 = no violations, 1 = violations found (printed as
header/offset/extent lines).
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE = ROOT / "include"

# Hex constants below this threshold are treated as struct offsets.
# Larger values are binary addresses (ctors, vtables, GOT cells) and are
# ignored as offset candidates.
OFFSET_LIMIT = 0x10000
# Alignment slack: extent may exceed last field start by up to this much
# (last field size + struct alignment).
SLACK = 0x10

OFFSET_COMMENT = re.compile(r"//\s*[-—]?\s*0x([0-9a-fA-F]{1,5})\b")
PAD_NAME = re.compile(r"\bpad[_]?0*([0-9a-fA-F]{1,5})\b")
FIXED_BY = re.compile(r"fixed by\s+\S+\s+at\s+0x([0-9a-fA-F]+)\b", re.I)
# Offset comments on virtual-declaration lines are VTABLE SLOT offsets
# (//0xb8 — exit() tail call), not field offsets. Never count them.
VIRTUAL_DECL = re.compile(r"\bvirtual\b")

EXTENT_PATTERNS = [
    re.compile(r"extent\s+(?:is\s+|from\s+|of\s+|=|fixed by\s+\S+\s+at)?0x([0-9a-fA-F]+)", re.I),
    re.compile(r"concrete size\s+0x([0-9a-fA-F]+)", re.I),
    re.compile(r"news\[0x([0-9a-fA-F]+)\]", re.I),
    re.compile(r"allocation[^.]*?size\s+0x([0-9a-fA-F]+)", re.I),
    re.compile(r"\bsize\s+0x([0-9a-fA-F]+)\s*\(", re.I),  # "size 0x2B0 (allocation site ...)"
]

STRICT_EXTENT_NEG = re.compile(r"extent\s*(unknown|>=)", re.I)
# Extent citations that describe a MEMBER/BASE sub-object, not the class
# itself ("sub-object (ctor ..., extent 0x40, to 0x250)",
# "... base region ..., extent 0xa0"). These are not class extents.
SUBOBJECT_LINE = re.compile(r"sub-?object|base region", re.I)
# "extent 0x68, to 0x80" — describes where a sub-object ENDS, not the class
# extent (e.g. docblock field maps of embedded ctor sub-objects).
SUBOBJECT_TO = re.compile(r"extent\s+0x[0-9a-fA-F]+,?\s+to\s", re.I)


def h(s):
    return int(s, 16)


def analyze(path: Path):
    text = path.read_text(errors="replace")
    max_off = 0
    for line in text.splitlines():
        if VIRTUAL_DECL.search(line):
            continue  # vtable slot offsets, not field offsets
        for m in OFFSET_COMMENT.finditer(line):
            v = h(m.group(1))
            if v < OFFSET_LIMIT:
                max_off = max(max_off, v)
    for m in PAD_NAME.finditer(text):
        start = h(m.group(1))
        if start < OFFSET_LIMIT:
            max_off = max(max_off, start)
    for m in FIXED_BY.finditer(text):
        v = h(m.group(1))
        if v < OFFSET_LIMIT:
            max_off = max(max_off, v)

    extents = []
    has_strict_citation = False
    for m in STRICT_EXTENT_NEG.finditer(text):
        if m.group(1).lower() == "unknown":
            continue  # no extent at all
        # "extent >= 0xNNN" is a lower bound; the 0xNNN still counts as a
        # candidate extent (last field must fit inside the proven minimum).
        pass
    for pat in EXTENT_PATTERNS:
        for m in pat.finditer(text):
            ls = text.rfind("\n", 0, m.start()) + 1
            le = text.find("\n", m.start())
            line = text[ls:le if le != -1 else len(text)]
            if SUBOBJECT_LINE.search(line) or SUBOBJECT_TO.search(line):
                continue  # sub-object extent, not the class extent
            v = h(m.group(1))
            if 0 < v < OFFSET_LIMIT:
                extents.append(v)
                has_strict_citation = True
    # "extent >= 0xNNN" is only a proven lower bound: it cannot validate
    # that fields fit, so the header is skipped rather than flagged.
    return max_off, extents, has_strict_citation


def main():
    violations = []
    checked = skipped = 0
    per_dir = {}
    for path in sorted(INCLUDE.rglob("*.hpp")):
        max_off, extents, has_strict = analyze(path)
        if not has_strict or not extents:
            skipped += 1
            continue
        checked += 1
        extent = max(extents)
        if max_off > extent + SLACK:
            rel = path.relative_to(ROOT)
            violations.append((str(rel), max_off, extent))
            d = str(path.parent.relative_to(INCLUDE))
            per_dir[d] = per_dir.get(d, 0) + 1

    print(f"checked {checked} headers with a provable extent "
          f"({skipped} skipped: no strict extent citation)")
    if violations:
        print(f"\nVIOLATIONS: {len(violations)} "
              f"(max cited offset > extent + 0x{SLACK:X})\n")
        for rel, off, ext in violations:
            print(f"  {rel}: max offset 0x{off:X} > extent 0x{ext:X} + 0x10")
        print("\nViolations by directory:")
        for d, n in sorted(per_dir.items(), key=lambda kv: -kv[1]):
            print(f"  {d}: {n}")
        sys.exit(1)
    print("all extents OK")


if __name__ == "__main__":
    main()
