# nn::pia::session::ProcessJoinRequestJob

## Identity

- vtable row 0x12de240 (tsv row = typeinfo slot), vptr 0x12de248 = row + 8, 6 slots.
  GOT cell 0x1313910 holds 0x12de238 = vptr - 0x10 (offset-to-top 0x12de238 = 0,
  typeinfo slot 0x12de240 = 0x12de280); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12de280 = {0x10, name 0xf819c0, base 0x12f8d30}; name =
  "N2nn3pia7session21ProcessJoinRequestJobE"; base = nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x991ea8 (re-installs vptr, frees +0x78/+0x80/+0x88 pointers via
  0x568bb0/0x568b64, tears down +0x98 sub-object — continues to 0x991f38's body
  region), 1 D0 0x991f38, 2 0xb4a654 (shared), 3 0xb4a67c (shared), 4 0x933314
  (shared), 5 0x992870 (`ret` stub).
- size 0xa8 EXACT: operator new 0xa8 (0x568aa0) then C1 0x991d5c at factory
  0x98692c-0x986940.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- C1 0x991d5c: [0x58] = 0, [0x60] = 10000 (0x2710) (stp at 0x991d7c); sub-object
  builder 0x92a1e0(this + 0x90) (0x991d8c); [0xa0] = 0xfd, [0xa4] = 0x300,
  byte [0xa6] = 0; remaining stores 0x991e7c-0x991e90 ([0x78] = 0, [0x80] = 0,
  [0x88] = config-derived x0, [0x68] = 0, [0x70] = 0).
- Config reads: global cell 0x1312748 (0x991da0) feeds a dimension computation
  (0x991db0-0x991dd4), unverified how it lands in this object.

## Construction / init order

1. C1 0x991d5c: base C1 0xb4a5e0(this) (0x991d6c).
2. vptr 0x12de248 -> [this] (0x991d88, cell 0x1313910 + 0x10).
3. Sub-object 0x92a1e0(this + 0x90) (0x991d8c).
4. Scalar tail stores (0x991d90-0x991e90) as listed above.
