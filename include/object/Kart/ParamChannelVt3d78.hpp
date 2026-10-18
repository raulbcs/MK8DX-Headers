#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt3d78 - address-anchored name (vptr 0x12b3d78, GOT cell
// 0x130db78, factory 0x666190).
// extent 0xb0 - details: doc/object/Kart/ParamChannelVt3d78.md
class ParamChannelVt3d78 : public KartParamCacheChan {
 public:
  void* mRecord20;        // 0x20 - set to this+0x38 by factory 0x666190
  uint8_t mFlag28;        // 0x28 - zeroed then set to 7
  uint8_t mFlag29;        // 0x29 - 4
  uint8_t mFlag2a;        // 0x2a - 0x1e
  uint8_t mFlag2b;        // 0x2b - 9
  uint8_t pad2c[4];       // 0x2c - unproven padding
  uint32_t mW30;          // 0x30 - 9 (written via post-inc store)
  uint32_t mW34;          // 0x34 - 7
  uint8_t mBlob38[0x24];  // 0x38 - memcpy from static blob cell 0x130db90
  float mScales5c[21];    // 0x5c - all 1.0f
                          // (0xb0 total)
};
}  // namespace object
