#pragma once

#include <cstdint>
#include <object/Kart/KartParamCacheMid.hpp>

// KartParamCacheVt3868 — address-anchored name (vptr 0x12b3868,
// extent 0x150
namespace object::Kart {
class KartParamCacheVt3868 : public KartParamCacheMid {
 public:
  char mChan110[0x18];  // 0x110 — channel-pair member (ctor pair
  uint32_t mField128;   // 0x128 — factory zero
  uint8_t pad12c[4];    // 0x12c — unproven padding
  char mChan130[0x20];  // 0x130 — channel-pair member (names
};
}  // namespace object
