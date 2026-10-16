# RaceDirectorVt5 (gear::RaceDirectorVt5)

- PROVISIONAL vtable-anchored name. Vtable 0x11b3460 (GOT 0x12fbcf8), typeinfo 0x5114c ("*(u32*)(this+0x9c) == 0"). Ctor 0x71000511a8. Size 0xC8, proven by the allocation site 0x710006f32c.

Derives from RaceDirectorVt2. Carries a state machine on +0x9c (states 0..0xa, jump table rodata 0xf21438) with RaceInfo distance checks and item-box tables ([child+0x150..0x188]) in its slot-0x70-family logic (0x51200+).

Naming: state machine 0..0xa with item-box tables and RaceInfo distance checks; the state jump-table rodata carries no label. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x9C mState9c — state machine 0..0xa (jump table rodata 0xf21438).
- 0xA0/0xA4/0xA8 — ctor zero.
- 0xAC mTicks600 — ctor sets 600.
- 0xB0 — ctor sets -1.
- 0xB4/0xB8 — ctor zero.
- 0xBC — ctor sets 0xFFFF; slot 0xd0 override getter returns the word at 0xBC.
- 0xBE — ctor sets 0xFFFF.
- 0xC0 — slot 0xd8 override getter returns this word.

## Construction / init order

1. Ctor 0x71000511a8 calls 0x4e2f4 (RaceDirectorVt2).
2. 0xA0/0xA4/0xA8/0xB4/0xB8 = 0; 0xAC = 600; 0xB0 = -1; 0xBC/0xBE = 0xFFFF. Store reach 0xc4.
3. Allocation 0x710006f32c.
