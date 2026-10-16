# RaceDirectorVt3 (gear::RaceDirectorVt3)

- PROVISIONAL vtable-anchored name. Vtable 0x11b31e8 (.data 0x11b31d8, GOT 0x12fbcc0), typeinfo 0x4e6f8. Ctor 0x710004e784 (calls 0x4e2f4). Size 0xC0, proven by the sole allocation site 0x710006ed94 (new 0xC0, then shared actor-registration tail 0x6f348).

Derives from RaceDirectorVt2. Carries a 600-tick timer (0xa4) and -1 sentinels.

The per-frame calc hook is the slot-0x108 override 0x4e7dc (reads [0x50] config and [0x58], RaceInfo lookup, then slot-0x138 vcall on the 0x58 child).

Naming: 600-tick timer + -1 sentinels; per-frame calc 0x4e7dc reads config and calls a child vcall; no rodata name in the unit. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x9C/0xA0 — ctor zero (qword store covers 0x9c-0xa3).
- 0xA4 mTicks600 — ctor sets 600 (0x258).
- 0xA8 — ctor zero.
- 0xAC/0xB0 — ctor sets -1.
- 0xB8 — ctor copies *(u32*)rodata 0xf73bb4 (== 0xFFFFFFFF); slot 0xc0 override getter returns this word; the rodata cell also holds 11 for Vt6/Vt7.
- 0xBC — slot 0xc8 override getter returns this word.
- 0xB4 — unproven gap.

## Construction / init order

1. Ctor 0x710004e784 calls 0x4e2f4 (RaceDirectorVt2).
2. Qword zero store covers 0x9c-0xa3; 0xA8 zero.
3. 0xA4 = 600 (0x258); 0xAC/0xB0 = -1; 0xB8 = *(u32*)rodata 0xf73bb4.
4. Allocation 0x710006ed94 (new 0xC0) then shared actor-registration tail 0x6f348.
