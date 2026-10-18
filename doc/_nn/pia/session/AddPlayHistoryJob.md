# nn::pia::session::AddPlayHistoryJob

## Identity

- vtable row 0x12dea30 (tsv row = typeinfo slot), vptr 0x12dea38 = row + 8, 6 slots.
  GOT cell 0x1313a48 holds 0x12dea28 = vptr - 0x10 (offset-to-top 0x12dea28 = 0,
  typeinfo slot 0x12dea30 = 0x12dea70); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12dea70 = {0x10, name 0xf81fc0, base 0x12f8d30}; name =
  "N2nn3pia7session17AddPlayHistoryJobE"; base = nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x99f750 (trivial — tail `b 0xb4a62c`, shared job-base D0), 1 D0
  0x99f754 (base dtor then operator delete 0x60b470), 2 0xb4a654 (shared),
  3 0xb4a67c (shared), 4 0x933314 (shared), 5 0xb4a7a4 (shared base-family
  fn: reads [x0+0xc], compares with 4).
- size 0xf8 EXACT: operator new 0xf8 (0x568aa0) then C1 0x99f71c at factory
  0x997a90-0x997aa4.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- [0x58, 0xec) untouched by C1 — unproven gap (fields presumably set by the
  job's execute path). Byte [0xec] = 0 (C1 0x99f71c).

## Construction / init order

1. C1 0x99f71c: base C1 0xb4a5e0(this) (0x99f72c).
2. vptr 0x12dea38 -> [this] (0x99f740, cell 0x1313a48 + 0x10).
3. Byte [0xec] = 0 (0x99f738).
