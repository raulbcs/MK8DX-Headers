# RaceDirectorSetChain (gear::RaceDirectorSetChain)

- PROVISIONAL vtable-anchored name. Base of the second PlayerSet dispatch chain (0x61514/0x620a0 derive from 0x628bc, which derives from this): ctor 0x710005f558 (Actor base), secondary vptr at +0x38 (GOT 0x12fbe00), zeroes 0x40-0xD8, sets [0x40]=0x01000000, [0xB0]=-1, owner at +0x90. Size unproven (< 0xF8).

Naming: secondary-vptr chain base (0x628bc); consumers are the factory branches only; no binary name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — secondary vptr (GOT 0x12fbe00).
- 0x40 — ctor sets 0x01000000.
- 0x44-0x8F — unproven padding.
- 0x90 — ctor arg x1 (owner).
- 0x98-0xAF — unproven padding.
- 0xB0 — ctor -1.
- 0xB4-0xBF — unproven padding.

## Construction / init order

1. Ctor 0x710005f558 with the Actor base.
2. Secondary vptr stored at +0x38 (GOT 0x12fbe00).
3. Zeroes 0x40-0xD8; [0x40] = 0x01000000; owner (arg x1) at +0x90; [0xB0] = -1.
