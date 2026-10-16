#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// gear::RaceDirectorVt6 — PROVISIONAL vtable-anchored name; rodata-seeded
// config (vtable 0x11b3598, ctor 0x710005377c, size 0xD8 —
// extent 0xd4 (ctor 0x710005377c store reach; allocation site 0x710006ef64 news 0xD8)
// Details: doc/gear/Race/RaceDirectorVt6.md

namespace gear {
class RaceDirectorVt6 : public RaceDirectorVt2 {
 public:
  uint32_t mState9c;    //0x9C — ctor zero
  uint32_t mZeroa0;     //0xA0
  uint32_t mZeroa4;     //0xA4
  uint32_t mTicks600;   //0xA8 — ctor sets 600
  int32_t mMinus1ac;    //0xAC — ctor sets -1
  uint32_t mZerob0;     //0xB0
  uint32_t mZerob4;     //0xB4
  uint32_t mCount11b8;  //0xB8 — ctor copies *(u32*)rodata 0xf73bb4 (== 11); slot 0xd0 override getter returns this word
  uint32_t mZerobc;     //0xBC
  uint64_t mTableC0;    //0xC0 — ctor copies *(u64*)rodata 0xf57b7c
  uint32_t mTableC8;    //0xC8 — ctor copies *(u32*)(0xf57b7c+8)
  uint16_t mZerocc;     //0xCC — ctor zero (u16)
  uint32_t mZerod0;     //0xD0
  uint8_t mGapCE[2];    // 0xCE — unproven gap
};
}  // namespace gear
