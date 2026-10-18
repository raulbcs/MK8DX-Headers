# game::Vt12f8cf0

PLACEHOLDER name (identity not proven). Assigned address 0x12f8cf0 is the
typeinfo slot; installed vptr = 0x12F8CF8 (row = assigned+8, vt-8 convention).
Typeinfo slot points to the typeinfo object at 0x12F8D30. GOT cell 0x1315F70
holds assigned-8 = 0x12F8CE8.

## Identity

- Ctor FUN_7100B4A5E0 (0xB4A5E0, 76 bytes), called in-place from ~10 embedded
  subobject ctors in the 0x93xxxx registry family (0x930F28, 0x932970,
  0x93B350, 0x964774, 0x966B94, 0x97BB38, 0x97DC68, 0x97DDD0, 0x97DFD0,
  0x97E0F4); no operator new at the ctor, so 0x58 is a lower bound from the
  deepest store ([this+0x50]) — complete-object size unverified.
- Multiple inheritance: [this] = cell 0x1315F70+0x10 = 0x12F8CF8 and
  [this+0x28] = cell 0x1313040+0x10 (addend 0x12DB168 → vptr 0x12DB178)
  (0xB4A5F4-0xB4A614).
- Base ctor 0x567CB8 (vptr cell 0x130B2D0) zeroes [this+0x8], [this+0xC] and
  [this+0x10..0x27]; slot 0 of the primary table (0xB4A62C) is a tail-call to
  the base's null D1 0x567CDC (`ret`), i.e. trivial D1.

## Table 0x12F8CF8 (6 slots)

| slot | addr | notes |
| --- | --- | --- |
| 0 | 0xB4A62C | D1 thunk, tail `b 0x567CDC` (ret) |
| 1 | 0xB4A630 | FUN_7100B4A630, 0x24 bytes |
| 2 | 0xB4A654 | FUN_7100B4A654, 0x28 bytes |
| 3 | 0xB4A67C | FUN_7100B4A67C, 0x6C bytes |
| 4 | 0x933314 | unrecovered (absent from functions.csv) |
| 5 | 0xB4A7A4 | FUN_7100B4A7A4, 4 bytes (O) |

## Construction / init order

- 0xB4A5E0: base ctor 0x567CB8; install primary vptr 0xB4A5F4-0xB4A600;
  install secondary vptr at +0x28 (0xB4A604-0xB4A614); zero [this+0x38..0x47],
  byte [this+0x48], ptr [this+0x50] (0xB4A60C-0xB4A61C).
- Embedding parents continue at [this+0x58]/[this+0x68] with further GOT cells
  (e.g. 0x13128F0 at 0x930F2C-0x930F3C), so the class is a base subobject of
  larger registry nodes.
