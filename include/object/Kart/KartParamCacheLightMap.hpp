#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheLightMap — named from ctor string evidence: ctor string tag 'agllmap' (0xefa640) (was address-anchored KartParamCacheVt48f8) (vptr 0x12b48f8, cell 0x130dce0, n=13, site 0x67885c, ctor 0x678808).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheLightMap : public KartParamCache {
 public:
  uint8_t mPad40[0x190];   // 0x40 — unproven gap
  uint32_t mZero1d0;       // 0x1d0 — ctor zero
  uint8_t mPad1d4[0x14];   // 0x1d4 — unproven gap
  uint64_t mZero1e8;       // 0x1e8 — ctor zero
  uint8_t mPad1f0[0x10];   // 0x1f0 — unproven gap
  uint32_t mZero200;       // 0x200 — ctor zero
  uint32_t mField204;      // 0x204 — ctor-written
  uint64_t mZero208;       // 0x208 — ctor zero
  uint32_t mZero210;       // 0x210 — ctor zero
  uint8_t mPad214[0x4];    // 0x214 — unproven gap
  uint64_t mZero218;       // 0x218 — ctor zero
  uint32_t mZero220;       // 0x220 — ctor zero
  uint8_t mPad224[0x34c];  // 0x224 — unproven gap
  uint64_t mZero570;       // 0x570 — ctor zero
  uint32_t mZero578;       // 0x578 — ctor zero
  uint8_t mPad57c[0x4];    // 0x57c — unproven gap
  uint64_t mZero580;       // 0x580 — ctor zero
  uint32_t mZero588;       // 0x588 — ctor zero
  uint8_t mPad58c[0x34c];  // 0x58c — unproven gap
  uint64_t mZero8d8;       // 0x8d8 — ctor zero
  uint32_t mZero8e0;       // 0x8e0 — ctor zero
  uint8_t mPad8e4[0x4];    // 0x8e4 — unproven gap
  uint64_t mZero8e8;       // 0x8e8 — ctor zero
  uint32_t mZero8f0;       // 0x8f0 — ctor zero
};
// Vtable slots (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - slot 0 (+0x10) dtor/reset (lightMapDtorResetSlot0_7100678b78.cpp): runs
//   0x71006373a4 (cold fragment) on the +0x33e8 block, frees the pooled array at +0x1d8
//   (stride 0xad8, 0x7100695e90 element dtor), clears +0x1e0 via 0x710060b984, re-inits
//   the +0x3408 container, and runs a 32-iteration pass (offsets 0x2000 down to 0x100,
//   step 0x100) resetting each node (+0xb90 vptr, +0xb40 vptr) through 0x710062fe44;
//   re-stamps the +0x8d8..+0x2d8 blocks and the +0x0 vptr. function size 0x17c bytes.
// - slot 5 (0x38) release tiles (lightMapSlot5ReleaseTilesAndSetFlag_710067ab40.cpp):
//   ORs byte +0x3401 with 0x28; for each of *(u32*)(+0x1d0) entries calls
//   0x7100699b44 on successive pointers from +0x1d8 (stride 0xad8); tail-calls
//   0x710067a474(self). function size 0x5c bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
