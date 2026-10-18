# nn::pia::local::LocalNode

## Identity

- vtable row 0x12e2160 (tsv row = typeinfo slot), vptr 0x12e2168 = row + 8,
  6 slots. GOT cell 0x1314158 holds 0x12e2158 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e21a0 = {0x10, name 0xf83840, base 0x12dd558}; name =
  "N2nn3pia5local9LocalNodeE"; base 0x12dd558 = "N2nn3pia6common13ISerializableE"
  (nn::pia::common::ISerializable).
- Slots: 0 D1 0x9d448c, 1 D0 0x9d44ac, 2 0x9d44f0, 3 0x9d4588, 4 0x9d45fc,
  5 0x9d4604. None of slots 2-5 are in functions.csv (unrecovered).
- D1 0x9d448c: re-installs own vptr (cell 0x1314158 + 0x10) AND the +0x08
  member's vptr (cell 0x1313d58 + 0x10 -> vptr 0x12e0478), stp + advance
  0x10, then tail 0x92a014 (member D0). D0 0x9d44ac: same, then operator
  delete 0x60b470.
- size 0x28 EXACT: used as an array element with stride 0x28 by the outer
  ctor at 0x9c4c88 (8 elements at this+0x48..+0x188, C1 calls 0x9c4cc8..).

## Member notes

- +0x08 subobject (0x18 bytes): C1 0x9c2648 (0x9d4460); its methods
  0x9c2680 / 0x9c2688 / 0x9c271c / 0x9c2874 are reached by slots 2-5.
- +0x20 u32 = 0; +0x24 u8 = 0; +0x25 u8 = 0xff (0x9d4464..0x9d4470).
- Slot 2 0x9d44f0: takes (x1, x2); operates on the +0x08 subobject
  (0x9c2680/0x9c2688) and writes one byte into *x2 — reads a node byte;
  error constant 0xc0710000 on failure. unverified interpretation.
- Slot 3 0x9d4588: same shape; writes the byte to [this+0x25]. unverified.
- Slot 4 0x9d45fc: tail-add this+0x8 then b 0x9c2874.
- Slot 5 0x9d4604: calls 0x9c2680 on this+0x8, returns result + 1.

## Construction / init order

1. C1 0x9d443c: vptr 0x12e2168 -> [this] (0x9d445c, cell 0x1314158 + 0x10).
2. Subobject C1 0x9c2648(this + 0x8) (0x9d4460).
3. +0x20 = 0, +0x24 = 0, +0x25 = 0xff, +0x10/+0x14/+0x18 zeroed
   (0x9d4468..0x9d447c).
