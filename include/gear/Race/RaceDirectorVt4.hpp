#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// gear::RaceDirectorVt4 — PROVISIONAL vtable-anchored name; built by the
// director factory (vtable 0x11b3328, ctor 0x710004fd6c, size 0xC0).
// Details: doc/gear/Race/RaceDirectorVt4.md

namespace gear {
class RaceDirectorVt4 : public RaceDirectorVt2 {
 public:
  uint32_t mZero9c;    //0x9C — ctor zero
  uint32_t mZeroa0;    //0xA0
  uint32_t mZeroa4;    //0xA4
  uint32_t mTicks600;  //0xA8 — ctor sets 600 (0x258)
  int32_t mMinus1ac;   //0xAC — ctor sets -1
  uint32_t mZerob0;    //0xB0
  uint16_t mFfffb8;    //0xB8 — ctor sets 0xFFFF; slot 0xd0 override getter
  uint16_t mFfffba;    //0xBA — ctor sets 0xFFFF
  uint32_t mZerobc;    //0xBC — slot 0xd8 override getter returns this word
  uint8_t mGapB4[4];   // 0xB4 — unproven gap
};
}  // namespace gear
