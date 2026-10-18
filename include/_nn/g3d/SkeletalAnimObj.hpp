#pragma once

#include <cstdint>

namespace nn::g3d {
// RTTI-confirmed (typeinfo 0x12f1a40: nn::g3d::SkeletalAnimObj).
// AnimObj subclass; new(0x88) in FUN_71006a82fc, or 0xa8-stride array
// elements in FUN_71006a2c24; no standalone C1.
// extent 0x88 - details: doc/_nn/g3d/SkeletalAnimObj.md
class SkeletalAnimObj {
 public:
  void* vtable;          // 0x00 - vptr 0x12f19f8 (GOT cell 0x130df70 holds
                         // 0x12f19e8 = vptr-0x10; typeinfo slot 0x12f19f0)
  void* mSelf08;         // 0x08 - = this+0x10 (base ctor self-pointer)
  uint32_t m10;          // 0x10 - zeroed word by base ctor 0xa6edc4
  uint32_t m14;          // 0x14 - zeroed
  uint32_t m18;          // 0x18 - zeroed
  float m1C;             // 0x1c - = 1.0f
  void* m20;             // 0x20 - raw GOT cell 0x1314f58 value 0xa6ec0c
                         // (.text table; role unverified)
  uint64_t m28;          // 0x28 - zeroed
  uint8_t mPad30[0x20];  // 0x30..0x4f - unproven
  uint64_t m50;          // 0x50 - zeroed by base ctor
  uint8_t mPad58[0x10];  // 0x58..0x67 - unproven
  uint64_t m68;          // 0x68 - zeroed by derived init
  uint8_t mPad70[0x10];  // 0x70..0x7f - unproven
  uint64_t m80;          // 0x80 - zeroed by derived init
};
}  // namespace nn::g3d
