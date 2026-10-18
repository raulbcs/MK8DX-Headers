# DummyPacketEncDec

- RTTI-named: typeinfo 0x12e4c20, name string "N2nn3nex17DummyPacketEncDecE";
  base typeinfo 0x12e4270 (PacketEncDecInf).
- GOT cell convention: cell 0x1314708 holds 0x12e4bb8 = vptr - 0x10.
  Installed vptr = 0x12e4bc8. 9 fn slots at vptr+0x00..+0x40.

## Member notes

- +0x08 u32: C1 arg (w22 stored at 0xa03894); the in-place path zeroes it
  (0xa03864).
- +0x10 RC4PacketEncDec (0xc0): the (inlined) C1 installs this vptr at [this],
  then calls RC4PacketEncDec C1 0x9f3574 on this+0x10 (0xa0389c-0xa038a4).
  The in-place construction path pre-installs the RC4 vptr (cell 0x1314560
  family) at +0x10 before the base C1 (0xa0386c-0xa03874).

## Construction / init order

- C1 inlined at two sites in one function: in-place (0xa03864: store u32 arg,
  both vptrs) and heap — factory allocates 0xd0 via 0x573f04 (0xa03880),
  stores w22 at +8, installs vptr 0x12e4bc8 at +0, calls RC4 C1 on +0x10
  (0xa038a4). Size 0xd0 proven.
- Slots (9): 0 = 0x576b84, 1 = 0xa1aa0c, 2 = 0xa1aa10 (8 bytes), 3 = 0xa1aa1c,
  4 = 0xa1aa20, 5 = 0xa1aa24, 6 = 0xa1aa28, 7 = 0xa1aa30, 8 = 0xa1aa34 — a
  block of tiny stub overrides; bodies unrecovered in functions.csv (no D1/D0
  body identified; slot 0 sits next to the allocator thunks).
