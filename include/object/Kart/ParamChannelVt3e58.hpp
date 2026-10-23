#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"
#include <object/Kart/KartParamCacheChanBase.hpp>
#include <object/Kart/KartParamCacheChan.hpp>

namespace object::Kart {
// ParamChannelVt3e58 - address-anchored name (vptr 0x12b3e58, GOT cell
// 0x130db98, factory 0x667120).
// extent 0x148 - details: doc/object/Kart/ParamChannelVt3e58.md
class ParamChannelVt3e58 : public KartParamCacheChan {
 public:
  void* mRecord20;        // 0x20 - set to this+0x50 by factory 0x667120
  uint8_t mFlag28;        // 0x28 - zeroed then 7
  uint8_t mFlag29;        // 0x29 - 4
  uint8_t mFlag2a;        // 0x2a - 0x1e
  uint8_t mFlag2b;        // 0x2b - 9
  uint8_t pad2c[4];       // 0x2c - unproven padding
  void* mSecond30;        // 0x30 - [cell 0x12fd178]+0x10
  void* mRecord38;        // 0x38 - set to this+0xd0
  uint8_t mFlag40;        // 0x40 - 0
  uint8_t mFlag41;        // 0x41 - 4
  uint8_t mFlag42;        // 0x42 - 0
  uint8_t mFlag43;        // 0x43 - 0
  uint8_t pad44[4];       // 0x44 - unproven padding
  uint32_t mW48;          // 0x48 - 9 (written via post-inc store)
  uint32_t mW4c;          // 0x4c - 7
  uint8_t mBlob50[0x24];  // 0x50 - memcpy from static blob cell 0x130dbb0
  float mScales74[21];    // 0x74 - all 1.0f
  uint32_t mWc8;          // 0xc8 - 9
  uint32_t mWcc;          // 0xcc - 7
  uint8_t mBlobD0[0x24];  // 0xd0 - memcpy(0x24) from same blob cell
  float mScalesF4[20];    // 0xf4 - all 1.0f
  uint8_t pad144[4];      // 0x144 - unproven gap
                          // (0x148 total)
};
}  // namespace object::Kart
