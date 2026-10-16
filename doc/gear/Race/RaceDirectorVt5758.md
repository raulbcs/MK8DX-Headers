# RaceDirectorVt5758 (gear::RaceDirectorVt5758)

- PROVISIONAL vtable-anchored name (vptr 0x12c5758, GOT cell 0x130feb0). Far-family singleton: ctor 0x71007b9a2c (in the 0x71007b98bc lazy-init region). Extent 0xae; size 0xb0.

Base: ctor 0x71007b976c (RaceDirectorBase38). After the base, the ctor zeroes 0x40..0x7f, stores 1 at 0x84, a pair from the global object [0x12fb168] at 0x8c/0x94, zeros to 0xad, and builds a dynamic array at 0x40 plus three members at 0x68 (new 0x18, ctor 0x71007c27bc), 0x70 (new 0x18, ctor 0x71007c27bc) and 0x78 (new 0x70, virtual factory on arg x20 + init 0x71007c55cc).

Naming: lazy singleton in the 0x7b98bc init region; consumers unexamined beyond the ctor; no name. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38 — ctor zero, set to 1 after the array allocation succeeds; 0x3c unproven padding.
- 0x40 — new[] of [global 0x12fb168]+8 entries, zero-filled loop.
- 0x48 — unproven gap; 0x4c — ctor zero; 0x50 — unproven padding; 0x60 — unproven gap.
- 0x68 — new(0x18), ctor 0x71007c27bc.
- 0x70 — new(0x18), ctor 0x71007c27bc.
- 0x78 — new(0x70), virtual factory on the ctor arg + init 0x71007c55cc.
- 0x80 — ctor zero; 0x81 unproven padding.
- 0x84 — ctor sets 1.
- 0x8c/0x94 — copied from [global 0x12fb168] / [global+8].
- 0x98/0x9c — ctor zero; 0x9e unproven padding.
- 0xa0 — ctor zeroes 0xa0..0xad (two overlapping stores: u64 @0xa0, unaligned u64 @0xa6).
- 0xae — unproven gap. Total 0xb0, binary extent 0xae.

## Construction / init order

1. Ctor 0x71007b9a2c runs base ctor 0x71007b976c (RaceDirectorBase38).
2. Zeroes 0x40..0x7f.
3. Dynamic array at 0x40: new[] of [global 0x12fb168]+8 entries, zero-filled loop; 0x38 set to 1 after it succeeds.
4. 0x68: new(0x18), ctor 0x71007c27bc.
5. 0x70: new(0x18), ctor 0x71007c27bc.
6. 0x78: new(0x70), virtual factory on the ctor arg x20 + init 0x71007c55cc.
7. 0x84 = 1; 0x8c/0x94 pair from [0x12fb168]; zeros to 0xad.
