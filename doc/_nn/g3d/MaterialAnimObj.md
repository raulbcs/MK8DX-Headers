# nn::g3d::MaterialAnimObj

RTTI-confirmed: typeinfo 0x12f18b0 -> mangled
`N2nn3g3d15MaterialAnimObjE` = nn::g3d::MaterialAnimObj. Per-material
texture/pattern animation object; derives from nn::g3d::AnimObj (base
ctor 0xa6edc4, base D1 = shared `ret` stub 0xa6ee6c).

- Vtable: vptr = 0x12f1868. GOT cell 0x130df78 holds 0x12f1858 =
  vptr-0x10; sites do `ldr cell; add #0x10; str [this]`. Row:
  [0x12f1858] = 0 (offset-to-top), [0x12f1860] typeinfo slot ->
  0x12f18b0.
- vptr sites: 0x6a3690 (builder FUN_71006a33c4), 0x6a68c8 (in-place
  init inside FUN_71006a6824), 0x6a6a84 / 0x6a6c40 / 0x6a6dfc /
  0x6a713c (inlined clones in FUN_71006a6ba0 region), 0x6a8570
  (new(0xa0) path in FUN_71006a82fc).
- Size 0xa0: `mov w0, #0xa0; bl 0x60b234` at 0x6a85bc in
  FUN_71006a82fc.

## Member notes

- Slots (9): +0x00 D1 0xa6ee6c (shared `ret` stub), +0x08 D0
  0xa708e0, +0x10 0xa708e4 (4 B override), +0x18 0xa7027c, +0x20
  0xa6fa38 (680 B), +0x28 0xa6ffc4 (36 B), +0x30 0xa6ffe8 (1168 B),
  +0x38 0xa70478 (312 B).
- Base part (+0x00..+0x57) written by base ctor 0xa6edc4; bytes
  +0x30..+0x4f unproven (never stored).

## Construction / init order

1. Base ctor 0xa6edc4(this): AnimObj vptr at +0x00, zeroes
   +0x10/+0x14/+0x18, 1.0f at +0x1c, raw cell 0x1314f58 value at
   +0x20, 0 at +0x28 and +0x50, this+0x10 at +0x08.
2. Derived init overwrites +0x00 with vptr 0x12f1868 and zeroes +0x68.
