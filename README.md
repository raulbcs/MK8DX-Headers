# MK8DX-Headers

All layouts in `include/` target the **Nintendo Switch (aarch64, 64-bit)** binary.

This is a **fork of [fishguy6564/MK8DX-Headers](https://github.com/fishguy6564/MK8DX-Headers)** — all credit for the original headers goes to fishguy and RoGamer97. Thank you for all the work you have put into this.

## Credits

The `vendor/` submodules are the work of the open-ead team — thank you all for everything you have done:

- [open-ead/sead](https://github.com/open-ead/sead) — SEAD (Nintendo's framework), used in `vendor/sead`
- [open-ead/agl](https://github.com/open-ead/agl) — AGL (Nintendo's graphics library), used in `vendor/agl`
- [open-ead/nnheaders](https://github.com/open-ead/nnheaders) — Nintendo SDK headers, used in `vendor/nnheaders`

## CI and pre-push checks

### Syntax CI (`.github/workflows/syntax.yml`)

On every push/PR, GitHub Actions runs `clang++ -fsyntax-only -std=c++17`
over **every** `include/**/*.hpp` (with `submodules: recursive` so the
`vendor/` SDK headers are present). Headers that fail today due to missing
includes are in an explicit allowlist inside the workflow; a failure in any
**non-allowlisted** file breaks CI. Stale allowlist entries (files that now
compile) produce a warning — remove them.

### Extent checker (`tools/check_extents.py`)

Mechanical validation: for every header with a provable class extent in its
docblock, the largest cited field offset must fit within `extent + 0x10`.
Currently advisory (CI step is `continue-on-error`) until the existing
violations are fixed:

```sh
python3 tools/check_extents.py
```

### Pre-push hook (`tools/pre-push-hook.sh`)

Same syntax gate + advisory extent check, run locally before each push.
Install (one-time, pick one):

```sh
git config core.hooksPath tools/hooks
# or
ln -sf ../../tools/pre-push-hook.sh .git/hooks/pre-push
```

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
