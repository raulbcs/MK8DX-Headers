# RaceDirectorVt7e38 (gear::RaceDirectorVt7e38)

- PROVISIONAL vtable-anchored name (vptr written by the ctor from cell 0x12fcd00; .data 0x12c7e38). Far-family director, 30 slots. Ctor 0x7d5450, size 0x180 (alloc 0x8bc7a8: new 0x180).

Base: RaceDirectorBase38 (ctor 0x7b976c).

Naming: RECLASSIFIED by consumer evidence: ctor 0x7d5450 is the primary base of RaceListItemF (same chain cited in RaceListItemF.hpp); far-family base-subobject, not an independent director. Name stays PROVISIONAL. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero; 0x3c unproven padding.
- 0x40/0x48 — u64 ctor zero.
- 0x50 — list init (0x60b918, count 4, end this+0x60).
- 0x60..0x7f — untouched by the ctor (unproven gap).
- 0x80 — ctor sets 1; 0x81 unproven padding.
- 0x88 — u64 ctor zero.
- 0x90 — s32 = -1; 0x94 unproven padding.
- 0x98/0xa0/0xa8 — u64 ctor zero.
- 0xb0 — s32 = -1; 0xb4 — u8 = 1; 0xb5 unproven padding.
- 0xb8 — sub-object, 0x78 bytes (ctor 0x8df668, to 0x130).
- 0x130 — u32 = 0; 0x134 unproven padding.
- 0x138 — u64 = 0.
- 0x140 — member sub-object (ctor 0x628628, extent 0x40 — fills the alloc to 0x180).

## Construction / init order

1. Ctor 0x7d5450; base ctor 0x7b976c (RaceDirectorBase38).
2. 0x38/0x40/0x48 = 0.
3. List init at 0x50: 0x60b918 (count 4, end this+0x60).
4. 0x80 = 1; 0x88 = 0; 0x90 = -1; 0x98/0xa0/0xa8 = 0; 0xb0 = -1; 0xb4 = 1.
5. Sub-object ctor 0x8df668 at 0xb8 (to 0x130).
6. 0x130 = 0; 0x138 = 0.
7. Member sub-object ctor 0x628628 at 0x140 (extent 0x40, fills the alloc to 0x180).
8. Allocation 0x8bc7a8 (new 0x180). This ctor is the primary base of RaceListItemF.
