# RaceDirectorSetChild80 (gear::RaceDirectorSetChild80)

- PROVISIONAL vtable-anchored name. Abstract-style child director of RaceDirectorPlayerSet: ctor 0x710006ded4 (Actor base), vtable 0x11b4650 (GOT 0x12fbf88). Size 0x80 (factory alloc 0x6f184). Owner back-pointer at +0x58.

Naming: abstract-style child (ctor 0x6ded4, owner at +0x58); factory branch context only, no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zeroes 0x38-0x57.
- 0x58 — ctor arg x1 (the PlayerSet).
- 0x60 — ctor zeroes to 0x7F.

## Construction / init order

1. Ctor 0x710006ded4 with the Actor base; vtable 0x11b4650.
2. Zeroes 0x38-0x57; owner (arg x1) at +0x58; zeroes to 0x7F.
3. Factory allocation 0x6f184 (0x80).
