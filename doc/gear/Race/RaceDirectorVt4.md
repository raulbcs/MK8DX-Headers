# RaceDirectorVt4 (gear::RaceDirectorVt4)

- PROVISIONAL vtable-anchored name. Vtable 0x11b3328 (.data anchor; GOT 0x12fbce0), typeinfo 0x4fc94 (per-object predicate on this+0x9c). Ctor 0x710004fd6c. Size 0xC0, proven by the allocation site 0x710006ee7c.

Derives from RaceDirectorVt2. Built by the director factory 0x710006eb5c (dispatches on getRaceCheckManager [x0+8]/[x0+0xc] == 3) and stored at [parent+0xa8].

Naming: predicate (this+0x9c) selector built when getRaceCheckManager flags == 3; no name evidence. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x9C/0xA0/0xA4 — ctor zero.
- 0xA8 mTicks600 — ctor sets 600 (0x258).
- 0xAC — ctor sets -1.
- 0xB0 — ctor zero.
- 0xB8 — ctor sets 0xFFFF; slot 0xd0 override getter returns the word at 0xB8.
- 0xBA — ctor sets 0xFFFF.
- 0xBC — slot 0xd8 override getter returns this word.
- 0xB4 — unproven gap.

## Construction / init order

1. Ctor 0x710004fd6c calls 0x4e2f4 (RaceDirectorVt2).
2. 0x9C/0xA0/0xA4/0xB0 = 0; 0xA8 = 600 (0x258); 0xAC = -1; 0xB8/0xBA = 0xFFFF.
3. Factory 0x710006eb5c allocates (0x710006ee7c) and stores at [parent+0xa8].
