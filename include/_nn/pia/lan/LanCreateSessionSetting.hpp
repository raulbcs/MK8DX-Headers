#pragma once

#include <cstdint>

namespace nn::pia::lan {
// LanCreateSessionSetting — RTTI-named (typeinfo 0x12dc020, name
// "N2nn3pia3lan23LanCreateSessionSettingE"; base session::CreateSessionSetting).
// 9 slots; GOT cell 0x13132e8 holds vptr-0x10 (vptr 0x12dbfd0).
// extent 0x1c0 - details: doc/_nn/pia/lan/LanCreateSessionSetting.md
class LanCreateSessionSetting {
 public:
  void* mVtable;          // 0x00 - vptr 0x12dbfd0 (cell 0x13132e8 + 0x10)
  uint64_t mZero08;       // 0x08 - zeroed by C1 (stp x8, xzr)
  uint32_t m10;           // 0x10 - zeroed by C1
  uint8_t mPad14[0x4];    // 0x14 - pad to 0x18
  uint8_t mPad18[0x18];   // 0x18 - memset 0 by C1
  uint8_t mPad30[0x180];  // 0x30 - memset 0 by C1
  uint32_t m1B0;          // 0x1b0 - zeroed by C1
  uint8_t m1B4[0x4];      // 0x1b4 - zeroed by C1 (u8 + pad)
  uint32_t m1B8;          // 0x1b8 - zeroed by C1
  uint8_t m1BC[0x4];      // 0x1bc - tail pad to 0x1c0 (member stride)
};
}  // namespace nn::pia::lan
