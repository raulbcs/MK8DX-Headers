# RaceDirectorSetStatePod (gear::RaceDirectorSetStatePod)

- PROVISIONAL vtable-anchored name. 0x3C-byte POD state record (ctor 0x71000585c4, NO vtable). Two instances per RaceDirectorPlayerSet (at +0xB8 and +0xC0; the second is also stored into [[set+0xB0]+0x78], i.e. shared with the RaceDirectorSetLanePool child). Carries a hardcoded 0.25f ratio at +0x24.

Naming: POD state record (ctor 0x585c4, 0.25f ratio); two instances per PlayerSet; no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x00 — ctor zeroes 0x00-0x1F.
- 0x20 — ctor zero.
- 0x24 — ctor sets 0.25f.
- 0x28/0x2C/0x30/0x38 — ctor zero; 0x2E/0x34 unproven padding.

## Construction / init order

1. Ctor 0x71000585c4: zeroes 0x00-0x1F, 0x20 = 0, 0x24 = 0.25f, zeros at 0x28/0x2C/0x30/0x38. Store reach 0x3c.
2. Instantiated twice per RaceDirectorPlayerSet at +0xB8 and +0xC0 (0x6f3dc: new(0x3C)); the second instance is also stored into [[set+0xB0]+0x78].
