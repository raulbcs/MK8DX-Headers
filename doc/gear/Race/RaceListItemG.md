# RaceListItemG (gear::RaceListItemG)

- PROVISIONAL vtable-anchored name ("G"). Manager list item of the far race family (base chain 0x7ee400, NOT Actor). Vtable 0x11b9650 (GOT 0x12fcfe8). Ctor 0x710010adec; size 0xA10, proven by the allocation site 0x71003989cc. Registers into manager+0x218.

RECLASSIFIED: offsets 0x00-0x9AF are the primary base RaceListItemGBase (vtable 0x12c8f68, ctor 0x7ee400 — see RaceListItemGBase.md); this ctor overwrites the vptr and starts its own fields at 0x9B0. Kept flat in the header (the m108/m10C/m110 writes sit inside the base extent).

Naming: alloc 0xa10 at 0x3989cc inside the per-mode dispatcher, registered at mgr+0x218; no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x00 — vtable ptr; 0x08-0xFF unproven padding; 0x100 unproven gap.
- 0x108 — ctor sets 8; 0x10C — ctor sets 0xC; 0x110 — ctor sets 4 (all inside the base extent).
- 0x114-0x9AF — unproven padding (base region).
- 0x9B0-0x9C7 — ctor memset 0x48.
- 0x9C8/0x9D8/0x9E8/0x9F8 — ctor -1 (0xCC-strided with unproven padding between).
- 0xA00 — ctor zero; 0xA04 unproven.
- 0xA08 — ctor zero; 0xA09 unproven padding.

## Construction / init order

1. Allocation 0x71003989cc (0xA10) inside the per-mode dispatcher.
2. Ctor 0x710010adec calls 0x7ee400 (RaceListItemGBase, which runs 0x7b976c first), then overwrites the vptr (cell 0x12fcfe8).
3. Base-region writes 0x108=8 / 0x10C=0xC / 0x110=4 (u64 store covers 0x108..0x10f).
4. memset 0x48 at 0x9B0; -1 at 0x9C8/0x9D8/0x9E8/0x9F8; 0xA00 = 0; 0xA08 = 0.
5. Registration into manager+0x218.
