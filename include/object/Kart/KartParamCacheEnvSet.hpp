#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object {
// KartParamCacheEnvSet — named from ctor string tag 'aglenvset' (0xef9116; was address-anchored KartParamCacheVt2738) (vptr 0x12b2738,
// GOT cell 0x130d9a0). Mid2-derived variant (ctor 0x710064bdac calls 0x7100668d40): zeros
// 0x1d0-0x1f8, then init 0x7100689f00 with a name pair (rodata
// 0xef9120). Extent 0x200.
class KartParamCacheEnvSet : public KartParamCacheMid2 {
 public:
  // (0x200 total)
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/envSetDtorResetSlot0_710064be2c.cpp):
// walks the pooled array at +0x1e0 (stride 0x2e8, count at -8); per entry runs the
// element dtor 0x710064a82c over the inner array at entry-0x8 (stride 0x168), frees it
// and clears the entry's count/pointer fields (-0x10/-0x8), then re-stamps default vptrs
// at entry-0x2e8, entry-0x270 and entry-0x2a0; frees the outer array, clears +0x1e0/
// +0x1d8, re-inits the +0x1e8 container, stamps the +0x0 vptr. function size 0x148 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
