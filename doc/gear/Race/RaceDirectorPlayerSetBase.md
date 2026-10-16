# RaceDirectorPlayerSetBase (gear::RaceDirectorPlayerSetBase)

- PROVISIONAL vtable-anchored name. Vtable 0x12c59b0 (GOT cell 0x130fee0), size 0x58.

Far-family gap member reclassified: the PRIMARY BASE of RaceDirectorPlayerSet. The factory ctor (0x710006eb5c) calls 0x7c2938 at offset 0 — it runs ctor 0x7b976c (RaceDirectorBase38), zeroes 0x38..0x57 and stores this vptr; the factory then overwrites the vptr with its own (0x12fbd48 cell) and starts its fields at 0x58.

Naming: base-subobject gap member (ctor 0x7c2938); identity from the derived factory ctor only. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero (child-array cursor); 0x3c unproven padding.
- 0x40 — ctor zero (child array base).
- 0x48 — ctor zero.
- 0x50 — ctor zero (child count).

## Construction / init order

1. Ctor 0x71007c2938: calls ctor 0x71007b976c (RaceDirectorBase38).
2. Zeroes 0x38..0x57.
3. Stores this vptr (vtable 0x12c59b0 via GOT cell 0x130fee0). Store reach 0x58.
