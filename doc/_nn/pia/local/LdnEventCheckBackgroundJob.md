# nn::pia::local::LdnEventCheckBackgroundJob

## Identity

- vtable row 0x12e10f0 (tsv row = typeinfo slot), vptr 0x12e10f8 = row + 8,
  6 slots. GOT cell 0x1313e70 holds 0x12e10e8 = vptr - 0x10 (offset-to-top
  0x12e10e8 = 0, typeinfo slot 0x12e10f0 = 0x12e1130); installed vptr =
  cell + 0x10.
- RTTI: typeinfo 0x12e1130 = {0x10, name 0xf83170, base 0x12e17a0, 0}; name =
  "N2nn3pia5local26LdnEventCheckBackgroundJobE"; base 0x12e17a0 =
  nn::pia::local::LocalEventCheckBackgroundJob.
- Slots: 0 D1 0x9cb83c (4-byte tail b 0x9cf40c = base D1), 1 D0 0x9cb840
  (base D1 0x9cf40c then operator delete 0x60b470), 2 ret 0xb4a654, 3 ret
  0xb4a67c, 4 ret 0x933314 (shared StepSequenceJob cluster), 5 0x9cb864
  (tail b 0x9cf550 — thunk to a base virtual).
- size 0x68 EXACT: operator new 0x68 at 0x9bf688 (caller 0x9bf69c); sole site
  found.

## Member notes

- [0x08, 0x68) = LocalEventCheckBackgroundJob base subobject (base C1
  0x9cf3d4) — unproven gap here; derived C2 adds no fields of its own.

## Construction / init order

1. C2 0x9cb80c: base C1 0x9cf3d4(this) — LocalEventCheckBackgroundJob C1
   (0x9cb81c).
2. vptr 0x12e10f8 -> [this] (0x9cb82c, cell 0x1313e70 + 0x10).
- Factory: operator new 0x68 at 0x9bf688, C2 0x9cb80c at 0x9bf69c.
