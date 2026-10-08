#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheNormalDrawer — named from ctor string evidence: ctor string tag 'aglNmdw' + 'NormalDrawer' name string (0xf1a9c5-0xf018f3) (was address-anchored KartParamCacheVt2ca0) (vptr 0x12f2ca0, cell 0x1315200, n=13, site 0xa9bb38, ctor 0xa9baf4).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheNormalDrawer : public KartParamCache {
 public:
  uint8_t mPad40[0x190];   // 0x40 — unproven gap
  uint32_t mZero1d0;       // 0x1d0 — ctor zero
  uint8_t mPad1d4[0xc];    // 0x1d4 — unproven gap
  uint32_t mField1e0;      // 0x1e0 — ctor-written
  uint8_t mPad1e4[0x23c];  // 0x1e4 — unproven gap
  uint64_t mField420;      // 0x420 — ctor-written
  uint8_t mPad428[0x28];   // 0x428 — unproven gap
  uint64_t mField450;      // 0x450 — ctor-written
  uint8_t mPad458[0x10];   // 0x458 — unproven gap
  uint8_t mField468;       // 0x468 — ctor-written
  uint8_t mPad469[0x7];    // 0x469 — unproven gap
  uint64_t mField470;      // 0x470 — ctor-written
  uint8_t mPad478[0x10];   // 0x478 — unproven gap
  uint32_t mZero488;       // 0x488 — ctor zero
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/normalDrawerDtorResetSlot0_7100a9bc80.cpp):
// frees the pooled array at +0x1d8 (stride 0x9f8) running ten element destructors per
// entry, re-inits both +0x1e8 and the drawer container, and re-stamps default vptr
// fields +0x470/+0x450 (cell 0x710130d918), +0x420 (0x710130d920), +0x1e8
// (0x710130d830), +0x0 (0x710130d848). function size 0x130 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
