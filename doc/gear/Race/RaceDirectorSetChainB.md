# RaceDirectorSetChainB (gear::RaceDirectorSetChainB)

- PROVISIONAL vtable-anchored name. Chain variant (ctor 0x71000620a0, vtable 0x11b3e48 / GOT 0x12fbe38). Size 0x110 (factory alloc 0x6ee28). Seeds a limit of 30 at +0xFC.

Naming: chain variant: ctor 0x620a0 plus slot reading [this+0x78]->+0x28c (RaceInfo-adjacent); no rodata name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0xF8 — ctor zero.
- 0xFC — ctor sets 30 (0x1E).
- 0x100-0x108 — ctor zeroes (+0x104 skipped).
- 0x109 — unproven padding. Total 0x110.

## Construction / init order

1. Ctor 0x71000620a0 (base chain: RaceDirectorSetChainMid 0x71000628bc -> RaceDirectorSetChain 0x710005f558 -> Actor).
2. 0xF8 = 0; 0xFC = 30 (0x1E); zeroes 0x100-0x108 (+0x104 skipped).
3. Factory allocation 0x6ee28 (0x110).
