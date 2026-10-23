#!/usr/bin/env python3
"""Session fixer v2: repair headers broken by the 96b05b5 prose sweep.

Per failing file, apply ONLY local mechanical fixes (no fwd decls):
  - ensure file starts with `#pragma once`
  - ensure `#include <cstdint>` when fixed-point types are used/missing
  - insert missing `namespace X {` opener
  - add include of the (unique-stem) header defining an unknown class
Iterates until convergence.
"""
import re
import subprocess
import sys
from pathlib import Path

FLAGS = ["-fsyntax-only", "-std=c++17", "-DNNSDK", "-Iinclude",
         "-Ivendor/sead/include", "-Itools/shims",
         "-Ivendor/nnheaders", "-Ivendor/nnheaders/include"]


def ns_of(p):
    parts = Path(p).parts[1:-1]
    if parts and parts[0] == "_nn":
        parts = ("nn",) + parts[1:]
    return "::".join(parts)


def find_def(name):
    r = subprocess.run(["grep", "-rl", "-E",
                        rf"\b(class|struct) {name}\b", "include"],
                       capture_output=True, text=True)
    hits = [h for h in r.stdout.split() if h]
    if not hits:
        return None
    exact = [h for h in hits if Path(h).stem == name]
    return (exact or sorted(hits, key=lambda h: (h.count("/"), h)))[0]


def fix(path):
    t = Path(path).read_text()
    o = t
    if not t.startswith("#pragma once"):
        t = "#pragma once\n\n" + t
    if "#include <cstdint>" not in t:
        t = t.replace("#pragma once\n",
                      "#pragma once\n\n#include <cstdint>\n", 1)
    closes = len(re.findall(r"^\}  // namespace", t, re.M))
    opens = len(re.findall(r"^namespace ", t, re.M))
    if closes > opens:
        m = re.search(r"^(class|struct) ", t, re.M)
        t = t[:m.start()] + f"namespace {ns_of(path)} {{\n" + t[m.start():]
    if t != o:
        Path(path).write_text(t)
        return True
    return False


def add_includes(path):
    r = subprocess.run(["clang++"] + FLAGS + [path],
                       capture_output=True, text=True)
    if r.returncode == 0:
        return False
    t = Path(path).read_text()
    o = t
    t = re.sub(r"#include <o>\n", "", t)  # undo earlier slicing bug
    names = set(re.findall(r"unknown (?:class name|type name) '(\w+)'",
                           r.stderr))
    # 'expected class name': derive base from `class X : public Base`
    for m in re.finditer(r"^class (\w+)\s*:\s*public (\w+)", t, re.M):
        base = m.group(2)
        if re.search(rf"\b(class|struct) {base}\b", t):
            continue
        if find_def(base):
            names.add(base)
    for name in names:
        if re.search(rf"\b(class|struct|namespace) {name}\b", t):
            continue
        d = find_def(name)
        if d:
            inc = f"#include <{d[len('include/'):]}"
            inc += ">"
            if inc not in t:
                lines = t.split("\n")
                last = max((i for i, l in enumerate(lines)
                            if l.startswith("#include")), default=-1)
                lines.insert(last + 1, inc)
                t = "\n".join(lines)
    if t != o:
        Path(path).write_text(t)
        return True
    return False


def main():
    all_hpp = subprocess.run(["find", "include", "-name", "*.hpp"],
                             capture_output=True, text=True).stdout.split()
    bad = []
    for f in sorted(all_hpp):
        if subprocess.run(["clang++"] + FLAGS + [f],
                          capture_output=True).returncode != 0:
            bad.append(f)
    for it in range(8):
        print(f"== pass {it}: {len(bad)} failing", flush=True)
        if not bad:
            return 0
        nxt = []
        for f in bad:
            fix(f)
            add_includes(f)
            if subprocess.run(["clang++"] + FLAGS + [f],
                              capture_output=True).returncode != 0:
                nxt.append(f)
        if nxt == bad and nxt:
            Path("/tmp/unfixable.txt").write_text("\n".join(nxt))
            print(f"stuck at {len(nxt)}; list in /tmp/unfixable.txt")
            return 1
        bad = nxt
    return 1


if __name__ == "__main__":
    sys.exit(main())
