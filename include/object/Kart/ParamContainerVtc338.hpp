#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtc338 — address-anchored name (vptr 0x12bc338, GOT cell
// 0x130e660). Large container of the 0x647f40 hook-band cluster
// (param-cache super-family ring): n=25 slots, allocation
// 0x370 at site 0x712cac. Shares the trivial hook band
// 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare; compare 0x7100647f6c (paramNodeSharedTypeIdEquals) is slot 0x50 shared by 61 ParamNode vtables).
// Own fields mapped from the inlined construction at the quoted site
// (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
// Vtable slot facts :
// - Slot 10 (0x60): one-time-guarded static singleton getter. Guard cell
//   0x71012fd3c8; instance cell 0x71012fd3d8 initialised to
//   [0x71012fd3d0]+0x10; returns the instance pointer.
//   true function size 0x5c bytes (gap-split artifact).
//   [paramContainerVtc338StaticInstanceSlot10_7100712e64.cpp]
// Vtable slot facts :
// slot 24 (vt+0xd0) = spot light update (light node *(self+0x358), id +0x360,
// angle accumulators +0x364/0x368, mask +0x36c; hue/palette modes on
// *(lt+0x290)); slot 32 (vt+0x210) = byte-identical masked variant (light ptr
// +0x470, id +0x478, mask +0x484; 5 differing insns total).
class ParamContainerVtc338 {
 public:
  void* vtable;           // 0x00
  uint8_t mPad8[0x28];    // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];    // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0x2f8];  // 0x38 — array/body region — unproven gap
  uint8_t mPad330[0x8];   // 0x330 — inner vptr (ctor-written)
  uint8_t mPad338[0x28];  // 0x338 — ctor-zeroed region (0x338-0x350 qword-zeroed)
  uint8_t mPad360[0x2];   // 0x360 — u16 count/flag — ctor-written
  uint8_t mPad362[0x2];   // 0x362 — unproven gap
  uint8_t mPad364[0x4];   // 0x364 — ctor-zero
  uint8_t mPad368[0x4];   // 0x368 — unproven gap
  uint8_t mPad36c[0x2];   // 0x36c — u16 — ctor-written
  uint8_t mPad36e[0x2];   // 0x36e — u16 — ctor-zero
                          // (0x370 total, factory alloc)
};

// Vtable slot 24 (0xd0) = SpotLightRig::Obj update — entry 0x7100712ed4,
// true size: 0x3f8, range 0x7100712ed4..0x71007132cc. Self fields: light node
// ptr +0x358, id halfword +0x360, angle accumulators i32 +0x364/+0x368,
// mask halfword +0x36c. Semantics:
//  - Gate: vt[0x90/8](arg, [+0x360]) bit0 must be set and *(u8*)(lt+0x58)
//    nonzero, else return.
//  - [+0x36C] = *(u16*)(arg+0xC) & mask.
//  - vt[0x80/8](arg, &sp+0x40, id) fetches two rgb triples (+0x40/+0x50/
//    +0x60, second at +0x4c/+0x5c/+0x6c).
//  - Color combine vs lt[0x468]/[0x46C]/[0x470]: byte lt+0x490 set ->
//    out_k = lt[0x468+4k] + in[0xc+0x10k] (plain add); else 3x3 combine
//    with rows (a,b,c)/(b,a,c)/(a,b,c), (a,b,c) = (lt[0x468], lt[0x46C],
//    lt[0x470]).
//  - Default stack color words from globals 0x7102fce50 and 0x7102fce10;
//    mode switch on *(int*)(lt+0x290): 0 static, 1 double-rng hue/palette
//    via FUN_710062eecc + 683565248.0f fixed-point angles, 2 multiply; w21
//    merge into lt+0x2D0/lt+0x2F0, alpha normalized by lt[0x388]; final
//    vt+0xe0 apply. Globals touched: 0x712fc990 / 0x712fb0160 / 0x71307cb8.
//
// Vtable slot 32 = MaskedSpotLightRig update — entry 0x710072f618, size
// 0x3f8, byte-identical to slot 24 except three self offsets: light node
// ptr +0x470, id halfword +0x478, mask halfword +0x484 (all callees,
// globals, rodata floats and vtable slot offsets identical).
}  // namespace object

// Naming closure: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only). Address-anchored name retained.
