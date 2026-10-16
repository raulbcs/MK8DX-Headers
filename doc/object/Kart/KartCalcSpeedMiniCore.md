# KartCalcSpeedMiniCore

## Identity

Kart speed calculation runtime, "mini core" variant. Vtable .data
0x124d0e8 (GOT cell 0x1306390 region), ctor 0x710034d2d8, size 0x300
(allocation 0x300 at 0x34d1ac — a clone path in FUN_7100034d070; the
primary allocation in FUN_7100034c620 is larger: its derived ctor
0x34c640 re-runs after the base ctor and rewrites vtables at 0x0/0x38/
0x128/0x208 from 0x1306398 and owns the derived tail fields
0x300..0x357, not covered by this base-class header). Slot names carry
KartCalcSpeed_mini_core_710034b558 evidence.

## Member notes

Notes in field order; proven from the cited addresses.

- 0x8 — sead::hostio::Node base members (see gear/Actor/Actor.hpp: Node supplies 0x08..0x30; base ctor 0x1a1ec4)
- 0x38 — ctor: [0x13063a0]+0x2a8 secondary vtable (0x34d31c); rewritten by the derived ctor to [0x1306398]+0x2e0 (0x34c65c)
- 0x40 — unproven gap; ctor passes this+0x90 as arg to the container init 0x803d24 (0x34d328)
- 0x128 — ctor: [0x13063a0]+0x340 secondary vtable (0x34d320); rewritten by the derived ctor to [0x1306398]+0x378 (0x34c66c)
- 0x130 — unproven gap
- 0x138 — pointer: copied wholesale into the 0x300 clone created by FUN_7100034d070 (ldp 0x34d1b0, stp 0x34d1b8)
- 0x140 — pointer, same clone copy (0x34d1b0/0x34d1b8)
- 0x148 — unproven gap
- 0x1F8 — ctor: 0x133c7b0 (static table 0x133c790, 0x34d3f4-0x34d408)
- 0x200 — ctor: 0x133c798 (0x34d408)
- 0x208 — ctor: [0x13063a0]+0x370 secondary vtable (0x34d324); rewritten by the derived ctor to [0x1306398]+0x3a8 (0x34c6a4); passed as arg to the container init 0x803d24 (0x34d300/0x34d328)
- 0x210 — unproven gap (no ctor write, no located access)
- 0x260 — ctor: [0x13063a8]+0x10 vtable (0x34d388)
- 0x268 — ctor 2 (0x34d410); loop bound vs 3 at 0x34d468
- 0x269 — ctor zero
- 0x26a — ctor zero
- 0x26b
- 0x26c — ctor zero
- 0x270 — ctor stores `this`
- 0x278 — ctor: new[](0x20) array, zeroed 32B (0x34d424-0x34d460)
- 0x280 — ctor: new[](0x20) array, zeroed 32B
- 0x288 — ctor: call result (new[](0x20) at 0x34d43c, zeroed 32B + up to [0x268] slots at 0x34d478)
- 0x290 — ctor zero (0x34d374); read as flag arg by FUN_7100034d070 → 0x34e7e8 (0x34d0dc-0x34d0e4)
- 0x291 — untouched by ctor; no located access
- 0x298 — ctor: [0x12fb038]+0x10 (0x34d35c-0x34d390)
- 0x2a0 — ctor zero (0x34d378)
- 0x2a8 — ctor zero (0x34d37c)
- 0x2a9 — untouched by ctor; no located access
- 0x2b0 — ctor constant 0x437a0000 = 250.0f (0x34d380)
- 0x2b4 — ctor zero (0x34d39c)
- 0x2b8 — ctor zero (0x34d3a0)
- 0x2bc — ctor zero (str 1<<32 at 0x34d3a4 covers 0x2bc/0x2c0)
- 0x2c0 — ctor 1 (same store, 0x34d3a4)
- 0x2c4
- 0x2c8
- 0x2c9 — ctor zero (strh wzr at 0x34d3b0 covers 0x2c8/0x2c9)
- 0x2ca — ctor zero (0x34d3ac); read by FUN_7100034d070 (0x34d17c) and passed to a new 0x280-byte object stored at its +0x278 (0x34d134/ 0x34d150)
- 0x2cb — untouched by ctor; no located access
- 0x2cc — ctor copy of *(void**)0x12fb0148 (0x34d398- 0x34d3c4); sibling copies below read the same cell
- 0x2d4
- 0x2d8
- 0x2e0
- 0x2e4 — ctor copy of *(void**)0x12fb0148 (0x34d3e4- 0x34d3e8); [0x2e8] is the element count for the 0x2f0 child array (reads 0x34b590/0x34b5b4/ 0x34b654/0x34b6b0)
- 0x2ec
- 0x2f0
- 0x2f8
- 0x2FC — untouched by ctor 0x34d2d8 and by the derived ctor 0x34c640 (writes only 0x300+); no located access; end padding to the 0x300 allocation size

## Construction / init order

In field/offset order (= binary init order within this header):
- 0x8 — sead::hostio::Node base members (see gear/Actor/Actor.hpp: Node supplies 0x08..0x30; base ctor 0x1a1ec4)
- 0x38 — ctor: [0x13063a0]+0x2a8 secondary vtable (0x34d31c); rewritten by the derived ctor to [0x1306398]+0x2e0 (0x34c65c)
- 0x40 — unproven gap; ctor passes this+0x90 as arg to the container init 0x803d24 (0x34d328)
- 0x128 — ctor: [0x13063a0]+0x340 secondary vtable (0x34d320); rewritten by the derived ctor to [0x1306398]+0x378 (0x34c66c)
- 0x1F8 — ctor: 0x133c7b0 (static table 0x133c790, 0x34d3f4-0x34d408)
- 0x200 — ctor: 0x133c798 (0x34d408)
- 0x208 — ctor: [0x13063a0]+0x370 secondary vtable (0x34d324); rewritten by the derived ctor to [0x1306398]+0x3a8 (0x34c6a4); passed as arg to the container init 0x803d24 (0x34d300/0x34d328)
- 0x210 — unproven gap (no ctor write, no located access)
- 0x260 — ctor: [0x13063a8]+0x10 vtable (0x34d388)
- 0x268 — ctor 2 (0x34d410); loop bound vs 3 at 0x34d468
- 0x269 — ctor zero
- 0x26a — ctor zero
- 0x26c — ctor zero
- 0x270 — ctor stores `this`
- 0x278 — ctor: new[](0x20) array, zeroed 32B (0x34d424-0x34d460)
- 0x280 — ctor: new[](0x20) array, zeroed 32B
- 0x288 — ctor: call result (new[](0x20) at 0x34d43c, zeroed 32B + up to [0x268] slots at 0x34d478)
- 0x290 — ctor zero (0x34d374); read as flag arg by FUN_7100034d070 → 0x34e7e8 (0x34d0dc-0x34d0e4)
- 0x291 — untouched by ctor; no located access
- 0x298 — ctor: [0x12fb038]+0x10 (0x34d35c-0x34d390)
- 0x2a0 — ctor zero (0x34d378)
- 0x2a8 — ctor zero (0x34d37c)
- 0x2a9 — untouched by ctor; no located access
- 0x2b0 — ctor constant 0x437a0000 = 250.0f (0x34d380)
- 0x2b4 — ctor zero (0x34d39c)
- 0x2b8 — ctor zero (0x34d3a0)
- 0x2bc — ctor zero (str 1<<32 at 0x34d3a4 covers 0x2bc/0x2c0)
- 0x2c0 — ctor 1 (same store, 0x34d3a4)
- 0x2c9 — ctor zero (strh wzr at 0x34d3b0 covers 0x2c8/0x2c9)
- 0x2ca — ctor zero (0x34d3ac); read by FUN_7100034d070 (0x34d17c) and passed to a new 0x280-byte object stored at its +0x278 (0x34d134/ 0x34d150)
- 0x2cb — untouched by ctor; no located access
- 0x2cc — ctor copy of *(void**)0x12fb0148 (0x34d398- 0x34d3c4); sibling copies below read the same cell
- 0x2e4 — ctor copy of *(void**)0x12fb0148 (0x34d3e4- 0x34d3e8); [0x2e8] is the element count for the 0x2f0 child array (reads 0x34b590/0x34b5b4/ 0x34b654/0x34b6b0)
- 0x2FC — untouched by ctor 0x34d2d8 and by the derived ctor 0x34c640 (writes only 0x300+); no located access; end padding to the 0x300 allocation size
