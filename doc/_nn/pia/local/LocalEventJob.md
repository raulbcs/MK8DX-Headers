# nn::pia::local::LocalEventJob

## Identity

- vtable row 0x12e1820 (tsv row = typeinfo slot), vptr 0x12e1828 = row + 8,
  6 slots. GOT cell 0x1313fd8 holds 0x12e1818 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e1860 = {0x10, name 0xf83480, base 0x12f8d30}; name =
  "N2nn3pia5local13LocalEventJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9cf8cc, 1 D0 0x9cf8e4, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9cfad0 (bare `ret`; unrecovered in
  functions.csv). Slots 2-4 are the shared StepSequenceJob stubs.
- D1 0x9cf8cc: zeroes [this+0x60], re-installs vptr (cell 0x1313fd8 +
  0x10), tail 0xb4a62c. D0 0x9cf8e4: same body then operator delete
  0x60b470.
- size 0x68 EXACT: operator new 0x68 at 0x9bfa98 whose factory call
  0x9bfaac targets derived C2 0x9cb868 (re-installs vptr cell 0x1313e78 +
  0x10 over base C1 0x9cf894); the derived class adds no fields.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1 (0x9cf8b8 stp).
- +0x60: C1 arg (x1), zeroed by D1/D0.

## Construction / init order

1. C1 0x9cf894: base C1 0xb4a5e0(this) (0x9cf8a8).
2. [this+0x58] = 0, [this+0x60] = x1 (0x9cf8b8).
3. vptr 0x12e1828 -> [this] (0x9cf8bc, cell 0x1313fd8 + 0x10).
