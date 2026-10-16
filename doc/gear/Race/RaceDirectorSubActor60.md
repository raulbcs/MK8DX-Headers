# RaceDirectorSubActor60 (gear::RaceDirectorSubActor60)

- PROVISIONAL vtable-anchored name. The first sub-actor RaceDirector creates at +0x60 (ctor 0x7100066448, base 0x7b9a18). Size 0xB0, proven by the allocation site inside the RaceDirector ctor (0x4d8c0 `mov w0,#0xb0`). Vtable 0x11b41c8 (GOT 0x12fbeb0). Owns one same-size child (ctor 0x66ba8) registered in its own child array.

Naming: RaceDirector child at +0x60 (ctor 0x66448, size 0xB0); parent ctor is the only consumer; no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — child array pattern (count/array/cursor), registered by RaceDirector ctor.
- 0x60 — new(0xB0), ctor 0x66ba8 (RaceDirectorSubActor60Child).
- 0x68 — to 0xB0 (unproven).

## Construction / init order

1. Allocation 0x4d8c0 (`mov w0,#0xb0`) inside the RaceDirector ctor.
2. Ctor 0x7100066448 (base 0x7b9a18 -> Actor); vtable 0x11b41c8.
3. Child at 0x60: new(0xB0), ctor 0x66ba8, registered in this class's own child array.
