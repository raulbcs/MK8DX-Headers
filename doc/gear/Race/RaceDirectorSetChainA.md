# RaceDirectorSetChainA (gear::RaceDirectorSetChainA)

- PROVISIONAL vtable-anchored name. Chain variant (ctor 0x7100061514, vtable 0x11b3c98 / GOT 0x12fbe18). Size 0x100 (factory allocs 0x6ed40/0x6ef10/0x6f00c/0x6f2d8).

Naming: chain variant: four factory allocs (0x6ed40/0x6ef10/0x6f00c/0x6f2d8) and no strings anywhere in the unit; behavior unmapped beyond the ctor. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0xF8 — ctor zero; list/map head. Total 0x100.

## Construction / init order

1. Ctor 0x7100061514 (base chain: RaceDirectorSetChainMid 0x71000628bc -> RaceDirectorSetChain 0x710005f558 -> Actor).
2. 0xF8 = 0.
3. Factory allocations: 0x6ed40/0x6ef10/0x6f00c/0x6f2d8 (0x100 each).
