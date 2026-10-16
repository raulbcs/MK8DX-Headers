# RaceDirectorSetChildActor80 (gear::RaceDirectorSetChildActor80)

- PROVISIONAL vtable-anchored name. Fallback child director of RaceDirectorPlayerSet: ctor 0x710006e5e0 (Actor base), vtable 0x11b46d8 (GOT 0x12fbf90). Size 0x80 (factory alloc 0x6f12c; used in the fallback dispatch branch). Owner back-pointer at +0x58.

Naming: fallback child ctor 0x6e5e0; only the factory branch 0x6f12c names nothing. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zeroes 0x38-0x57.
- 0x58 — ctor arg x1.
- 0x60 — zeroes to 0x7F.

## Construction / init order

1. Ctor 0x710006e5e0 with the Actor base; vtable 0x11b46d8.
2. Zeroes 0x38-0x57; owner (arg x1) at +0x58; zeroes to 0x7F.
3. Factory allocation 0x6f12c (0x80) — the fallback dispatch branch.
