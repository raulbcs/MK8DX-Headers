#pragma once

#include <cstdint>
#include <object/Kart/KartParamCache.hpp>

// KartParamCacheMid2 — address-anchored name (vptr 0x12b4518,
// extent 0x1d0
namespace object::Kart {
class KartParamCacheMid2 : public KartParamCache {
 public:
  uint8_t mPad40[0x10];   // 0x40 — unproven gap
  uint64_t mField50;      // 0x50
  uint32_t mField58;      // 0x58
  uint8_t mPad5c[0x44];   // 0x5c — unproven gap
  uint32_t mFielda0;      // 0xa0
  uint8_t mPada4[0x4];    // 0xa4 — unproven gap
  uint64_t mZeroa8;       // 0xa8 — ctor zero
  uint64_t mFieldb0;      // 0xb0
  uint64_t mFieldb8;      // 0xb8
  uint8_t mPadc0[0x108];  // 0xc0 — unproven gap
  uint64_t mZero1c8;      // 0x1c8 — ctor zero
};
}  // namespace object
