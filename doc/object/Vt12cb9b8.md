# object::Vt12cb9b8

PLACEHOLDER name (identity not proven). vptr 0x12cb9b8, 14 slots, typeinfo NULL.
GOT cell 0x1310860 holds vptr-0x10 (0x12cb9a8). Not gear::Actor-derived (no Actor
base call, no accept/prepareOuter tail). Pooled object: the vptr is installed onto
an object taken from a manager pool, not by a C1.

## Member notes

- Init FUN_71006b5e2c (0x92 bytes) writes: [+0x20..+0x2F]=0, [+0x30] h=0, [+0x32] b=0,
  [+0x33] b=1, [+0x300] u32=0, [+0x308]=0, [+0x310] h=0, [+0x314] s32=-1.
- size: lower bound 0x318 from the deepest store (+0x314). Pool element size
  unverified — no direct allocation located (elements come from the manager array
  at [mgr+0x168], FUN_71006ad048 0x6ad060).

## Construction / init order

- Site 0x8297ec (function containing it): FUN_71006ad048(mgr, idx, ...) fetches the
  pooled object -> FUN_71006b5e2c(obj) initializes it -> `[obj] = 0x12cb9b8`
  (0x829808) -> FUN_71006ad110 finishes the setup. Second caller of the fetch:
  0x6f7904.
- Slots: 0/1 FUN_7100828e14/FUN_7100828e18 (unrecovered, likely D1/D0 pair),
  2 FUN_71006b5f80, 3 FUN_71006b6c50, 4 FUN_71006b609c, 5 FUN_71006b60bc,
  6 FUN_71006b6c58, 7 FUN_71006b6c78, 8 FUN_71006b68f0, 9 FUN_71006b68b8,
  10 FUN_71006b6ca4, 11 FUN_71006b612c, 12 FUN_71006b676c, 13 FUN_7100828e3c
  (unrecovered).
- Unrelated: the nearby singleton at 0x829830 (guard cell 0x1310868) constructs a
  static object with vptr 0x12cbd80 (GOT cell 0x1310870) at 0x135b588 — different
  class, do not confuse.
