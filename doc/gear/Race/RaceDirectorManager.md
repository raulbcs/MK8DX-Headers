# RaceDirectorManager (gear::RaceDirectorManager)

- PROVISIONAL vtable-anchored name ("A" in the hierarchy pass). Vtable 0x11b3808 (GOT 0x12fbd40), typeinfo 0x58568 (predicate on this+0x9c). Ctor 0x710005876c; size 0x1A0, proven by the allocation site 0x710013d994.

Ctor 0x7b98bc is NOT the Actor chain: it is RaceDirectorManagerBase (vtable 0x12c5638, size 0x68 — see RaceDirectorManagerBase.md); this class overwrites the vptr at offset 0 and starts its own fields at 0x68. Kept flat in the header (the named 0x08/0x50/0x58 fields sit inside the base extent, written by this ctor). The class reuses the child-array pattern 0x38/0x40/0x4C.

Top-level race director manager: owns the per-player directors (RaceDirectorPlayer) and ~14 per-player data tables.

Naming: consumers: allocation site 0x13d994 and the per-player loop 0x58c44-0x58cd8; the class owns the per-player RaceDirectorPlayer vector, but no string or method-tree entry names it. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x00 — vtable ptr (ctor 0x5879c).
- 0x08 mObj8 — object built by 0x62ee28.
- 0x10 — unproven padding.
- 0x50 mTable50 — new(0x59C0) via ctor 0x66940 (at 0x58bd4).
- 0x58/0x5C — per-player director vector: the loop (0x58c44-0x58cd8); the bound is loaded from [this+0x5C]; 0x58/0x5C form a non-8-aligned pair — declared as raw u32s.
- 0x60 mVec60 — vector end/cap.
- 0x68 — unproven padding.
- 0x90 mObj90 — ctor writes (0x588c0 region).
- 0x98 — slot 0x98 guards on this+0x68: when set, runs the callee at 0x710005a01c, then dispatches 0x710005a1e0 with flag 1 (slot98_dispatch_7100059fe8). Slots 0xa0/0xa8 are tails of FUN_710005a1e0 — same dispatch, other flag values. 0x98-0xAB unproven padding (slot-0x98 dispatch region).
- 0xAC mFieldAc — ctor writes.
- 0xB0 — unproven padding.
- 0xC0-0x197 — ~14 allocated arrays (0x60b3fc + memset 0xb52770), per-player data tables (ctor 0x58d7c-0x59244); unproven gap.
- 0x198 — unproven padding. Total 0x1A0.

## Construction / init order

1. Ctor 0x710005876c; vptr stored by ctor 0x5879c.
2. Base ctor 0x7b98bc (RaceDirectorManagerBase): calls ctor 0x7b976c (RaceDirectorBase38), zeroes 0x38..0x67, stores vtable 0x12c5638; the manager then overwrites the vptr.
3. mObj8 (0x08): built by 0x62ee28.
4. mTable50 (0x50): new(0x59C0) via ctor 0x66940 (0x58bd4).
5. mObj90 (0x90): ctor writes, 0x588c0 region.
6. mFieldAc (0xAC): ctor writes.
7. 0xC0..0x198: ~14 allocated arrays, 0x60b3fc + memset 0xb52770 (ctor 0x58d7c-0x59244).
8. Allocation proof: 0x710013d994.
