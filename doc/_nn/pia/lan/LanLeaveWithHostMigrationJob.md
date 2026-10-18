# nn::pia::lan::LanLeaveWithHostMigrationJob

RTTI-confirmed via typeinfo name `N2nn3pia3lan28LanLeaveWithHostMigrationJobE` (0xf80e40). Typeinfo-row vtable 0x12dcb90: GOT cell 0x1313418 holds vptr-0x10, installed vptr 0x12dcb98; word at 0x12dcb90 points to the embedded typeinfo object at 0x12dcbe0 (base typeinfo 0x12ddfb0 = nn::pia::session::LeaveWithHostMigrationJob - the same base as nn::pia::inet::InetLeaveWithHostMigrationJob). Offset-to-top 0. 8 slots; slots 2-4 shared job overrides (0xb4a654/0xb4a67c/0x933314 `ret`).

## Member notes

- Slot5 0x975788 stores [this+0x80]; slot6 0x975700 (0x140 bytes) is the LAN host-migration step body.
- Slot7 0x9864ec is shared verbatim with nn::pia::inet::InetLeaveWithHostMigrationJob; here its deepest reachable store is [this+0x58]/[this+0x70].
- Size: lower bound 0x88 from the slot5 store at +0x80 (qword), matching sibling NexMatchDestroySessionJob's 0x88 bound. Exact size unverified.

## Construction / init order

- Ctor 0x9756c0: GOT cell 0x1313418 -> +0x10 -> `[this]` = vptr; nothing else (0x9756c0..0x9756d0). No `bl` callers and no relocs to the ctor were found - construction site unverified.
