# MK8DX-Headers

All layouts in `include/` target the **Nintendo Switch (aarch64, 64-bit)** binary.

This is a **fork of [fishguy6564/MK8DX-Headers](https://github.com/fishguy6564/MK8DX-Headers)** — all credit for the original headers goes to fishguy and RoGamer97. Thank you for all the work you have put into this.

## Credits

The `vendor/` submodules are the work of the open-ead team — thank you all for everything you have done:

- [open-ead/sead](https://github.com/open-ead/sead) — SEAD (Nintendo's framework), used in `vendor/sead`
- [open-ead/agl](https://github.com/open-ead/agl) — AGL (Nintendo's graphics library), used in `vendor/agl`
- [open-ead/nnheaders](https://github.com/open-ead/nnheaders) — Nintendo SDK headers, used in `vendor/nnheaders`

## CI and pre-push checks

### Syntax workflow (`.github/workflows/syntax.yml`)

The workflow is **`workflow_dispatch`-only**: it never runs automatically on
GitHub. Run it locally with [act](https://github.com/nektos/act):

```sh
act workflow_dispatch --container-architecture linux/amd64 \
  -P ubuntu-latest=catthehacker/ubuntu:act-latest
```

It runs `clang++ -fsyntax-only -std=c++17` over **every** `include/**/*.hpp`
(with `submodules: recursive` so the `vendor/` SDK headers are present).
Headers that fail today due to missing includes are in an explicit allowlist
inside the workflow; a failure in any **non-allowlisted** file breaks the run.
Stale allowlist entries (files that now compile) produce a warning — remove
them.

### Layout/extent linter (`tools/check_extents.py`) — BLOCKING

Mechanical layout validation, run by both the workflow and the pre-push hook
as a **blocking** step (violations fail the check):

- field overlap detection, byte-by-byte,
- coverage: every cited offset covered by a field or an annotated pad,
- pads must carry an `unproven padding/gap` note,
- every header with fields needs a cited extent (small embedded allowlist),
- alignment advisory warnings (non-blocking).

```sh
python3 tools/check_extents.py
```

### Coverage report (`tools/coverage_report.py`)

Generates a local `COVERAGE.md`/`coverage.html` summary (gitignored) of which
headers have proven extents, field maps, and vtable anchors. Regenerate with:

```sh
python3 tools/coverage_report.py
```

### Pre-push hook (`tools/pre-push-hook.sh`)

Same syntax gate + blocking layout/extent check, run locally before each
push. Install (one-time):

```sh
git config core.hooksPath tools/hooks
```

`tools/hooks/pre-push` is a committed symlink to `../pre-push-hook.sh`.
The hook expects `clang++` on PATH and the `vendor/nnheaders` submodule
checked out (`git submodule update --init vendor/nnheaders`).

## Legal

This project is not affiliated with, endorsed by, or sponsored by Nintendo.
Mario Kart 8 Deluxe, Nintendo, and the Nintendo Switch are trademarks of
Nintendo Co., Ltd. All game assets, code, and related intellectual property
remain the property of Nintendo.

The headers here are reverse-engineered interface declarations provided for
research and interoperability purposes only. No original Nintendo code, assets,
or data are included or distributed.

I love this game. This is a fan-made modding project, made out of passion and
curiosity about how the game works — not for profit. Nothing here is monetized
in any way.
