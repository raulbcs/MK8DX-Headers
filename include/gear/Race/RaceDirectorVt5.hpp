#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// gear::RaceDirectorVt5 — PROVISIONAL vtable-anchored name; state machine
// on +0x9c (vtable 0x11b3460, ctor 0x71000511a8, size 0xC8 —
// extent 0xc4 (ctor 0x71000511a8 store reach; allocation site 0x710006f32c news 0xC8)
// Details: doc/gear/Race/RaceDirectorVt5.md

namespace gear {
class RaceDirectorVt5 : public RaceDirectorVt2 {
 public:
  uint32_t mState9c;   //0x9C — state machine 0..0xa
  uint32_t mZeroa0;    //0xA0
  uint32_t mZeroa4;    //0xA4
  uint32_t mZeroa8;    //0xA8
  uint32_t mTicks600;  //0xAC — ctor sets 600
  int32_t mMinus1b0;   //0xB0 — ctor sets -1
  uint32_t mZerob4;    //0xB4
  uint32_t mZerob8;    //0xB8
  uint16_t mFfffbc;    //0xBC — ctor sets 0xFFFF; slot 0xd0 override getter
  uint16_t mFfffbe;    //0xBE — ctor sets 0xFFFF
  uint32_t mZeroc0;    //0xC0 — slot 0xd8 override getter returns this word
  // extent 0xc4 (ctor 0x71000511A8 stores reach 0xc4)
};
}  // namespace gear
