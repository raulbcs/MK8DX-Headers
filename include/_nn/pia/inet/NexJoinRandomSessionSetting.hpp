#pragma once

#include <cstdint>

namespace nn::pia::inet {
// NexJoinRandomSessionSetting — RTTI-named (typeinfo 0x12d9910, name
// "N2nn3pia4inet27NexJoinRandomSessionSettingE"). 11 slots; GOT cell
// 0x13128c8 holds vptr-0x10 (vptr 0x12d98a8).
// extent 0x2078 - details: doc/_nn/pia/inet/NexJoinRandomSessionSetting.md
class NexJoinRandomSessionSetting {
 public:
  void* mVtable;            // 0x00 - vptr 0x12d98a8 (cell 0x13128c8 + 0x10;
                            //   cell holds vptr-0x10 = 0x12d9898)
  void* mSubobject08;       // 0x08 - subobject vptr (C1 0x92b5f0 sets it;
                            //   D 0x92ba5c tears it down)
  uint8_t mPad10[0x620];    // 0x10 - unproven subobject body
  void* mMember630;         // 0x630 - member subobject (C1 0x933694, D
                            //   0x933b28)
  uint8_t mPad638[0xd18];   // 0x638 - unproven
  void* mMember1350;        // 0x1350 - member subobject (C1 0x933694, D
                            //   0x933b28)
  uint8_t mPad1358[0xd18];  // 0x1358 - unproven
  uint32_t m2070;           // 0x2070 - C1 stores 0 (0x92ea6c)
  uint16_t m2074;           // 0x2074 - C1 stores 0x101 (0x92ea68/70)
  uint8_t m2076;            // 0x2076 - C1 stores 0 (0x92ea7c)
  uint8_t mPad2077;         // 0x2077 - tail padding to 0x2078
};
}  // namespace nn::pia::inet
