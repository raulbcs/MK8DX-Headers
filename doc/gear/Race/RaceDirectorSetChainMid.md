# RaceDirectorSetChainMid (gear::RaceDirectorSetChainMid)

- PROVISIONAL vtable-anchored name. Mid layer (ctor 0x71000628bc, vtable 0x11b3fd8 / GOT 0x12fbe50). Size 0xF8 (factory alloc 0x6f1d8). Adds zeros at 0xE0-0xEF.

Naming: mid layer ctor 0x628bc only zeroes fields; no name evidence. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0xC0 — unproven padding (0x20 bytes).
- 0xE0/0xE4/0xE8/0xEC/0xEF — ctor zero; 0xEE unproven gap.
- 0xF0 — unproven padding. Total 0xF8.

## Construction / init order

1. Ctor 0x71000628bc (base: RaceDirectorSetChain 0x710005f558 -> Actor).
2. Zeros at 0xE0-0xEF (0xEE gap).
3. Factory allocation 0x6f1d8 (0xF8).
