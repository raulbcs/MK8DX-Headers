#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object {
// KartParamCacheContainer — address-anchored name (vptr 0x12bd0a8,
// GOT cell 0x130e848, n=13). The KartParamCacheContainer of the KartSlotCap note (ctor
// 0x710071db70): zeros across 0x660..0x8e8. Extent 0x8f0.

class KartParamCacheContainer : public KartParamCacheMid2 {
 public:
  // additional writes by ctor 0x710071db70
};
// Vtable slot 0 (+0x10) dtor/reset (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/containerDtorResetSlot0_710071e5dc.cpp):
// frees the pooled array at +0x338 (stride 0xfd0, 0x7100721758 per entry), re-inits the
// +0x900 container, runs 0x710063a384 on +0x850 and 0x7100639f38 on +0x780, re-stamps
// default vptr fields +0x8c0 and +0x6a8..+0x340 (cell 0x710130d918), +0x300
// (0x710130d920), +0x900/+0x0 (0x710130d830 / 0x710130d848). function size 0x144 bytes.
}  // namespace object

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
