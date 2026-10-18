# nn::pia::lan::LanProcessHostMigrationJob

## Identity

RTTI-named: typeinfo data 0x12dc700, name "N2nn3pia3lan26LanProcessHostMigrationJobE" (string 0xf80cc0). Vtable row at 0x12dc670 is a typeinfo-slot row (offset-to-top 0 at 0x12dc668; typeinfo slot 0x12dc670 -> 0x12dc700); the installed vptr is 0x12dc678. GOT cell 0x1313330 holds 0x12dc668 (vptr - 0x10). 17 virtual slots (0x12dc678-0x12dc6f8). No secondary vtable.

## Member notes

- Slots (all unresolved except): slot 2 = 0xb4a654, slot 3 = 0xb4a67c (shared nn::pia job-interface override pair, common to the lan/local job family), slot 4 = 0x933314, slot 14 = 0x99034c (shared with the local ProcessHostMigration job). Slot 0 = C2 0x96e1b4, slot 1 = D1 0x96e1ec (calls base tail 0x99007c then operator delete 0x60b470).
- Base subobject: C1 0x96e154 first calls base ctor 0x98ffbc with this; a flag byte at this+0xd4 (written by the base) gates the conditional memset at +0x160.
- this+0x128: member subobject initialized by 0x929ec0 (x0 = this+0x128); extent of the member unknown.
- this+0x148 / +0x158: zeroed (0x96e184-0x96e188).
- this+0x160: memset(this+0x160, 0, 0x80) when [this+0xd4] != 0 (0x96e194-0x96e1a0).
- this+0x1e1: zeroed; this+0x1e8..0x1f0: stp xzr,xzr (0x96e18c).

## Construction / init order

- Factory 0x96cfa0: operator new(0x1f8) via 0x568aa0, then C1 0x96e154 — size 0x1f8 proven (0x96cfb4-0x96cfc8).
- C1 order: base 0x98ffbc -> vptr 0x12dc678 -> member 0x929ec0(this+0x128) -> zero stores above.
- C2 0x96e1b4: base tail 0x929ee0(this+0x128) then base D-tail 0x99007c.
