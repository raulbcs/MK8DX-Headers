# nn::pia::session::SessionStatusCheckJob

## Identity

- vtable row 0x12de7e0 (tsv row = typeinfo slot), vptr 0x12de7e8 = row + 8, 6 slots.
  GOT cell 0x1313a08 holds 0x12de7d8 = vptr - 0x10 (offset-to-top 0x12de7d8 = 0,
  typeinfo slot 0x12de7e0 = 0x12de820); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12de820 = {0x10, name 0xf81ea0, base 0x12f8d30}; name =
  "N2nn3pia7session21SessionStatusCheckJobE"; base = nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x99d384 (re-installs vptr via store-with-writeback
  `str x8, [x0], #0x58`, tears down +0x58 sub-object with 0x929ee0, tail
  base dtor 0xb4a62c), 1 D0 0x99d3b8, 2 0xb4a654 (shared), 3 0xb4a67c
  (shared), 4 0x933314 (shared), 5 0x99da90 (class virtual, reads global
  cell 0x1313a20).
- size 0x80 EXACT: operator new 0x80 (0x568aa0) then C1 0x99d348 at factory
  0x997828-0x99783c.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58 sub-object built by 0x929ec0 (same builder as ProcessUpdateMeshJob
  +0x100); only the sub-vptr is vtable-proven. [0x78] = 0 (C1 0x99d348).

## Construction / init order

1. C1 0x99d348: base C1 0xb4a5e0(this) (0x99d358).
2. Sub-object 0x929ec0(this + 0x58) (0x99d370).
3. vptr 0x12de7e8 -> [this] (0x99d36c, cell 0x1313a08 + 0x10).
4. [0x78] = 0 (0x99d374).
