# nn::g3d::SkeletalAnimObj

RTTI-confirmed: typeinfo 0x12f1a40 -> mangled
`N2nn3g3d15SkeletalAnimObjE` = nn::g3d::SkeletalAnimObj. Skeleton
animation object; derives from nn::g3d::AnimObj (base ctor 0xa6edc4,
base D1 = shared `ret` stub 0xa6ee6c).

- Vtable: vptr = 0x12f19f8. GOT cell 0x130df70 holds 0x12f19e8 =
  vptr-0x10; sites do `ldr cell; add #0x10; str [this]`. Row:
  [0x12f19e8] = 0 (offset-to-top), [0x12f19f0] typeinfo slot ->
  0x12f1a40.
- vptr sites: 0x6a3284 (element ctor loop in FUN_71006a2c24 - array
  elements of stride 0xa8, base ctor called at element+0x20), 0x6a83a0
  (new(0x88) path in FUN_71006a82fc).
- Size 0x88: `mov w0, #0x88; bl 0x60b234` at 0x6a83f8 in
  FUN_71006a82fc. (The 0xa8 array stride covers a 0x20-byte prefix
  before the object in the FUN_71006a2c24 layout.)

## Member notes

- Slots (9): +0x00 D1 0xa6ee6c (shared `ret` stub), +0x08 D0
  0xa78fa0, +0x10 0xa77554 (100 B), +0x18 0xa7763c (148 B), +0x20
  0xa76e88, +0x28 0xa76ed8 (84 B), +0x30 0xa7749c, +0x38 0xa776a8.
- Base part (+0x00..+0x57) written by base ctor 0xa6edc4; bytes
  +0x30..+0x4f unproven (never stored).

## Construction / init order

1. Base ctor 0xa6edc4(this): AnimObj vptr at +0x00, zeroes
   +0x10/+0x14/+0x18, 1.0f at +0x1c, raw cell 0x1314f58 value at
   +0x20, 0 at +0x28 and +0x50, this+0x10 at +0x08.
2. Derived init overwrites +0x00 with vptr 0x12f19f8 and zeroes +0x68
   and +0x80.
