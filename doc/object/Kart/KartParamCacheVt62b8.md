# KartParamCacheVt62b8

## Identity

KartParamCacheVt62b8 — address-anchored name (vptr 0x12b62b8). NOT a primary
row: 0x12b62b8 is the SECONDARY interface vtable (13 slots) installed at
[this+0xf0]; the primary vtable is 0x12b6278 (slot row at 0x12b6278, C2/D2
0x6a9230/0x6a937c, own slots 0x6a9518/0x6a96e0/0x6a97bc/0x6a9b78). Both
vptrs come from one cell: 0x130dfa0 holds 0x12b6268; code stores cell+0x10
(0x12b6278) at [this] and cell+0x50 (0x12b62b8) at [this+0xf0] (sites
0x6a8e34/0x6a8e48, 0x6a9240, 0x6a92e4, 0x6a938c, 0x6a9438).

Size 0x5b0 proven at the factory 0x71006a8cc8: allocation via 0x710069ea94
with size 0x5b0 (0x6a8cfc-0x6a8d0c), then C1 0x71006a8ddc, base ctor
0x7100a9ad1c, param copy 0x7100a9ae08, and follow-up sub-allocations stored
to +0x2e0/+0x2e8 (0x6a8d18-0x6a8da4).

## Secondary vtable (row 0x12b62b8)

- slot 0x00 (0x6a92d4) — D1 thunk: adjusts this −0xf0 to the primary base,
  reinstalls both vptrs, destroys members, tail-calls the shared dtor
  0xa9ad8c.
- slot 0x08 (0x6a9428) — D0 thunk (adjust −0xf0, then operator delete
  0x60b470).
- slots 0x10..0x60 — shared interface band: 0x63c6f8 (ret 1), 0x63c700 (ret),
  0x63c704 (ret 1), 0x63c70c (ret), 0x63c710 (paramCacheSharedTypeIdEquals),
  0x63c724/0x63c728 (ret), 0x669208 (agl::Debug::xml loader), 0x66979c,
  0x6697f8 (record-apply pair), 0x63c72c (ret).

## Member notes

Notes in field order; proven from C1 0x71006a8ddc / D2 0x6a9230 unless cited.

- 0x00 — primary vptr 0x12b6278.
- 0xf0 — secondary vptr 0x12b62b8; the dtor path overwrites it with cell
  0x130d848 + 0x10 before finishing (0x6a92b8-0x6a92c0) — unverified which
  vtable 0x130d848 holds.
- 0x2d0 — member destroyed via 0x710060b984 (0x6a9248/0x6a925c).
- 0x2f8 — small member ctor 0x7100629c08 (0x6a92ac-0x6a92b0).
- 0x300 — 0x30-byte block memcpy'd from global [0x12fb188] in the inlined
  construction at 0x6a8e58-0x6a8e68 (that site is a derived inlined variant
  that also zeroes 0x2c0/0x2c8/0x2d0/0x2d8 — unverified whether those writes
  belong to this class or the derived one).
- 0x358 — member ctor 0x710062bf28 (0x6a92a8).
- 0x430 — sub-object vptr from cell 0x130d920 (0x6a929c-0x6a92a4).
- 0x460..0x588 — vptr fan from cell 0x130d918, ten slots (0x6a926c-0x6a9294).

> Naming: address-anchored; no ctor strings (single rodata name 0xefe5d2
> passed to the base ctor at 0x6a8e20).

## Construction / init order

- Factory 0x71006a8cc8 (called from 0x710069fa78, result stored to
  [mgr+0xe8]): alloc 0x5b0 (0x6a8cfc), C1 0x71006a8ddc (0x6a8d18), param copy
  0x7100a9ae08 (0x6a8d28), +0x2d0 init with param id (0x6a8d2c-0x6a8d3c),
  sub-allocations stored to +0x2e0/+0x2e8 with ctors 0x71006b5cf0/0x71006b5d88
  and 0x71006b3678/0x71006b370c (0x6a8d40-0x6a8d94), +0x2f0 = 0, flag |= 1 at
  +0x8 (0x6a8d98-0x6a8da4).
- C1 0x71006a8ddc field order: base 0x7100a9ad1c, name 0xefe5d2, both vptrs
  (0x6a8e34-0x6a8e50), zeros, 0x300 block copy.
- D2 0x6a9230 (primary slot 0): reinstalls both vptrs, destroys 0x2d0,
  rebuilds the 0x460 fan and 0x430 sub-object, swaps 0xf0 to cell 0x130d848,
  tail-calls 0xa9ad8c.
