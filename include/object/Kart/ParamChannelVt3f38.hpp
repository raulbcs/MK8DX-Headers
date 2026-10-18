#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object {
// ParamChannelVt3f38 - address-anchored name (vptr 0x12b3f38, GOT cell
// 0x130dbb8, factory 0x6681d8).
// extent 0x278 - details: doc/object/Kart/ParamChannelVt3f38.md
class ParamChannelVt3f38 : public KartParamCacheChan {
 public:
  void* mRecord20;         // 0x20 - set to this+0x78+0x80*i (last group)
  uint8_t mFlag28;         // 0x28 - zeroed then 7
  uint8_t mFlag29;         // 0x29 - 4
  uint8_t mFlag2a;         // 0x2a - 0x1e
  uint8_t mFlag2b;         // 0x2b - 9
  uint8_t pad2c[4];        // 0x2c - unproven padding
  void* mSecond30;         // 0x30 - [cell 0x12fd178]+0x10
  void* mSecond38;         // 0x38 - 0
  void* mThird48;          // 0x48 - [cell 0x12fd178]+0x10
  void* mThird50;          // 0x50 - 0
  void* mFourth60;         // 0x60 - [cell 0x12fd178]+0x10
  void* mFourth68;         // 0x68 - 0
  uint8_t mFlags40[4];     // 0x40 - 0,4,0,0 (two 16-bit zeroes + 4)
  uint8_t pad44[4];        // 0x44 - unproven gap
  uint8_t mFlags58[4];     // 0x58 - 0,4,0 (byte 4 then two zeroed bytes)
  uint8_t pad5c[4];        // 0x5c - unproven gap
  uint8_t mFlags70[4];     // 0x70 - 0,4,0 (byte 4 then two zeroed bytes)
  uint8_t pad74[4];        // 0x74 - unproven gap
  struct Group78 {         // 0x78 - 4 groups, stride 0x80
    uint8_t mHead8[8];     // +0x00 - unproven
    uint8_t mBlob8[0x24];  // +0x08 - memcpy from static blob cell 0x130da80
    float mScales2c[21];   // +0x2c - all 1.0f (fills to +0x80)
  };
  Group78 mGroups78[4];  // 0x78 - memcpy(arg+0x78, 0x200) overwrites
                         // (0x278 total)
};
}  // namespace object
