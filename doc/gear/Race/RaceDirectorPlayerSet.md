# RaceDirectorPlayerSet (gear::RaceDirectorPlayerSet)

- PROVISIONAL vtable-anchored name ("C"). Vtable 0x11b4810 (GOT 0x12fbfd8, cell holds vptr-0x10), ctor 0x710006eb5c, secondary vtable 0x11b3c78 at +0x58. Size 0xD0 (allocated by RaceDirectorPlayer ctor 0x70e5c).

Per-player child-director set/factory: the 0x7c2938 call is the primary base RaceDirectorPlayerSetBase (vtable 0x12c59b0, size 0x58 — see RaceDirectorPlayerSetBase.md); this ctor overwrites the vptr at 0 and starts its own fields at 0x58.

Builds ~17 child directors (alloc -> ctor -> register at the 0x38/0x40/0x4C cursor -> store into a set field), dispatching on getRaceCheckManager [x0+8]/[x0+0xc] == 3. Named fields hold the RaceDirectorVt* chain members.

Naming: factory ctor 0x6eb5c builds ~17 child directors dispatching on RaceStateChecker flags; no rodata name, no method-tree entry. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38-0x4F — child array pattern.
- 0x50 mHelper50 — new(0x40), ctor 0x689c8 (RaceDirectorSetHelper).
- 0x58 — secondary vptr (0x11b3c78).
- 0x60 — ctor 0, later 6; 0x61 unproven gap.
- 0x62 — ctor 0. 0x63 — ctor 1. 0x64 — ctor 0; 0x65-0x67 unproven gap.
- 0x68 mChild68 — self (0x6f3fc).
- 0x70/0x78/0x80 — alloc(0x60) via 0x60b04c (member-offset table entries {offset,1} for 0xc8-0x120, 0x6f4a8+).
- 0x88 — unproven padding.
- 0x90 mChain90 — RaceDirectorSetChainA ctor 0x61514 (alloc 0x100 @0x6ed40); also Vt2 0x4e2f4 (0x6f11c).
- 0x98-0xA7 — unproven padding.
- 0xA8 — director chain members (0x6ed4c: ctor 0x61514, alloc 0x100; also 0x511a8->Vt5 @0x6f338, 0x702e0 @0x6f388, 0x628bc @0x6f1e4).
- 0xB0 mB0 — new(0xA8), ctor 0x702e0 (0x6f388) (RaceDirectorSetLanePool); the Vt3/Vt4/Vt6/Vt7 ctors (0x6eda0/0x6ee88/0x6ef70/0x6f074) dispatch into the chain fields instead.
- 0xB8 mB8 — new(0x3C), ctor 0x585c4 (0x6f3dc) (RaceDirectorSetStatePod).
- 0xC0 mC0 — second POD; also stored into [[set+0xb0]+0x78].
- 0xC8-0xCF — unproven padding; 0xD0 unproven gap.

Also: plain RaceDirector instance (0x4d7d8, alloc 0x90 @0x6f244), Vt2 (0x6f11c), 0x6e9d0/0x6ded4/0x620a0/0x6e5e0 members. Total 0xD0.

## Construction / init order

1. Allocation 0x6f244-family: RaceDirectorPlayer ctor 0x70e5c allocates 0xD0.
2. Ctor 0x710006eb5c; first call 0x7c2938 (primary base RaceDirectorPlayerSetBase, vtable 0x12c59b0); ctor then overwrites the vptr at 0.
3. mHelper50 (0x50): new(0x40), ctor 0x689c8.
4. Child director build loop (~17 children): alloc -> ctor -> register at the 0x38/0x40/0x4C cursor -> store into a set field; dispatch on getRaceCheckManager [x0+8]/[x0+0xc] == 3.
5. Chain members: 0x6f11c (Vt2 0x4e2f4, alloc 0x100 @0x6ed40, ctor 0x61514), 0x6ed4c, 0x6f338 (0x511a8->Vt5), 0x6f388 (0x702e0), 0x6f1e4 (0x628bc), 0x6f3dc (new(0x3C), ctor 0x585c4), 0x6f3fc (self at 0x68), 0x6f4a8+ member-offset table entries {offset,1} for 0xc8-0x120 via 0x60b04c; Vt3/Vt4/Vt6/Vt7 ctors 0x6eda0/0x6ee88/0x6ef70/0x6f074 dispatch into the chain fields.
6. Constants: 0x60=0 (later 6), 0x62=0, 0x63=1, 0x64=0.
