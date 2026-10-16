# RaceDirectorPlayer (gear::RaceDirectorPlayer)

- PROVISIONAL vtable-anchored name ("P"). Vtable 0x11b4a40 (GOT 0x12fc060), ctor 0x7100070cb4, size 0x2B0 (allocation site 0x7100058c60).

Per-player director: constructed in a loop by RaceDirectorManager (one per player, w1 = player index), registered in the manager's child array and vector. Owns the per-player director-set factory (RaceDirectorPlayerSet) at +0x50. The ctor's first call (0x7c2a90) is the primary base RaceDirectorPlayerBase (vtable 0x12c5a88, size 0x58 — see RaceDirectorPlayerBase.md); this ctor overwrites the vptr at 0 and starts its own fields at 0x58.

Naming: one-per-player construction loop in RaceDirectorManager (0x58c60 news 0x2B0); behavior is clear, a binary name is not. MethodTree has no entry. The ELF carries no name for this class (strings and the method-tree registrations at 0x6327a8 cover only graphics/profiling and the MapObjBase::calc*-family entries; custom-RTTI predicates hold no name string), so the name stays PROVISIONAL.

## Fields

- 0x38-0x4F — child array pattern (count=1).
- 0x50 mSet50 — new(0xD0), ctor 0x6eb5c (at 0x70eac).
- 0x58 mObj58 — new(0x38) named object (vptrs 0x11b4bf8 / 0x11ad210; string 0x7100ed6af8, cb 0x70f9c).
- 0x60 mParent60 — ctor arg x2 (the RaceDirectorManager).
- 0x68 mPtr68 — [[set+0xb0]+0x60].
- 0x70 mRaceInfo70 — RaceInfo walk: [0x7f7ac0]->[+0x190+idx*8, clamp<0xa]->[+0x218]->[+0x58].
- 0x78 mRaceCheck78 — if getRaceCheckManager[+8]==3: 0x24e70(playerIdx) race-check object.
- 0x80-0x87 — unproven padding.
- 0x88 mObj88 — alloc(0x60) + ctor 0x14186c(playerIdx).
- 0x90 mObj90 — 0x142498 result.
- 0x98-0xA7 — unproven padding.
- 0xA8 — ctor sets 2; 0xAC-0xB3 unproven padding.
- 0xB4 — ctor sets -1; 0xB8-0xBB unproven padding.
- 0xBC — ctor sets -1; 0xC0 unproven gap.
- 0xC4 — ctor zero.
- 0xC8 — ctor -1; final vcall on parent slot 0xc8 (w1=0xc).
- 0xCC — ctor -1.
- 0xD0 — ctor sets 1000; 0xD4-0xE7 unproven padding.
- 0xE8 — ctor sets 30; 0xE9-0xF7 unproven padding.
- 0xF8-0x22B — 0xF8/+0x118/+0x12C are self-referencing member heads (ctor 0x70d40/0x70d64); rest unproven.
- 0x22C — copied from the [0x12fb148] global pair.
- 0x230/0x232 — ctor 0xFFFF; 0x234 zero; 0x236-0x297 unproven padding.
- 0x298 — ctor zero.
- 0x29C — copied from the [0x12fb148] global pair.
- 0x2A0-0x2AF — unproven padding.

## Construction / init order

1. Ctor 0x7100070cb4; first call 0x7c2a90 (primary base RaceDirectorPlayerBase, vtable 0x12c5a88); ctor then overwrites the vptr at 0 (GOT 0x12fc060).
2. 0x70eac: mSet50 (0x50) = new(0xD0), ctor 0x6eb5c.
3. mObj58 (0x58): new(0x38), cb 0x70f9c.
4. mRaceCheck78 (0x78): 0x24e70(playerIdx) when getRaceCheckManager[+8]==3.
5. mObj88 (0x88): alloc(0x60), ctor 0x14186c(playerIdx); mObj90 (0x90) = 0x142498 result.
6. Self-referencing member heads at 0xF8/+0x118/+0x12C: 0x70d40/0x70d64.
7. Constants and copies: 0xA8=2, 0xB4=-1, 0xBC=-1, 0xC4=0, 0xC8/0xCC=-1, 0xD0=1000, 0xE8=30, 0x230/0x232=0xFFFF, 0x22C/0x29C from [0x12fb148], 0x298=0; final vcall on parent slot 0xc8 (w1=0xc).
