#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object {
// KartParamCacheCloud — named from ctor string evidence: ctor string tag 'aglcloud' + params tex_random_seed/tex_base_freq noise block (0xf02b9b-0xf1bd21) (was address-anchored KartParamCacheVt2f40) (vptr 0x12f2f40, cell 0x1315250, n=13, site 0xaac060, ctor 0xaac014).
// Variant of the 0x63c6f8 param-cache cluster.
class KartParamCacheCloud : public KartParamCache {
 public:
  uint8_t mPad40[0x490];    // 0x40 — unproven gap
  uint32_t mZero4d0;        // 0x4d0 — ctor zero
  uint8_t mPad4d4[0x4];     // 0x4d4 — unproven gap
  uint64_t mZero4d8;        // 0x4d8 — ctor zero
  uint64_t mField4e0;       // 0x4e0 — ctor-written
  uint64_t mZero4e8;        // 0x4e8 — ctor zero
  uint64_t mZero4f0;        // 0x4f0 — ctor zero
  uint32_t mZero4f8;        // 0x4f8 — ctor zero
  uint8_t mPad4fc[0x4];     // 0x4fc — unproven gap
  uint64_t mField500;       // 0x500 — ctor-written
  uint8_t mPad508[0x30];    // 0x508 — unproven gap
  uint64_t mField538;       // 0x538 — ctor-written
  uint8_t mPad540[0x30];    // 0x540 — unproven gap
  uint64_t mField570;       // 0x570 — ctor-written
  uint8_t mPad578[0x7770];  // 0x578 — unproven gap
  uint64_t mField7ce8;      // 0x7ce8 — ctor-written
  uint8_t mPad7cf0[0x28];   // 0x7cf0 — unproven gap
  uint64_t mField7d18;      // 0x7d18 — ctor-written
  uint8_t mPad7d20[0x18];   // 0x7d20 — unproven gap
  uint64_t mField7d38;      // 0x7d38 — ctor-written
  uint8_t mPad7d40[0x18];   // 0x7d40 — unproven gap
  uint64_t mField7d58;      // 0x7d58 — ctor-written
  uint8_t mPad7d60[0x18];   // 0x7d60 — unproven gap
  uint64_t mField7d78;      // 0x7d78 — ctor-written
  uint8_t mPad7d80[0x18];   // 0x7d80 — unproven gap
  uint64_t mField7d98;      // 0x7d98 — ctor-written
  uint8_t mPad7da0[0x18];   // 0x7da0 — unproven gap
  uint64_t mField7db8;      // 0x7db8 — ctor-written
  uint8_t mPad7dc0[0x18];   // 0x7dc0 — unproven gap
  uint64_t mField7dd8;      // 0x7dd8 — ctor-written
  uint8_t mPad7de0[0x18];   // 0x7de0 — unproven gap
  uint64_t mField7df8;      // 0x7df8 — ctor-written
  uint8_t mPad7e00[0x18];   // 0x7e00 — unproven gap
  uint64_t mField7e18;      // 0x7e18 — ctor-written
  uint8_t mPad7e20[0x18];   // 0x7e20 — unproven gap
  uint64_t mField7e38;      // 0x7e38 — ctor-written
  uint8_t mPad7e40[0x28];   // 0x7e40 — unproven gap
  uint64_t mField7e68;      // 0x7e68 — ctor-written
  uint8_t mPad7e70[0x18];   // 0x7e70 — unproven gap
  uint64_t mField7e88;      // 0x7e88 — ctor-written
  uint8_t mPad7e90[0x18];   // 0x7e90 — unproven gap
  uint64_t mField7ea8;      // 0x7ea8 — ctor-written
  uint8_t mPad7eb0[0x18];   // 0x7eb0 — unproven gap
  uint64_t mField7ec8;      // 0x7ec8 — ctor-written
  uint8_t mPad7ed0[0x28];   // 0x7ed0 — unproven gap
  uint64_t mField7ef8;      // 0x7ef8 — ctor-written
  uint8_t mPad7f00[0x18];   // 0x7f00 — unproven gap
  uint64_t mField7f18;      // 0x7f18 — ctor-written
  uint8_t mPad7f20[0x18];   // 0x7f20 — unproven gap
  uint64_t mField7f38;      // 0x7f38 — ctor-written
  uint8_t mPad7f40[0x18];   // 0x7f40 — unproven gap
  uint64_t mField7f58;      // 0x7f58 — ctor-written
};
// Vtable slot 0 (0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/cloudDtorSlot0_7100aac7e4.cpp):
// stamps vptr 0x1315250(+0x10) into +0x0; cell 0x130d918(+0x10) into +0x7f38/0x7f18/
// 0x7ef8/0x7ea8/0x7e88/0x7e68/0x7e18/0x7df8/0x7dd8/0x7db8/0x7d98/0x7d78/0x7d58/0x7d38/
// 0x7d18; cell 0x130d920(+0x10) into +0x7ec8/0x7e38/0x7ce8; cell 0x130d848(+0x10) into
// +0x7f58. Sub-object teardown in order: 0x7100aff458 on +0x6ea0/+0x6098/+0x5290/
// +0x4488/+0x3680/+0x2878/+0x1a70/+0xc68, 0x710063ea80 on +0xc08, 0x71006469c4 on
// +0xae8/+0x9c8/+0x8a8/+0x788, 0x71006462c4 on +0x5a8, vptr-stamped +0x570/+0x538/+0x500
// each followed by 0x71006374e4, then 0x7100639f38 on +0x400/+0x280; finally re-stamps
// 0x130d848(+0x10) into +0x0. function size 0x194 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
