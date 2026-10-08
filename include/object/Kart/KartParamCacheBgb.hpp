#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object {
// KartParamCacheBgb — named from ctor string evidence: ctor string tag 'gsysbgb' + params scale/blur_offset/enable_expand_blur/background_buffer (0xf05894-0xf0596a) (was address-anchored KartParamCacheVtbd030) (vptr 0x12bd030,
// GOT cell 0x130e840, n=?). Mid2-derived variant: ctor zeroes 0x1d0/0x1d8 and writes to 0x330.
// Extent 0x338.
class KartParamCacheBgb : public KartParamCacheMid2 {
 public:
  // additional writes by ctor 0x710071d134
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/bgbDtorResetSlot0_710071d3a4.cpp):
// frees the pooled array at +0x1d8 (stride 0x5e8) running five element destructors per
// entry, re-inits the +0x338 container, re-stamps default vptr fields +0x318/+0x2f8/
// +0x2d8/+0x2b8/+0x298 (cell 0x710130d918), +0x268 (0x710130d920), +0x338
// (0x710130d830), +0x0 (0x710130d848). function size 0x10c bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
