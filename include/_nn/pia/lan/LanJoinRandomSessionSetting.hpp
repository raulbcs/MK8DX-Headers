#pragma once

#include <cstdint>

namespace nn::pia::lan {
// LanJoinRandomSessionSetting — RTTI-named (typeinfo 0x12dc0a0, name
// "N2nn3pia3lan27LanJoinRandomSessionSettingE"). 11 slots; GOT cell
// 0x1313300 holds vptr-0x10 (vptr 0x12dc048).
// extent 0x680 - details: doc/_nn/pia/lan/LanJoinRandomSessionSetting.md
class LanJoinRandomSessionSetting {
 public:
  void* mVtable;          // 0x00 - vptr 0x12dc048 (cell 0x1313300 + 0x10)
  void* mSubobject08;     // 0x08 - subobject vptr (C1 0x96c32c; D-tor tail
                          //   0x96c41c family)
  uint8_t mPad10[0x1b8];  // 0x10 - unproven subobject body
  void* mMember1c8;       // 0x1c8 - member subobject (C1 0x973a74, virtual
                          //   call [x8,#0x18] in C1 tail)
  uint8_t mPad1d0[0x250]; // 0x1d0 - unproven
  void* mMember420;       // 0x420 - member subobject (C1 0x973a74)
  uint8_t mPad428[0x250]; // 0x428 - unproven
  uint32_t m678;          // 0x678 - C1 stores 0 (0x96c920); last field
  uint8_t mPad67c[0x4];   // 0x67c - tail padding to 0x680
};
}  // namespace nn::pia::lan
