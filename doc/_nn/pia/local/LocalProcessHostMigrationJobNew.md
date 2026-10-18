# nn::pia::local::LocalProcessHostMigrationJobNew

## Identity

RTTI-named: typeinfo data 0x12e0ad0, name "N2nn3pia5local31LocalProcessHostMigrationJobNewE" (string 0xf82fa0). Typeinfo-slot row at 0x12e0a40 (offset-to-top 0 at 0x12e0a38; typeinfo slot -> 0x12e0ad0); installed vptr 0x12e0a48. GOT cell 0x1313dc8 holds 0x12e0a38 (vptr - 0x10). 17 virtual slots (0x12e0a48-0x12e0ac8). No secondary vtable.

## Member notes

- Slot 11 = LocalProcessHostMigrationJobNew::LocalCleanupOldHostInfo (0x9c43e0, named in config/functions.csv). Slot 0 = C2 0x9c4350, slot 1 = D1 0x9c4394 (dtors run member tails 0x92a014 on +0x12c and +0x124, then base tail 0x99007c). Slots 2/3 = 0xb4a654/0xb4a67c (shared pia job-interface pair), slot 14 = 0x99034c.
- this+0x124 / this+0x12c: two 8-byte member subobjects initialized by 0x7100929fd4 (0x9c4320-0x9c4328), then zeroed field-wise (u32 @0x124, u16 @0x128, u32 @0x12c, u16 @0x130; 0x9c4334-0x9c4340).
- this+0x138: C1 second argument (x1) stored verbatim (0x9c432c).
- this+0x140: zero byte (0x9c4330).

## Construction / init order

- Factory 0x9c3b68: operator new(0x148) via 0x568aa0, then C1 0x9c42f4(this, x1 = factory's saved global) — size 0x148 proven (0x9c3b88-0x9c3ba0).
- C1 order: base 0x98ffbc -> vptr 0x12e0a48 -> member inits 0x929fd4 at +0x124 and +0x12c -> arg store @0x138 -> zero stores above.
