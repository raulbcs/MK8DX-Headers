# RaceDirectorBase38 (gear::RaceDirectorBase38)

- PROVISIONAL vtable-anchored name. 0x38 POD base of the small far-family classes.

Ctor 0x71007b976c (zeroes 0x10..0x37 only, NO Actor/sead chain call) stores vptr cell 0x130fea0 (+0x10 -> vtable 0x12c55b8). Every far-family class whose ctor calls 0x7b976c derives this: RaceDirectorManagerBase (0x7b98bc), RaceDirectorPlayerSetBase (0x7c2938), RaceDirectorPlayerBase (0x7c2a90), RaceListItemG's base (0x7ee400), and the three singletons 0x12601e8 (0x3995d4), 0x12c5758 (0x7b9a2c), 0x12ca260 (0x7fd3d4).

Naming: 0x38 POD base with no vtable slots beyond slot 0; identity is purely structural (shared ctor 0x7b976c). Nothing in-binary to baptize. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x00 — vtable ptr (cell 0x130fea0); 0x08 untouched by ctor.
- 0x10/0x18/0x20/0x28/0x30 — ctor zero.

## Construction / init order

1. Ctor 0x71007b976c: zeroes 0x10..0x37 (no Actor/sead chain call), stores vptr cell 0x130fea0 (+0x10 -> vtable 0x12c55b8). Store reach 0x38.
