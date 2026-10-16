# RaceListItemGBase (gear::RaceListItemGBase)

- PROVISIONAL vtable-anchored name. Vtable 0x12c8f68 (GOT cell 0x1310240), far-family gap member reclassified: the PRIMARY BASE of RaceListItemG, not a member. Ctor 0x71007ee400 (called at offset 0 by the RaceListItemG ctor 0x710010adec; it runs ctor 0x71007b976c = RaceDirectorBase38 first and stores this vptr; the derived ctor then overwrites the vptr with its own, cell 0x12fcfe8). Extent 0x9b0 — the derived ctor starts its own fields at 0x9b0 (memset 0x48 + the -1/ptr block), so the base is 0x9b0 of the 0xa10 total. (The out-of-line copy at 0x878f94 belongs to RaceDirectorVt10's graph, not to this class.)

Naming: 0x9b0 base-subobject gap member (ctor 0x7ee400); identity from the derived ctor only. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero; 0x3c unproven padding.
- 0x40/0x48/0x58/0x60/0x68 — ctor zero.
- 0x50 — ctor sets -1; 0x54 unproven padding.
- 0x70 mSub70 — embedded member (secondary vptr, cell 0x12fada0; ctor 0x710061cc48; field 0x80 set to 0x80 by the ctor).
- 0x78 mNode78 — self node head (set to this+0x84); 0x80 unproven padding.
- 0x84 mNode84 — node body reached by the back-ptr (0x24 bytes).
- 0xa8 — unproven padding (to 0x108).
- 0x108 — written by the DERIVED ctor (0x80000008; the ctor's u64 store covers 0x108..0x10f = this + m10c).
- 0x10c — derived ctor sets 0xc; 0x110 — derived ctor sets 4; 0x114 unproven padding.
- 0x118-0x9AF — untouched by the ctors (to 0x9b0).

## Construction / init order

1. Ctor 0x71007ee400 runs ctor 0x71007b976c (RaceDirectorBase38).
2. Stores this vptr (vtable 0x12c8f68 via GOT cell 0x1310240).
3. Zeros at 0x38/0x40/0x48/0x58/0x60/0x68; 0x50 = -1.
4. Embedded member at 0x70: ctor 0x710061cc48, secondary vptr from cell 0x12fada0, field +0x80 set to 0x80.
5. 0x78 = this+0x84 (self node head).
6. The derived ctor (0x710010adec) then writes 0x108/0x10c/0x110 and overwrites the vptr.
