# nn::pia::session::ProcessUpdateMeshJob

## Identity

- vtable row 0x12de2a0 (tsv row = typeinfo slot), vptr 0x12de2a8 = row + 8, 6 slots.
  GOT cell 0x1313948 holds 0x12de298 = vptr - 0x10 (offset-to-top 0x12de298 = 0,
  typeinfo slot 0x12de2a0 = 0x12de2e0); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12de2e0 = {0x10, name 0xf81c70, base 0x12f8d30}; name =
  "N2nn3pia7session20ProcessUpdateMeshJobE"; base = nn::pia::common::StepSequenceJob.
- Slots: 0 D1 0x992b50 (re-installs vptr, frees +0x78 array with per-0x20
  element dtor 0x929ee0, frees +0xa8 with 0x78-element-size check, ...), 1 D0
  0x992cc8, 2 0xb4a654 (shared), 3 0xb4a67c (shared), 4 0x933314 (shared),
  5 0x9957d8 (reset virtual — re-runs base C1 0xb4a5e0).
- size 0x120 EXACT: operator new 0x120 (0x568aa0) then C1 0x992874 at factory
  0x986958-0x98696c.

## Member notes

- [0x08, 0x58) initialized by shared base C1 0xb4a5e0 — unproven gap.
- C1 0x992874 (0x992874-0x992b4c): [0x58] = 0; [0x60] = [0x64] = 20000
  (0x4e20, stp 0x9928bc); [0x70] = 10000; [0x68] = 0; [0xe0] = 0; vptr;
  sub-builder 0x929ec0(this + 0x100) (0x9928c4); memset(this + 0x80, 0xff,
  0x20) (0x9928d4); [0xe8] = 0; [0xf0] = 0; [0xc8]/[0xca] = 0; [0xcc] = 0;
  [0xd0] = 0; [0xd4] = 0; [0xf5] = [0xf6] = 0; [0xf8] = 0; byte [0xfc] = 1;
  tail call 0x929ed0(this + 0x100) (0x992b4c).

## Construction / init order

1. C1 0x992874: base C1 0xb4a5e0(this) (0x99288c).
2. [0x58] = 0, [0xe0] = 0.
3. vptr 0x12de2a8 -> [this] (0x9928c0, cell 0x1313948 + 0x10).
4. Sub-object 0x929ec0(this + 0x100) (0x9928c4).
5. Buffer memset + scalar tail stores (0x9928c8-0x992b3c), tail 0x929ed0.
