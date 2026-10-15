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
// dtor: pooled-array strides 0xfd0; resets cells 0x710130d918; fn size 0x144.

}  // namespace object

// Naming: factory/array structural variant (base-call chain + factory case id only, no per-class strings).
