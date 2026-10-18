# nn::pia::local::LocalAllowParticipatingBackgroundJob

## Identity

- vtable row 0x12e21c0 (tsv row = typeinfo slot), vptr 0x12e21c8 = row + 8,
  6 slots. GOT cell 0x1314160 holds 0x12e21b8 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e2200 = {0x10, name 0xf83860, base 0x12f8d30}; name =
  "N2nn3pia5local36LocalAllowParticipatingBackgroundJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9d4660, 1 D0 0x9d4678, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9d484c (bare `ret`; unrecovered in
  functions.csv). Slots 2-4 are the shared StepSequenceJob stubs.
- D1 0x9d4660: zeroes [this+0x68], re-installs vptr (cell 0x1314160 +
  0x10), tail 0xb4a62c. D0 0x9d4678: same body then operator delete
  0x60b470.
- size 0x70 EXACT: operator new 0x70 at 0x9ccfe8 with C1 0x9d4620 call at
  0x9cd000 (the object is embedded at +0x58 of a holder class whose C2 is
  0x9ccfa4, vptr cell 0x1313eb8).

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1 (0x9d4640); the holder C2 0x9ccfa4 overwrites it
  with its own +0x58 pointer.
- +0x60 u32 = 0 (0x9d4644).
- +0x68: C1 arg (x1, stored at 0x9d4648), zeroed by D1/D0.

## Construction / init order

1. C1 0x9d4620: base C1 0xb4a5e0(this) (0x9d4634).
2. vptr 0x12e21c8 -> [this] (0x9d4650, cell 0x1314160 + 0x10).
3. [this+0x58] = 0 (0x9d4640); [this+0x60] = 0 (0x9d4644);
   [this+0x68] = x1 (0x9d4648).
