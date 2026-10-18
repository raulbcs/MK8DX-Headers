# nn::g3d::BoneVisibilityAnimObj

RTTI-confirmed: typeinfo 0x12f1840 -> mangled
`N2nn3g3d21BoneVisibilityAnimObjE` = nn::g3d::BoneVisibilityAnimObj.
Per-bone visibility animation object; derives from nn::g3d::AnimObj
(shared base typeinfo record; base ctor 0xa6edc4, base D1 = shared
`ret` stub 0xa6ee6c).

- Vtable: vptr = 0x12f17d8. GOT cell 0x130df88 holds 0x12f17c8 =
  vptr-0x10; sites do `ldr cell; add #0x10; str [this]`. Row:
  [0x12f17c8] = 0 (offset-to-top), [0x12f17d0] typeinfo slot ->
  0x12f1840.
- vptr sites: 0x6a6fb4 (in-place init inside FUN_71006a6f14, object
  placed at [x23+8]+[x20+0xa4]), 0x6a875c (new(0x80) path in
  FUN_71006a82fc).
- Size 0x80: `orr w0, wzr, #0x80; bl 0x60b234` at 0x6a879c/0x6a87ac in
  FUN_71006a82fc.

## Member notes

- Slots (9): +0x00 D1 0xa6ee6c (shared `ret` stub), +0x08 D0
  0xa6f69c, +0x10 0xa6f354 (36 B), +0x18 0xa6f454, +0x20 0xa6f0fc
  (600 B), +0x28 0xa6f378 (36 B), +0x30 0xa6f39c (576 B), +0x38
  0xa6f5dc (196 B).
- Base part (AnimObj, +0x00..+0x57) is written entirely by base ctor
  0xa6edc4; bytes +0x30..+0x4f are never stored by the ctor and are
  unproven.

## Construction / init order

1. Base ctor 0xa6edc4(this): installs AnimObj vptr at +0x00
   (cell 0x1314f58 + 0x10), zeroes +0x10/+0x14/+0x18, stores 1.0f at
   +0x1c, stores raw cell value (0xa6ec0c) at +0x20 and 0 at +0x28,
   zeroes +0x50, writes this+0x10 at +0x08.
2. Derived init overwrites +0x00 with vptr 0x12f17d8 and zeroes +0x68.
