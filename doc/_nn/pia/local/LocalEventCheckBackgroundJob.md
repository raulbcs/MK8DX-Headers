# nn::pia::local::LocalEventCheckBackgroundJob

## Identity

- vtable row 0x12e17c0 (tsv row = typeinfo slot), vptr 0x12e17c8 = row + 8,
  6 slots. GOT cell 0x1313fb0 holds 0x12e17b8 = vptr - 0x10; installed
  vptr = cell + 0x10.
- RTTI: typeinfo 0x12e1800 = {0x10, name 0xf83460, base 0x12f8d30}; name =
  "N2nn3pia5local28LocalEventCheckBackgroundJobE"; base 0x12f8d30 =
  nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x9cf5a8, 1 D0 0x9cf600, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314, 5 `ret` 0x9cf890 (bare `ret`; unrecovered in
  functions.csv). Slots 2-4 are the shared StepSequenceJob stubs.
- D1 0x9cf5a8 and D0 0x9cf600 follow the family pattern (re-install vptr,
  destroy +0x58 subobject, tail 0xb4a62c; D0 adds operator delete
  0x60b470) — bodies not individually disassembled (unverified).
- size 0x88 EXACT: operator new 0x88 at 0x9c53b0, C1 call 0x9c53c4.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58 subobject (0x18 bytes): C1 0x929ec0 (0x9cf580).
- +0x78: result of virtual call [x1 vtable + 0x190](x1) made by the C1
  (0x9cf588..0x9cf598).
- +0x80: C1 arg (x1, stored at 0x9cf584).

## Construction / init order

1. C1 0x9cf554: base C1 0xb4a5e0(this) (0x9cf568).
2. vptr 0x12e17c8 -> [this] (0x9cf57c, cell 0x1313fb0 + 0x10).
3. Subobject C1 0x929ec0(this + 0x58) (0x9cf580).
4. [this+0x80] = x1 (0x9cf584); [this+0x78] = virtual call result
   (0x9cf598).
