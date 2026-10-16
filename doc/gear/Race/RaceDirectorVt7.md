# RaceDirectorVt7 (gear::RaceDirectorVt7)

- PROVISIONAL vtable-anchored name. Vtable 0x11b36d0 (GOT 0x12fbd28; 0x11b36e0 is the D1 slot), typeinfo 0x56b28 ("(*(u32*)(this+0x9c) | 1) == 1" — accepts state 0 or 1). Ctor 0x7100056ba8. Size 0xC8, proven by the allocation site 0x710006f06c (guarded by the race-check-manager flag at 0x6efac).

Derives from RaceDirectorVt2. Overrides both slot 0xd0 (0x58374) and 0xd8 (0x58338) — the only one of the set that does.

Naming: predicate accepts state 0/1; only member overriding slots 0xd0/0xd8; no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x9C/0xA0/0xA4 — ctor zero.
- 0xA8 mTicks600 — ctor sets 600.
- 0xAC — ctor sets -1.
- 0xB0/0xB4/0xB5 — ctor zero.
- 0xB6-0xBD — unproven padding.
- 0xBE mUbe — ctor packs *(u32*)rodata 0xf73bb4 (== 11, unaligned 4-byte store) over 0xbe..0xc1.
- 0xC0 mUc0 — upper half of the same rodata copy; slot 0xd0 override getter (0x58374) returns the byte at 0xBE.
- 0xC2 — unproven gap.
- 0xC4 — ctor zero.

## Construction / init order

1. Ctor 0x7100056ba8 calls 0x4e2f4 (RaceDirectorVt2).
2. Zeros 0x9C..0xB5 (0xA8 = 600, 0xAC = -1); unaligned 4-byte copy of *(u32*)rodata 0xf73bb4 over 0xbe..0xc1; 0xC4 zero. Store reach 0xc8.
3. Allocation 0x710006f06c, guarded by the race-check-manager flag at 0x6efac.
