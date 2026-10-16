# RaceDirectorManagerBase (gear::RaceDirectorManagerBase)

- PROVISIONAL vtable-anchored name. Vtable 0x12c5638 (GOT cell 0x130fea8, holds vptr-0x10), size 0x68.

Far-family gap member reclassified: it is the PRIMARY BASE of RaceDirectorManager, not a member. The manager ctor (0x710005876c) calls 0x7b98bc at offset 0 — it runs ctor 0x7b976c (RaceDirectorBase38), zeroes 0x38..0x67 and stores this vptr; the manager then overwrites the vptr with its own and starts its fields at 0x68.

Naming: base-subobject gap member: identity is defined by the derived ctor 0x7b98bc alone; no consumer names it. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero (the child-array cursor); 0x3c unproven padding.
- 0x40 — ctor zero (child array base).
- 0x48/0x50/0x58/0x60 — ctor zero.

## Construction / init order

1. Ctor 0x71007b98bc: calls ctor 0x71007b976c (RaceDirectorBase38, zeroes 0x10..0x37, stores vptr cell 0x130fea0 -> vtable 0x12c55b8).
2. Zeroes 0x38..0x67.
3. Stores this vptr (vtable 0x12c5638 via GOT cell 0x130fea8).
