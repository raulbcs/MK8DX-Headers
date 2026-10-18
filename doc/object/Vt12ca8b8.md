# object::Vt12ca8b8

PLACEHOLDER name (identity not proven). vptr 0x12ca8b8, 10 slots, typeinfo NULL (game-side).
GOT cell 0x1310518 holds 0x12ca8a8 (vtable row − 0x10); the installed vptr equals the row start
0x12ca8b8. Row header words at −0x10/−0x8 are both 0.

## Member notes

- size 0x170, proven by `operator new(0x170)` at 0x8059a8 / 0x805d24 (and 0x80516c path) inside
  FUN_71008054c8 immediately before the vptr store.
- No dedicated C1 located: base-ctor 0x8dc2b0(this, x1=[0x12fb0148], s0=1.0f) runs first
  (0x8059c4 / 0x805d40 / 0x805190), then the factory overrides the vptr with 0x12ca8b8
  (0x8059e8 / 0x805d60 / 0x8051ac→tail 0x805d5c). Derived field init is inlined/inside 0x8dc2b0
  and was not mapped — interior layout unverified.
- Always stored at +0x10 of a 0x38 wrapper object created by the same factory (wrapper vtable is a
  neighboring table via GOT cell 0x13104e0/0x1310508, not documented here).
- Slot 0 (0x7d4d44) is shared verbatim with Vt12ca918 — linker-folded shared stub or identical
  D1; slots 1–3 point inside FUN_7100807968 (functions.csv merges several small thunks there).

Slot table (all `U` quality in functions.csv unless noted):
0x00 0x7d4d44, 0x08 0x807a34, 0x10 0x807a58, 0x18 0x807a98, 0x20 0x7d513c, 0x28 0x7d5144,
0x30 0x8dce3c, 0x38 0x7d514c, 0x40 0x807ad8, 0x48 0x7d515c.

## Construction / init order

- Creation sites (all in FUN_71008054c8, an 11-way `[x1]`-indexed factory that appends each 0x38
  wrapper to an array at [x19+0x10], count [x19+0x8]):
  0x8051a8 → tail 0x805458, 0x8059e0 (case alloc 0x170 at 0x8059a8), 0x805d58 (case alloc 0x170
  at 0x805d24). Order: new(0x38) wrapper → new(0x88) inner (base-ctor 0x7ceeb4, tier arg 7) →
  new(0x170) this → 0x8dc2b0 → vptr override 0x12ca8b8.
- Second parallel factory FUN_7100804db0 builds the same wrapper/inner/member shape with sibling
  vtables (Vt12ca918 among them); it never installs 0x12ca8b8.
