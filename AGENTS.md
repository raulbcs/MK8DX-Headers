# MK8DX-Headers

## Commits

Follow https://cbea.ms/git-commit/ (the 7 rules):

1. Subject: single line, **≤ 50 chars** (up to ~72 allowed when the area prefix demands it, as in prior commits), no trailing period
2. Subject in imperative mood ("Document quant channel offsets")
3. Body (if needed): wrap at 72 chars; include evidence (instruction/reloc addresses)
4. Blank line between subject and body
5. Area prefix first: `Recorder:`, `Director:`, etc.

## Misc

- Headers never add compilable code — docblocks and mirrored structs only
- Address facts enter a header only if verified against .rela.dyn/disassembly (cite them in the commit body)
