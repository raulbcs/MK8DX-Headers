#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheCloudDraw — named from ctor string evidence: ctor string tag 'aglclwd' + member names mIsDrawReduceBuffer/mIsSyncSunPosition/mDrawOrder/mCloudColorScale (0xf1a661-0xf1a745) (was address-anchored KartParamCacheVt2b28) (vptr 0x12f2b28, cell 0x13151d8, n=13, site 0xa96144, ctor 0xa960f8).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheCloudDraw : public KartParamCache {
 public:
  uint8_t mPad40[0x3c8];     // 0x40 — unproven gap
  uint64_t mField408;        // 0x408 — ctor-written
  uint8_t mPad410[0x28];     // 0x410 — unproven gap
  uint64_t mField438;        // 0x438 — ctor-written
  uint8_t mPad440[0x10];     // 0x440 — unproven gap
  uint8_t mField450;         // 0x450 — ctor-written
  uint8_t mPad451[0x7];      // 0x451 — unproven gap
  uint64_t mField458;        // 0x458 — ctor-written
  uint8_t mPad460[0x10];     // 0x460 — unproven gap
  uint8_t mField470;         // 0x470 — ctor-written
  uint8_t mPad471[0x7];      // 0x471 — unproven gap
  uint64_t mField478;        // 0x478 — ctor-written
  uint8_t mPad480[0x10];     // 0x480 — unproven gap
  uint8_t mField490;         // 0x490 — ctor-written
  uint8_t mPad491[0x7];      // 0x491 — unproven gap
  uint64_t mField498;        // 0x498 — ctor-written
  uint8_t mPad4a0[0x10];     // 0x4a0 — unproven gap
  uint8_t mPad4b0;           // 0x4b0 — ctor zero
  uint8_t mPad4b1[0x7];      // 0x4b1 — unproven gap
  uint64_t mField4b8;        // 0x4b8 — ctor-written
  uint8_t mPad4c0[0x10];     // 0x4c0 — unproven gap
  uint8_t mPad4d0;           // 0x4d0 — ctor zero
  uint8_t mPad4d1[0x7];      // 0x4d1 — unproven gap
  uint64_t mField4d8;        // 0x4d8 — ctor-written
  uint8_t mPad4e0[0x10];     // 0x4e0 — unproven gap
  uint32_t mZero4f0;         // 0x4f0 — ctor zero
  uint8_t mPad4f4[0x4];      // 0x4f4 — unproven gap
  uint64_t mField4f8;        // 0x4f8 — ctor-written
  uint8_t mPad500[0x10];     // 0x500 — unproven gap
  uint32_t mField510;        // 0x510 — ctor-written
  uint8_t mPad514[0x4];      // 0x514 — unproven gap
  uint64_t mField518;        // 0x518 — ctor-written
  uint8_t mPad520[0x10];     // 0x520 — unproven gap
  uint64_t mField530;        // 0x530 — ctor-written
  uint32_t mField534;        // 0x534 — ctor-written
  uint64_t mField538;        // 0x538 — ctor-written
  uint32_t mField53c;        // 0x53c — ctor-written
  uint64_t mField540;        // 0x540 — ctor-written
  uint8_t mPad548[0x10];     // 0x548 — unproven gap
  uint32_t mField558;        // 0x558 — ctor-written
  uint8_t mPad55c[0x4];      // 0x55c — unproven gap
  uint64_t mField560;        // 0x560 — ctor-written
  uint8_t mPad568[0x10];     // 0x568 — unproven gap
  uint32_t mField578;        // 0x578 — ctor-written
  uint8_t mPad57c[0x4];      // 0x57c — unproven gap
  uint64_t mField580;        // 0x580 — ctor-written
  uint8_t mPad588[0x10];     // 0x588 — unproven gap
  uint32_t mField598;        // 0x598 — ctor-written
  uint8_t mPad59c[0x4];      // 0x59c — unproven gap
  uint64_t mField5a0;        // 0x5a0 — ctor-written
  uint8_t mPad5a8[0x10];     // 0x5a8 — unproven gap
  uint32_t mField5b8;        // 0x5b8 — ctor-written
  uint8_t mPad5bc[0x4c];     // 0x5bc — unproven gap
  uint8_t mPad608;           // 0x608 — ctor zero
  uint8_t mPad609[0xf];      // 0x609 — unproven gap
  uint32_t mZero618;         // 0x618 — ctor zero
  uint8_t mPad61c[0x4];      // 0x61c — unproven gap
  uint64_t mZero620;         // 0x620 — ctor zero
  uint8_t mPad628[0x3ea8];   // 0x628 — unproven gap
  uint64_t mZero44d0;        // 0x44d0 — ctor zero
  uint64_t mZero44d8;        // 0x44d8 — ctor zero
  uint64_t mZero44e0;        // 0x44e0 — ctor zero
  uint64_t mZero44e8;        // 0x44e8 — ctor zero
  uint64_t mZero44f0;        // 0x44f0 — ctor zero
  uint64_t mZero44f8;        // 0x44f8 — ctor zero
  uint8_t mPad4500[0x19f0];  // 0x4500 — unproven gap
  uint64_t mZero5ef0;        // 0x5ef0 — ctor zero
  uint64_t mZero5ef8;        // 0x5ef8 — ctor zero
  uint64_t mZero5f00;        // 0x5f00 — ctor zero
  uint64_t mZero5f08;        // 0x5f08 — ctor zero
  uint64_t mZero5f10;        // 0x5f10 — ctor zero
  uint64_t mZero5f18;        // 0x5f18 — ctor zero
  uint8_t mPad5f20[0x19f0];  // 0x5f20 — unproven gap
  uint64_t mZero7910;        // 0x7910 — ctor zero
  uint64_t mZero7918;        // 0x7918 — ctor zero
  uint64_t mZero7920;        // 0x7920 — ctor zero
  uint64_t mZero7928;        // 0x7928 — ctor zero
  uint64_t mZero7930;        // 0x7930 — ctor zero
  uint64_t mZero7938;        // 0x7938 — ctor zero
  uint8_t mPad7940[0x240];   // 0x7940 — unproven gap
  uint64_t mField7b80;       // 0x7b80 — ctor-written
  uint8_t mPad7b88[0x30];    // 0x7b88 — unproven gap
  uint64_t mField7bb8;       // 0x7bb8 — ctor-written
  uint8_t mPad7bc0[0x390];   // 0x7bc0 — unproven gap
  uint64_t mField7f50;       // 0x7f50 — ctor-written
  uint8_t mPad7f58[0x30];    // 0x7f58 — unproven gap
  uint64_t mField7f88;       // 0x7f88 — ctor-written
};
// Vtable slot 0 (0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/cloudDrawDtorSlot0_7100a969d4.cpp):
// stamps vptr 0x13151d8(+0x10); if byte +0x8270 set, calls the companion reset
// 0x7100a96c08; frees the pooled array at +0x620 (count at -8, stride 0x1258, element
// reset 0x7100a96ecc), zeroing +0x620/+0x618; resets containers 0x71006375a0 on
// +0x7b80/+0x7bb8/+0x7f50/+0x7f88, 0x7100654ae0 on +0x1d0, 0x71006469c4 on +0x7fc0,
// re-stamps and finalizes +0x7f88/0x130d838 and +0x7f50/0x13151e8, 0x710063ea80 on
// +0x7ef0/+0x7b20, 0x71006462c4 on +0x7d10/+0x7940, 0x71006469c4 on +0x7bf0; runs the
// KartParamCacheCloudTex slot-0 dtor on +0x5f20/+0x4500/+0x2ae0 and 0x7100a96ecc on
// +0x1880/+0x628; re-stamps cell 0x130d918(+0x10) into +0x5a0..+0x438 (0x20 stride,
// 12 slots), cell 0x130d920(+0x10) into +0x408, cell 0x130d830(+0x10) into +0x1d0 with
// 0x7100654ae0/0x71006156b4; finally stamps cell 0x130d848(+0x10) into +0x0. True
// function size 0x230 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
