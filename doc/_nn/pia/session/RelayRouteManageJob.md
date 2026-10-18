# nn::pia::session::RelayRouteManageJob

## Identity

- vtable row 0x12de3c0 (tsv row = typeinfo slot), vptr 0x12de3c8 = row + 8, 6 slots.
  GOT cell 0x13139c8 holds 0x12de3b8 = vptr - 0x10 (offset-to-top 0x12de3b8 = 0,
  typeinfo slot 0x12de3c0 = 0x12de400); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12de400 = {0x10, name 0xf81d30, base 0x12f8d30}; name =
  "N2nn3pia7session19RelayRouteManageJobE"; base = nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x996d78 (re-installs vptr, frees +0x68, +0x70, +0x80 via
  0x568bb0/0x568b64, tail base dtor 0xb4a62c), 1 D0 0x996df0, 2 0xb4a654
  (shared), 3 0xb4a67c (shared), 4 0x933314 (shared), 5 0x9974b8
  (class virtual, full-size body 0x9974b8-...).
- size 0x90 EXACT: operator new 0x90 (0x568aa0) then C1 0x996be4 at factory
  0x986a48-0x986a5c.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- C1 0x996be4 (0x996be4-0x996d78): [0x5c] = [0x60] = 0; [0x88] = 0; vptr;
  reads global config cell 0x13125e0, halfword [x8+0x48] -> [0x58] (grid
  dimension, 0x996c10-0x996c20); dim*dim byte array allocated via
  0x563b70 + 0x568aa0 (0x996c24-0x996c38), zero-filled by unrolled loop +
  tail memset (array, 0, dim) (0x996d74); array ptr -> [0x80] (0x996d60).

## Construction / init order

1. C1 0x996be4: base C1 0xb4a5e0(this) (0x996bf4).
2. vptr 0x12de3c8 -> [this] (0x996c0c, cell 0x13139c8 + 0x10).
3. Config-derived dimension -> [0x58] (0x996c20).
4. Array alloc + zero-fill -> [0x80] (0x996c24-0x996d74).
