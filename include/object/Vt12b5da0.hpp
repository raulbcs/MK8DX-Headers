#pragma once

#include <cstdint>

// Vt12b5da0 - PLACEHOLDER name (KartParamCacheGroup-derived cache variant;
// ctor 0x6958c8 chains KartParamCacheGroup ctor 0x64a708). Secondary vtable
// 0x12b5e28 lives at [this+0x40].
// extent 0xad8 - details: doc/object/Vt12b5da0.md

namespace object {
class Vt12b5da0 {
 public:
  void* vtable;        // 0x00 - installed 0x12b5da0 (cell 0x130de98)
  char mPad08[0x30];   // 0x08..0x37 - KartParamCacheGroup base body
  void* mSecA_38;      // 0x38 - secondary vptr 0x12b5e08 (off-to-top -0x38)
  void* mSecB_40;      // 0x40 - secondary vptr 0x12b5e28 (off-to-top -0x40)
  char mPad48[0x120];  // 0x48..0x167 - base-group tail (unproven)
  uint64_t mZero_168;  // 0x168 - zeroed by ctor
  uint64_t mZero_170;  // 0x170 - zeroed by ctor
  uint32_t mZero_178;  // 0x178 - zeroed by ctor
  uint32_t mZero_17c;  // 0x17c - padding
  uint64_t mZero_180;  // 0x180 - zeroed by ctor
  char mPad188[0x1c8];  // 0x188..0x34f - member inited by 0x645410 (unproven)
  char mPad350[0x180];  // 0x350..0x4cf - member inited by 0x643fa0 (unproven)
  char mPad4d0[0x310];  // 0x4d0..0x7df - flags/records written by ctor
  void* mSlot7e0_7e0;  // 0x7e0 - read by D1 0x695e90 (array-ish pointer)
  char mPad7e8[0x2f0];  // 0x7e8..0xad7 - tail (unproven)
};
}  // namespace object
