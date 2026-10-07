# tools/shims

Minimal forward-declaration / declaration-only headers for dependencies that
are not vendored in this repo. Shims exist ONLY so `clang -fsyntax-only`
passes with honest semantics (right namespace, right class/method names);
they are never included by the game itself and must never define layout
(fields, offsets, sizes) that `tools/check_extents.py` would trust.

Current content: none. The previously-missing deps are covered by:

- `vendor/sead` (open-ead/sead submodule), on the include path with `-DNNSDK`
- `include/xlink2/TriggerType.hpp` and `include/xlink2/ResTriggerOverwriteParam.hpp`
  (minimal in-repo headers, added 2026-10-07)

If a future header needs a missing external type, add a shim here using the
same directory layout as the expected include path (e.g.
`tools/shims/math/seadQuat.hpp`) and add `-Itools/shims` consumers via the
CI workflow (`-I` already present).
