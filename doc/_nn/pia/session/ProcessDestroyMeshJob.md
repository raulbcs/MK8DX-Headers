# nn::pia::session::ProcessDestroyMeshJob

## Identity

- vtable row 0x12de130 (tsv row = typeinfo slot), vptr 0x12de138 = row + 8, 6 slots.
  GOT cell 0x13138e0 holds 0x12de128 = vptr - 0x10 (offset-to-top 0x12de128 = 0,
  typeinfo slot 0x12de130 = 0x12de170); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12de170 = {0x10, name 0xf81960, base 0x12f8d30}; name =
  "N2nn3pia7session21ProcessDestroyMeshJobE"; base = nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x98fce0 (tail `b 0xb4a62c`, shared job-base D0), 1 D0 0x98fce4
  (base dtor then operator delete 0x60b470), 2 0xb4a654 (shared base fn: calls
  0x567ce4, clears byte [this+0x48]), 3 0xb4a67c (shared base fn), 4 0x933314
  (shared base fn), 5 0x98ffb8 (reset virtual — re-runs base C1 0xb4a5e0).
- size 0x68 EXACT: operator new 0x68 (0x568aa0) then C1 0x98fca0 at factory
  0x9869b0-0x9869c4.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- +0x58 = 0, +0x60 = 1000 (0x3e8), byte +0x64 = 0 (C1 0x98fca0).

## Construction / init order

1. C1 0x98fca0: base C1 0xb4a5e0(this) (0x98fcb0).
2. [0x58] = 0 (0x98fcbc), byte [0x64] = 0 (0x98fcc0).
3. vptr 0x12de138 -> [this] (0x98fcc8, cell 0x13138e0 + 0x10).
4. [0x60] = 0x3e8 (0x98fccc-0x98fcd0).
