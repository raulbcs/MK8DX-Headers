# nn::pia::local::LocalEjectClientListCheckJob

## Identity

- vtable row 0x12e1760 (tsv row = typeinfo slot), vptr 0x12e1768 = row + 8,
  6 slots. GOT cell 0x1313fa0 holds 0x12e1758 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e17a0 = {0x10, name 0xf83420, base 0x12f8d30}; name =
  "N2nn3pia5local28LocalEjectClientListCheckJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9cf40c, 1 D0 0x9cf424, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9cf550 (bare `ret`; unrecovered in
  functions.csv). Slots 2-4 are the shared StepSequenceJob stubs.
- D1 0x9cf40c: zeroes [this+0x60], re-installs vptr (cell 0x1313fa0 +
  0x10), tail 0xb4a62c (shared job-base D0). D0 0x9cf424: same body then
  operator delete 0x60b470.
- size 0x68 EXACT: operator new 0x68 at 0x9bf688 whose factory call
  0x9bf69c targets derived C2 0x9cb80c (re-installs vptr cell 0x1313e70
  + 0x10 over base C1 0x9cf3d4); the derived class adds no fields, so the
  base size is also 0x68.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58: zeroed by C1; set by helper 0x9cf45c alongside a delegate
  slot at +0x30..+0x40 (cell 0x1313fa8 + 0x10 at +0x30, string 0xf130c6b
  at +0x40).
- +0x60: C1 arg (x1, stored at 0x9cf3f8 stp), zeroed by D1.

## Construction / init order

1. C1 0x9cf3d4: base C1 0xb4a5e0(this) (0x9cf3e8).
2. [this+0x58] = 0, [this+0x60] = x1 (0x9cf3f8).
3. vptr 0x12e1768 -> [this] (0x9cf3fc, cell 0x1313fa0 + 0x10).
