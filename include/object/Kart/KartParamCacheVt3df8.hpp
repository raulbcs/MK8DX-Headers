#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheVt3df8 — address-anchored name (vptr 0x12f3df8, cell 0x13153c8, n=13, site 0xad0720, ctor 0xad06d0).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheVt3df8 : public KartParamCache {
 public:
  uint8_t mPad40[0x190];   // 0x40 — unproven gap
  uint32_t mZero1d0;       // 0x1d0 — ctor zero
  uint8_t mPad1d4[0x4];    // 0x1d4 — unproven gap
  uint64_t mZero1d8;       // 0x1d8 — ctor zero
  uint32_t mField1e0;      // 0x1e0 — ctor-written
  uint8_t mPad1e4[0x24];   // 0x1e4 — unproven gap
  uint64_t mZero208;       // 0x208 — ctor zero
  uint8_t mPad210[0x30];   // 0x210 — unproven gap
  uint64_t mField240;      // 0x240 — ctor-written
  uint8_t mPad248[0x10];   // 0x248 — unproven gap
  uint32_t mZero258;       // 0x258 — ctor zero
  uint8_t mPad25c[0x4];    // 0x25c — unproven gap
  uint64_t mField260;      // 0x260 — ctor-written
  uint8_t mPad268[0x10];   // 0x268 — unproven gap
  uint32_t mField278;      // 0x278 — ctor-written
  uint8_t mPad27c[0x4];    // 0x27c — unproven gap
  uint64_t mField280;      // 0x280 — ctor-written
  uint8_t mPad288[0x10];   // 0x288 — unproven gap
  uint32_t mZero298;       // 0x298 — ctor zero
  uint8_t mPad29c[0x4];    // 0x29c — unproven gap
  uint64_t mField2a0;      // 0x2a0 — ctor-written
  uint8_t mPad2a8[0x10];   // 0x2a8 — unproven gap
  uint32_t mZero2b8;       // 0x2b8 — ctor zero
  uint8_t mPad2bc[0x4];    // 0x2bc — unproven gap
  uint64_t mField2c0;      // 0x2c0 — ctor-written
  uint8_t mPad2c8[0x10];   // 0x2c8 — unproven gap
  uint32_t mField2d8;      // 0x2d8 — ctor-written
  uint32_t mField2dc;      // 0x2dc — ctor-written
  uint64_t mField2e0;      // 0x2e0 — ctor-written
  uint8_t mPad2e8[0x10];   // 0x2e8 — unproven gap
  uint64_t mField2f8;      // 0x2f8 — ctor-written
  uint32_t mField2fc;      // 0x2fc — ctor-written
  uint64_t mField300;      // 0x300 — ctor-written
  uint32_t mField304;      // 0x304 — ctor-written
  uint64_t mField308;      // 0x308 — ctor-written
  uint8_t mPad310[0x10];   // 0x310 — unproven gap
  uint32_t mField320;      // 0x320 — ctor-written
  uint32_t mField324;      // 0x324 — ctor-written
  uint64_t mField328;      // 0x328 — ctor-written
  uint8_t mPad330[0x10];   // 0x330 — unproven gap
  uint32_t mField340;      // 0x340 — ctor-written
  uint32_t mField344;      // 0x344 — ctor-written
  uint8_t mPad348[0x238];  // 0x348 — unproven gap
  uint64_t mField580;      // 0x580 — ctor-written
  uint8_t mPad588[0x10];   // 0x588 — unproven gap
  uint32_t mField598;      // 0x598 — ctor-written
  uint32_t mField59c;      // 0x59c — ctor-written
  uint32_t mField5a0;      // 0x5a0 — ctor-written
  uint8_t mPad5a4[0x4];    // 0x5a4 — unproven gap
  uint64_t mField5a8;      // 0x5a8 — ctor-written
  uint8_t mPad5b0[0x10];   // 0x5b0 — unproven gap
  uint32_t mZero5c0;       // 0x5c0 — ctor zero
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/vt3df8DtorResetSlot0_7100ad0b20.cpp):
// frees the pooled array at +0x1d8 (stride 0x678, count at -8) running six element
// destructors per entry, re-stamps default vptr fields +0x5a8/+0x580/+0x328/+0x308/
// +0x2e0/+0x2c0/+0x2a0/+0x280/+0x260/+0x240/+0x210 and +0x0, re-inits the +0x348
// container. function size 0x128 bytes.
}  // namespace object

// Naming closure: ctor strings found (pref, start/end, blur_type/kernel, clear color) but no engine tag and no unambiguous role; kept address-anchored.
