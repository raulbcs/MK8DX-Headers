# nn::pia::local::LocalLeaveWithHostMigrationJobNew

## Identity

- vtable row 0x12e1980 (tsv row = typeinfo slot), vptr 0x12e1988 = row + 8, 9 slots.
  GOT cell 0x1314040 holds 0x12e1978 = vptr - 0x10 (offset-to-top 0x12e1978 = 0,
  typeinfo slot 0x12e1980 = 0x12e19d0); installed vptr = cell + 0x10.
- RTTI: typeinfo 0x12e19d0 = {0x10, name 0xf83560, base 0x12ddfb0}; name =
  "N2nn3pia5local33LocalLeaveWithHostMigrationJobNewE"; base 0x12ddfb0 =
  "N2nn3pia7session25LeaveWithHostMigrationJobE" (its base C1 0x985dd8 is
  called directly by the derived C1 0x9d1328; the session-base vtable itself
  is unmapped here).
- Slots: 0 D1 0x9d1360, 1 D0 0x9d1378, 2 ret 0xb4a654, 3 ret 0xb4a67c,
  4 ret 0x933314 (inherited cluster), 5 `ret` 0x9d14f8, 6 0x9d13b0
  (uses global cell 0x1312488 and [this+0x98]+0x18+0x188), 7 0x9864ec.
- D1 0x9d1360: [this+0x98] = 0, re-installs vptr, tail base D1 0x985e34.
  D0 0x9d1378: same then operator delete 0x60b470.
- extent 0xa0 EXACT: operator new 0xa0 at 0x9c3bd4-0x9c3bec followed by
  C1 0x9d1328 (sole allocation site).
- Virtual-dispatch callers of slot 7 (vptr + 0x40): 0x9d9b1c (via
  [x+0xb0]->vptr), 0x9f25fc, 0xa18bb4.

## Member notes

- [0x08, 0x58) initialized by the shared pia job-base C1 0xb4a5e0 (called from
  base C1 0x985dd8) — unproven gap.
- +0x58/+0x60 zeroed as a pair (stp xzr, xzr, 0x985df8); +0x68 = 5000;
  +0x70 = 0xfd; [0x74, 0x94) memset 0 (0x20 bytes).
- +0x98 = C1 arg x1 (0x9d1348), stored after the base C1 returns; nulled by D1.

## Construction / init order

1. C1 0x9d1328: base C1 0x985dd8(this) (0x9d133c).
2. [this+0x98] = x1 (0x9d1348).
3. vptr 0x12e1988 -> [this] (0x9d1350, cell 0x1314040 + 0x10).
