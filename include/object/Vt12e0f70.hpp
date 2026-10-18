#pragma once

#include <cstdint>

// Vt12e0f70 - PLACEHOLDER name; nn::ldn job-region object (D1 tail shares
// FUN_71009cd3c0 with LocalBackgroundProcessJob). 14-slot primary table.
// extent 0x310 - details: doc/object/Vt12e0f70.md

namespace object {
class Vt12e0f70 {
 public:
  void* vtable;              // 0x00 - 0x12e0f78 (GOT cell 0x1313e38 holds
                             // 0x12e0f68 = vt-0x8; installed = cell+0x10)
  uint8_t mPad08[0xa8];      // 0x08 - unproven padding (ctor zeroes +0xc/+0xc0)
  void* mMemberVtable_b0;    // 0xb0 - 0x12d7fc8 (GOT cell 0x1312478 holds
                             // 0x12d7fb8 = vt-0x8; member at +0xb0)
  void* mMemberField_b8;     // 0xb8 - ctor stores 0
  uint8_t mPadC0[0x4];       // 0xc0 - ctor zeroes u32
  uint8_t mBufferC4[0x40];   // 0xc4 - memset 0x40 (0x9c9e2c-0x9c9e3c)
  uint8_t mField104;         // 0x104 - ctor zeroes byte
  uint8_t mBuffer105[0x180]; // 0x105 - memset 0x180 (0x9c9e40-0x9c9e4c)
  uint8_t mZeroed285[0xb];   // 0x285 - ctor zeroes +0x288 u32 and +0x28c u16
  uint64_t mField290;        // 0x290 - ctor stores 0
  uint32_t mField298;        // 0x298 - ctor zeroes
  uint32_t mField29c;        // 0x29c - ctor zeroes
  uint64_t mField2a0;        // 0x2a0 - ctor stores 0
  uint32_t mField2a8;        // 0x2a8 - ctor zeroes
  uint8_t mPad2ac[0x40];     // 0x2ac - unproven padding
  uint8_t mField2ec;         // 0x2ec - ctor zeroes byte
  uint8_t mPad2ed[0x23];     // 0x2ed - unproven padding to extent
};
}  // namespace object
