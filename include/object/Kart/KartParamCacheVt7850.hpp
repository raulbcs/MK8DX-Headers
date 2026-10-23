#pragma once

#include <cstdint>
#include <object/Kart/KartParamCache.hpp>

// KartParamCacheVt7850 — address-anchored name (vptr 0x12b7850,
// GOT cell 0x130e240). Cluster variant whose ctor (0x71006ae398 region) writes flags
namespace object::Kart {
class KartParamCacheVt7850 : public KartParamCache {
 public:
  char mOwn40[0x120];  // 40 — own-field region
};
}  // namespace object
