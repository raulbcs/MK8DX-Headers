#pragma once

#include <cstdint>
#include <object/Kart/KartParamCache.hpp>

// KartParamCacheVt24c8 — address-anchored name (vptr
// extent 0x58
namespace object::Kart {
class KartParamCacheVt24c8 : public KartParamCache {
 public:
  uint8_t pad40[8];   // 0x40 — untouched by the ctors
  uint32_t mField48;  // 0x48 — factory zero
  uint8_t pad4c[4];   // 0x4c — unproven padding
  void* mPtr50;       // 0x50 — factory zero
};
}  // namespace object
