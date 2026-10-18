# nn::pia::inet::InetLeaveWithHostMigrationJob

RTTI-confirmed via typeinfo name `N2nn3pia4inet29InetLeaveWithHostMigrationJobE` (0xf7eb70). Typeinfo-row vtable 0x12da6f0: GOT cell 0x1312aa8 holds vptr-0x10, installed vptr 0x12da6f8; word at 0x12da6f0 points to the embedded typeinfo object at 0x12da740 (base typeinfo 0x12ddfb0 = nn::pia::session::LeaveWithHostMigrationJob, itself a nn::pia::common::StepSequenceJob). Offset-to-top 0. 8 slots; slots 2-4 shared job overrides (0xb4a654/0xb4a67c/0x933314 `ret`).

## Member notes

- Slot6 0x938218 (0x220 bytes) is the host-migration step body; it stores [this+0x18] and works through the global session-context GOT cells.
- Slot7 0x9864ec clears [this+0x58], [this+0x6c], writes [this+0x70] and [this+0x94] (byte) - deepest `this` offset in the class; shared verbatim with nn::pia::lan::LanLeaveWithHostMigrationJob slot7.
- Size: lower bound 0x98 from the slot7 store at +0x94 (byte). Exact size unverified.

## Construction / init order

- Ctor 0x9381d8: GOT cell 0x1312aa8 -> +0x10 -> `[this]` = vptr; nothing else (0x9381d8..0x9381f0). No `bl` callers and no relocs to the ctor were found - construction site unverified.
