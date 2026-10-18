# nn::pia::transport::StationLocation

## Identity

- vtable row 0x12df3e0 (tsv row = typeinfo slot), vptr 0x12df3e8 = row + 8,
  6 slots. GOT cell 0x1313c50 holds 0x12df3d8 = vptr - 0x10 (offset-to-top
  0x12df3d8 = 0, typeinfo slot 0x12df3e0 = 0x12df418); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12df418 = {0x10, name 0xf826c0, base 0}; name =
  "N2nn3pia9transport15StationLocationE" (no base listed in the ti
  struct; the +0x8 base vptr proves the StationAddress base).
- Secondary base: [this+0x8] = 0x12d9580 (GOT cell 0x1312438), typeinfo
  0x12d9598 = nn::pia::common::StationAddress.
- Slots: 0 D1 0x9b3a40, 1 D0 0x9b3a88, 2 0x9b3c70, 3 0x9b3c8c, 4 0x9b3de8,
  5 0x9b3ee8 (0-quality 4-byte `ret`).
- D1 0x9b3a40: re-installs primary vptr, destroys +0x30 sub-object
  (0x92a014), re-installs the StationAddress vptr at +0x8, tail-destroys
  +0x10 sub (0x92a014). D0 0x9b3a88: same, then operator delete 0x60b470.
- extent 0x38: no heap allocation found — all ctor call sites build stack
  temporaries (e.g. sp+0x38 at 0x92e078) or embedded members (size 0x38
  subobjects inside LanConnectStationJob per its batch); 0x38 = +0x30
  subobject + 8. Cross-checked by the LanConnectStationJob header.

## Member notes

- +0x00 primary vptr; +0x08 StationAddress base (C1 0x92a1e0 covers
  [0x8, 0x30) — unproven gap).
- +0x18..0x2f: zeroed by C1 after the base ctor ([0x18,0x28) stp, +0x28
  u8, +0x29 u32 stur, +0x2d/+0x2e u8) — copy ctor 0x9b3908 and copy fn
  0x9b39bc copy exactly these bytes, so they are StationLocation's own
  scalars, not base members.
- +0x30: member sub-object, C1 0x929fd4, D1/D0 via 0x92a014.
- 0x9b3ad8 (not a slot) = copy-assign: 0x92a304(+0x8), copies the 0x18-0x2f
  scalars, tail 0x92a000(+0x30).

## Construction / init order

1. C1 0x9b38b8: vptr 0x12df3e8 -> [this] (0x9b38d8, cell 0x1313c50 + 0x10).
2. Base ctor 0x92a1e0(this + 0x8) (0x9b38dc).
3. Sub-object ctor 0x929fd4(this + 0x30) (0x9b38e4).
4. [this+0x28] = 0 (0x9b38e8); [this+0x18] = [this+0x20] = 0 (0x9b38ec);
   [this+0x2d] = 0 (0x9b38f0); [this+0x29] u32 = 0 (0x9b38f4);
   [this+0x2e] u8 = 0 (0x9b38f8).
