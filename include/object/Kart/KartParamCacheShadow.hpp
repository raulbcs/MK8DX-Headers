#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheShadow — named from ctor string evidence: ctor string tag 'aglsdw' + params cascade_num/mip_level_num/depth_clamp/stable_texel_width (0xf1dab5-0xf1dbb2) (was address-anchored KartParamCacheVt3e90) (vptr 0x12f3e90, cell 0x13153d8, n=13, site 0xad9134, ctor 0xad90e8).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheShadow : public KartParamCache {
 public:
  uint8_t mPad40[0x1b0];    // 0x40 — unproven gap
  uint64_t mField1f0;       // 0x1f0 — ctor-written
  uint8_t mPad1f8[0x28];    // 0x1f8 — unproven gap
  uint64_t mField220;       // 0x220 — ctor-written
  uint8_t mPad228[0x10];    // 0x228 — unproven gap
  uint32_t mField238;       // 0x238 — ctor-written
  uint8_t mPad23c[0x4];     // 0x23c — unproven gap
  uint64_t mField240;       // 0x240 — ctor-written
  uint8_t mPad248[0x10];    // 0x248 — unproven gap
  uint32_t mField258;       // 0x258 — ctor-written
  uint8_t mPad25c[0x4];     // 0x25c — unproven gap
  uint64_t mField260;       // 0x260 — ctor-written
  uint8_t mPad268[0x10];    // 0x268 — unproven gap
  uint8_t mField278;        // 0x278 — ctor-written
  uint8_t mPad279[0x7];     // 0x279 — unproven gap
  uint64_t mField280;       // 0x280 — ctor-written
  uint8_t mPad288[0x10];    // 0x288 — unproven gap
  uint32_t mField298;       // 0x298 — ctor-written
  uint8_t mPad29c[0x4];     // 0x29c — unproven gap
  uint64_t mField2a0;       // 0x2a0 — ctor-written
  uint8_t mPad2a8[0x10];    // 0x2a8 — unproven gap
  uint32_t mZero2b8;        // 0x2b8 — ctor zero
  uint8_t mPad2bc[0x4];     // 0x2bc — unproven gap
  uint64_t mField2c0;       // 0x2c0 — ctor-written
  uint8_t mPad2c8[0x10];    // 0x2c8 — unproven gap
  uint32_t mZero2d8;        // 0x2d8 — ctor zero
  uint8_t mPad2dc[0x4];     // 0x2dc — unproven gap
  uint64_t mField2e0;       // 0x2e0 — ctor-written
  uint8_t mPad2e8[0x10];    // 0x2e8 — unproven gap
  uint32_t mField2f8;       // 0x2f8 — ctor-written
  uint8_t mPad2fc[0x4];     // 0x2fc — unproven gap
  uint64_t mField300;       // 0x300 — ctor-written
  uint8_t mPad308[0x10];    // 0x308 — unproven gap
  uint64_t mZero318;        // 0x318 — ctor zero
  uint32_t mZero320;        // 0x320 — ctor zero
  uint8_t mPad324;          // 0x324 — ctor zero
  uint8_t mPad325[0x3];     // 0x325 — unproven gap
  uint64_t mField328;       // 0x328 — ctor-written
  uint8_t mPad330[0x10];    // 0x330 — unproven gap
  uint32_t mField340;       // 0x340 — ctor-written
  uint8_t mPad344[0x4];     // 0x344 — unproven gap
  uint64_t mField348;       // 0x348 — ctor-written
  uint8_t mPad350[0x10];    // 0x350 — unproven gap
  uint64_t mZero360;        // 0x360 — ctor zero
  uint32_t mZero368;        // 0x368 — ctor zero
  uint8_t mPad36c;          // 0x36c — ctor zero
  uint8_t mPad36d[0x3];     // 0x36d — unproven gap
  uint32_t mZero370;        // 0x370 — ctor zero
  uint8_t mPad374[0x4];     // 0x374 — unproven gap
  uint64_t mZero378;        // 0x378 — ctor zero
  uint8_t mPad380[0x1418];  // 0x380 — unproven gap
  uint64_t mZero1798;       // 0x1798 — ctor zero
  uint8_t mPad17a0[0x20];   // 0x17a0 — unproven gap
  uint32_t mZero17c0;       // 0x17c0 — ctor zero
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/shadowDtorResetSlot0_7100ad99a8.cpp):
// tears down the +0x380 drawer, frees the pooled array at +0x378 (stride 0x5d0,
// paramNodeVt3f08DtorSlot0_7100adb5d0 element dtor), releases the optional heap blocks
// at +0x360/+0x318 (flags +0x36c/+0x324), then re-stamps default vptr fields +0x348,
// +0x300, +0x2e0, +0x2c0, +0x2a0, +0x280, +0x260, +0x240, +0x220, +0x1f0 and +0x0.
// function size 0x128 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
