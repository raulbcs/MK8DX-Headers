#pragma once

#include <cstdint>

namespace nn::pia::session {
// JoinSessionSetting — RTTI-named (typeinfo 0x12ddce0, name
// "N2nn3pia7session18JoinSessionSettingE"; root typeinfo, no base).
// 9 slots; GOT cell 0x1313790 holds vptr-0x10 (vptr 0x12ddc98).
// extent 0x18 - details: doc/_nn/pia/session/JoinSessionSetting.md
class JoinSessionSetting {
 public:
  void* mVtable;     // 0x00 - vptr 0x12ddc98 (cell 0x1313790 + 0x10)
  void* m08;         // 0x08 - ptr, setter slot 7 = 0x983270 (C1 zero-inits)
  uint32_t m10;      // 0x10 - u32, setter slot 3 = 0x983280 (C1 zero-inits)
  uint16_t m14;      // 0x14 - u16, setter slot 5 = 0x9832ac (C1 zero-inits)
  uint8_t m16[0x2];  // 0x16 - tail pad to 0x18
};
}  // namespace nn::pia::session
