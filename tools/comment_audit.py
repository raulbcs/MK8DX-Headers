#!/usr/bin/env python3
"""comment_audit.py — extract auditable claims from comments in include/ headers.

Populates tools/claims.db (SQLite). Every claim gets status='pending'.
This tool EXTRACTS ONLY — no verification.

Claim kinds:
  ADDR     hex addresses cited in comments (vptr/cell/ctor/factory/site/other)
  BEHAVIOR behavioral claims ("writes nothing", "sole caller", "stlr w", ...)
  XREF     cross-references to other classes/headers
  INTERP   interpretation markers ("likely", "probably", "identity is", ...)

Usage: python3 tools/comment_audit.py            # (re)build claims.db
       python3 tools/comment_audit.py --summary  # print counts, no rebuild
"""

import argparse
import os
import re
import sqlite3
import sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INCLUDE = os.path.join(ROOT, "include")
DB_PATH = os.path.join(ROOT, "tools", "claims.db")

# Hex token that is plausibly an address (not a tiny field offset like 0xE0).
MIN_ADDR = 0x10000

ADDR_RE = re.compile(r"0x[0-9a-fA-F]+")
WORD_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")

# ---- BEHAVIOR patterns (regex, each -> subtype label) -----------------------
BEHAVIOR_PATTERNS = [
    (re.compile(r"writes? nothing|n[aã]o escreve|only zeroes|zer[aó]"), "writes-nothing"),
    (re.compile(r"sole (caller|consumer|user)|[uú]nico (chamador|consumidor|usu[aá]rio)"), "sole-caller"),
    (re.compile(r"\bstlr\b|\bstlrb\b|\bstlrh\b|stlr w"), "stlr"),
    (re.compile(r"news?\s+0x[0-9a-fA-F]+"), "news"),
    (re.compile(r"alloc\w*\s+0x[0-9a-fA-F]+"), "alloc"),
    (re.compile(r"never instantiated|nunca instanciad|no (direct )?instantiation"), "never-instantiated"),
    (re.compile(r"no method-tree|method[- ]tree"), "method-tree"),
]

# ---- INTERP patterns --------------------------------------------------------
INTERP_PATTERNS = [
    (re.compile(r"\blikely\b|provavelmente"), "likely"),
    (re.compile(r"\bprobably\b"), "probably"),
    (re.compile(r"identity is|identidade [ée]"), "identity"),
    (re.compile(r"no binary name|sem nome no bin[aá]rio|unnamed in binary"), "no-binary-name"),
    (re.compile(r"\bguess|palpite|speculative|conjecture|hip[oó]tese|assum(e|ed|ing)\b|presumably"), "hedge"),
]

# Subtype classification for ADDR claims, by phrase context.
ADDR_SUBTYPE_HINTS = [
    (re.compile(r"vptr|vtable ptr|vt ptr"), "vptr"),
    (re.compile(r"\bcell\b|c[eé]lula"), "cell"),
    (re.compile(r"\bctor\b|constructor|construtor|c[123]\b"), "ctor"),
    (re.compile(r"factory|f[aá]brica"), "factory"),
    (re.compile(r"\bsite\b|call site|chamada em|instanti"), "site"),
]

COMMENT_BLOCK_RE = re.compile(r"/\*.*?\*/", re.S)
LINE_COMMENT_RE = re.compile(r"//[^\n]*")
STRING_RE = re.compile(r'"(?:\\.|[^"\\])*"')


def strip_strings(text: str) -> str:
    return STRING_RE.sub('""', text)


def iter_comments(text: str):
    """Yield (line_no, comment_text) for // and /* */ comments."""
    # Mask strings so comment markers inside literals are ignored.
    masked = strip_strings(text)
    spans = []
    for m in COMMENT_BLOCK_RE.finditer(masked):
        spans.append(m)
    for m in LINE_COMMENT_RE.finditer(masked):
        if any(s.start() <= m.start() < s.end() for s in spans):
            continue
        spans.append(m)
    for m in spans:
        start_line = masked.count("\n", 0, m.start()) + 1
        yield start_line, m.group(0)


def classify_addr(addr_val: int, ctx: str) -> str:
    for rx, sub in ADDR_SUBTYPE_HINTS:
        if rx.search(ctx):
            return sub
    if addr_val >= 0x7100000000:
        return "site"  # flat .text runtime address
    return "other"


def addr_class(addr_val: int) -> str:
    """Top-level address class for the detail column."""
    if addr_val >= 0x7100000000:
        return "flat-text"
    if addr_val >= 0x1000000:
        return "data-vptr-cell"
    return "flat-text"


def extract_from_header(rel: str, text: str):
    claims = []
    for line_no, comment in iter_comments(text):
        ctx = comment

        # ADDR claims: one per address token.
        for m in ADDR_RE.finditer(comment):
            val = int(m.group(0), 16)
            if val < MIN_ADDR:
                continue  # field offset or small constant, not an address claim
            sub = classify_addr(val, ctx)
            detail = addr_class(val)
            claims.append(("ADDR", m.group(0), sub, comment.strip(), detail))

        # BEHAVIOR claims.
        for rx, sub in BEHAVIOR_PATTERNS:
            if rx.search(ctx):
                claims.append(("BEHAVIOR", rx.pattern[:40], sub, comment.strip(), ""))

        # INTERP claims.
        for rx, sub in INTERP_PATTERNS:
            if rx.search(ctx):
                claims.append(("INTERP", rx.pattern[:40], sub, comment.strip(), ""))

        # XREF claims: "derives from X", "same ctor as X", "see X.hpp",
        # "wired like X", and any Mention of Other PascalCase names.
        xref_started = False
        for m in re.finditer(
            r"(?:derives? from|same ctor as|see|wired like|like|same as|equivalent to|"
            r"corresponds to|match(?:es)?|cf\.)\s+([A-Za-z_][\w:./]*)",
            ctx,
        ):
            claims.append(("XREF", m.group(0)[:60], "explicit-xref", comment.strip(), m.group(1)))
            xref_started = True
        # Header file references and PascalCase class mentions.
        for m in re.finditer(r"\b([A-Z][A-Za-z0-9_]{2,}(?:\.hpp)?)\b", ctx):
            tok = m.group(1)
            if tok.endswith(".hpp"):
                claims.append(("XREF", tok, "header-ref", comment.strip(), tok))
            elif not xref_started and not tok.startswith("Vt"):
                # standalone class-name mention — only if not already captured
                claims.append(("XREF", tok, "name-mention", comment.strip(), tok))
    return claims


def build_db():
    if os.path.exists(DB_PATH):
        os.remove(DB_PATH)
    conn = sqlite3.connect(DB_PATH)
    conn.execute(
        """CREATE TABLE claims(
               id INTEGER PRIMARY KEY,
               header TEXT NOT NULL,
               line INTEGER NOT NULL,
               kind TEXT NOT NULL,
               claim_text TEXT NOT NULL,
               addr TEXT,
               status TEXT NOT NULL DEFAULT 'pending',
               detail TEXT NOT NULL DEFAULT ''
           )"""
    )
    conn.execute("CREATE INDEX idx_claims_kind ON claims(kind)")
    conn.execute("CREATE INDEX idx_claims_status ON claims(status)")
    conn.execute("CREATE INDEX idx_claims_header ON claims(header)")

    headers = []
    for dirpath, _dirs, files in os.walk(INCLUDE):
        for f in sorted(files):
            if f.endswith(".hpp"):
                headers.append(os.path.join(dirpath, f))
    headers.sort()

    n = 0
    for path in headers:
        rel = os.path.relpath(path, ROOT)
        with open(path, encoding="utf-8", errors="replace") as fh:
            text = fh.read()
        rows = []
        for kind, addr, sub, comment, detail in extract_from_header(rel, text):
            if kind == "ADDR":
                claim_text, addr_col, detail_col = comment, addr, f"{sub}|{detail}"
            else:
                claim_text, addr_col, detail_col = comment, sub, detail
            rows.append((rel, _find_line(text, comment), kind, claim_text, addr_col,
                         "pending", detail_col))
        conn.executemany(
            "INSERT INTO claims(header,line,kind,claim_text,addr,status,detail) "
            "VALUES (?,?,?,?,?,?,?)",
            rows,
        )
        n += 1
    conn.commit()
    return conn, n, headers


_line_cache = {}


def _find_line(text: str, comment: str) -> int:
    key = id(text)
    if key not in _line_cache:
        # Build index of first occurrence line for each distinct comment string
        _line_cache[key] = {}
        cache = _line_cache[key]
        for line_no, c in iter_comments(text):
            cache.setdefault(c, line_no)
    return _line_cache[key].get(comment, 0)


def summary(conn):
    print("== by kind ==")
    for row in conn.execute("SELECT kind, COUNT(*) FROM claims GROUP BY kind ORDER BY 2 DESC"):
        print(f"  {row[0]:10s} {row[1]}")
    print("== ADDR subtypes (detail col: subtype|class) ==")
    for row in conn.execute(
        "SELECT detail, COUNT(*) FROM claims WHERE kind='ADDR' GROUP BY detail ORDER BY 2 DESC"
    ):
        print(f"  {row[0]:28s} {row[1]}")
    print("== BEHAVIOR subtypes (addr col) ==")
    for row in conn.execute(
        "SELECT addr, COUNT(*) FROM claims WHERE kind='BEHAVIOR' GROUP BY addr ORDER BY 2 DESC"
    ):
        print(f"  {row[0]:24s} {row[1]}")
    print("== INTERP subtypes (addr col) ==")
    for row in conn.execute(
        "SELECT addr, COUNT(*) FROM claims WHERE kind='INTERP' GROUP BY addr ORDER BY 2 DESC"
    ):
        print(f"  {row[0]:24s} {row[1]}")
    print("== XREF subtypes (addr col) ==")
    for row in conn.execute(
        "SELECT addr, COUNT(*) FROM claims WHERE kind='XREF' GROUP BY addr ORDER BY 2 DESC"
    ):
        print(f"  {row[0]:24s} {row[1]}")
    total = conn.execute("SELECT COUNT(*) FROM claims").fetchone()[0]
    headers = conn.execute("SELECT COUNT(DISTINCT header) FROM claims").fetchone()[0]
    print(f"== total: {total} claims across {headers} headers ==")


def write_report(out_path):
    conn = sqlite3.connect(DB_PATH)
    lines = ["# COMMENT_AUDIT — mechanical verification of docblock claims",
             "",
             "Generated by `tools/comment_audit.py` (`--verify` + `--report`).",
             "Sources: `/tmp/full.asm`, ELF phdrs + `.data` of `main.elf`, `llvm-objdump -R` relocs.",
             "", "## Totals by kind/status", "",
             "| kind | ok | bad | warn | skip | total |",
             "|---|---|---|---|---|---|"]
    kinds = [r[0] for r in conn.execute(
        "SELECT DISTINCT kind FROM claims ORDER BY kind")]
    for k in kinds:
        c = {s: conn.execute("SELECT COUNT(*) FROM claims WHERE kind=? AND status=?",
                             (k, s)).fetchone()[0] for s in ("ok", "bad", "warn", "skip")}
        t = conn.execute("SELECT COUNT(*) FROM claims WHERE kind=?", (k,)).fetchone()[0]
        lines.append(f"| {k} | {c['ok']} | {c['bad']} | {c['warn']} | {c['skip']} | {t} |")
    lines += ["", "## bad / warn / skip claims", ""]
    for st in ("bad", "warn", "skip"):
        rows = conn.execute(
            "SELECT header,line,kind,addr,substr(detail,instr(detail,'VERIFY[')) "
            "FROM claims WHERE status=? ORDER BY kind,header,line", (st,)).fetchall()
        lines += [f"### {st} ({len(rows)})", ""]
        for h, ln, k, addr, det in rows:
            lines.append(f"- `{h}:{ln}` ({k} `{addr}`) {det}")
        lines.append("")
    with open(out_path, "w") as f:
        f.write("\n".join(lines))
    print(f"report written: {out_path}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--summary", action="store_true", help="print counts only")
    ap.add_argument("--verify", action="store_true",
                    help="mechanically verify claims in claims.db (needs /tmp/full.asm + main.elf)")
    ap.add_argument("--report", metavar="OUT", help="write COMMENT_AUDIT.md-style report from claims.db")
    args = ap.parse_args()

    if args.report:
        write_report(args.report)
        return 0

    if args.verify:
        from verify_claims import run_verify
        db = DB_PATH if os.path.exists(DB_PATH) else None
        if db is None:
            print("claims.db missing; run without --verify first", file=sys.stderr)
            return 1
        conn, counts = run_verify(db)
        print("== verify results by kind/status ==")
        for kind in ("ADDR", "BEHAVIOR", "XREF", "INTERP"):
            row = "  ".join(f"{st}={counts.get((kind, st), 0)}"
                             for st in ("ok", "bad", "warn", "skip"))
            print(f"  {kind:10s} {row}")
        return 0

    if args.summary and os.path.exists(DB_PATH):
        conn = sqlite3.connect(DB_PATH)
        summary(conn)
        return 0

    conn, n, headers = build_db()
    print(f"scanned {n} headers from include/ (vendor not present under include/)")
    summary(conn)
    size = os.path.getsize(DB_PATH)
    print(f"db: {DB_PATH} ({size/1024:.0f} KB)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
