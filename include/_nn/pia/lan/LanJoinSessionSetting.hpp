#pragma once

#include <cstdint>

namespace nn::pia::lan {
// LanJoinSessionSetting — RTTI-named (typeinfo 0x12dc110, name
// "N2nn3pia3lan21LanJoinSessionSettingE"; base session::JoinSessionSetting,
// vt 0x12ddc98). 9 slots; GOT cell 0x1313308 holds vptr-0x10 (vptr
// 0x12dc0c8). extent 0x18 - details:
// doc/_nn/pia/lan/LanJoinSessionSetting.md
class LanJoinSessionSetting {
 public:
  void* mVtable;     // 0x00 - vptr 0x12dc0c8 (cell 0x1313308 + 0x10)
  uint64_t mZero08;  // 0x08 - zeroed by base C1 0x98324c
  uint32_t m10;      // 0x10 - zeroed by base C1 0x98324c
  uint16_t m14;      // 0x14 - zeroed by base C1 0x98324c
  uint8_t m16[0x2];  // 0x16 - tail pad to 0x18
};
}  // namespace nn::pia::lan
