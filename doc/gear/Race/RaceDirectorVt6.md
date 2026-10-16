# RaceDirectorVt6 (gear::RaceDirectorVt6)

- PROVISIONAL vtable-anchored name. Vtable 0x11b3598 (GOT 0x12fbd10; the doc's 0x11b35a8 is the D1 slot, not the vptr), typeinfo 0x53720 ("*(u32*)(this+0x9c) == 0"). Ctor 0x710005377c. Size 0xD8, proven by the allocation site 0x710006ef64.

Derives from RaceDirectorVt2. Seeds 0xb8 with the rodata constant 11 and copies two rodata tables ([0xf57b7c] u64 + u32) into 0xc0/0xc8.

Naming: rodata-seeded config (11 at 0xb8, two tables at 0xc0/0xc8); no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x9C/0xA0/0xA4 — ctor zero.
- 0xA8 mTicks600 — ctor sets 600.
- 0xAC — ctor sets -1.
- 0xB0/0xB4 — ctor zero.
- 0xB8 mCount11b8 — ctor copies *(u32*)rodata 0xf73bb4 (== 11); slot 0xd0 override getter returns this word.
- 0xBC — ctor zero.
- 0xC0 mTableC0 — ctor copies *(u64*)rodata 0xf57b7c.
- 0xC8 mTableC8 — ctor copies *(u32*)(0xf57b7c+8).
- 0xCC — ctor zero (u16); 0xD0 — ctor zero.
- 0xCE — unproven gap.

## Construction / init order

1. Ctor 0x710005377c calls 0x4e2f4 (RaceDirectorVt2).
2. 0x9C..0xBC zeros (0xB8 then overwritten), 0xA8 = 600, 0xAC = -1.
3. 0xB8 = *(u32*)rodata 0xf73bb4 (== 11); 0xC0 = *(u64*)rodata 0xf57b7c; 0xC8 = *(u32*)(0xf57b7c+8); 0xCC/0xD0 zero. Store reach 0xd4.
4. Allocation 0x710006ef64.
