# nn::pia::local::LocalBackgroundProcessJob

## Identity

- vtable row 0x12e14e0 (tsv row = typeinfo slot), vptr 0x12e14e8 = row + 8,
  6 slots. GOT cell 0x1313ed8 holds 0x12e1478 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e1560 = {0x10, name 0xf832b0, base 0x12f8d30}; name =
  "N2nn3pia5local25LocalBackgroundProcessJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9cd3c0, 1 D0 0x9cd3fc, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 bare `ret` 0x9cdc60 (unrecovered in functions.csv).
- D1 0x9cd3c0: re-installs vptr, destroys the +0x80 sub-object (0xb48600),
  tail 0xb4a62c. D0 0x9cd3fc: same body then operator delete.
- extent 0x88 unverified (lower bound): last field touched is the +0x80
  sub-object; no direct operator-new factory found. A derived class ctor
  at 0x9c9dec re-installs a different vptr (cell 0x1313e38) and stores up
  to +0xc0, so this class is used as a base.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1.
- +0x60 u32 = 10 (only class in this family initializing it); +0x64 u16 = 0.
- +0x68: zeroed by C1; +0x70: arg x1 stored verbatim.
- +0x78 u8 = 0; +0x80: sub-object tail-initialized by 0xb485a8 (dtor pair
  0xb48600) — size unverified.

## Construction / init order

1. C1 0x9cd36c: base C1 0xb4a5e0(this) (0x9cd380).
2. [this+0x60] = 10; [this+0x64] = 0 (0x9cd38c-0x9cd390).
3. [this+0x68] = 0; [this+0x70] = arg x1 (0x9cd394-0x9cd398).
4. [this+0x58] = 0 (0x9cd3a4); [this+0x78] = 0 (0x9cd3a8).
5. vptr 0x12e14e8 -> [this] (0x9cd3ac, cell 0x1313ed8 + 0x10).
6. Sub-object tail-ctor 0xb485a8(this + 0x80) (0x9cd3bc).
