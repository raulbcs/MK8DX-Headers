#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed: typeinfo slot 0x12f5808 -> record 0x12f5850 {0x10, name
// 0xf88800 = N2nn3nex14_DDL_GatheringE, base 0x128c3b0 = nn::nex::RootObject,
// 0x10}. Internal DDL gathering-record class (matchmake gathering schema).
// extent 0x40 (lower bound; upper unproven) - details: doc/_nn/nex/_DDL_Gathering.md
class _DDL_Gathering {
 public:
  void* vtable;          // 0x00 - vptr 0x12f5810 (GOT cell 0x1315778 holds
                         // 0x12f5800 = vptr-0x10; off-top 0)
  uint8_t mPad8[0x30];   // 0x08 - unproven gap
  void* mField38;        // 0x38 - RootObject-family subobject: ctor sites
                         // 0xb14e9c/0xb1553c install GOT cell 0x130b4a8
                         // (+0x10) here
};
}  // namespace nn::nex
