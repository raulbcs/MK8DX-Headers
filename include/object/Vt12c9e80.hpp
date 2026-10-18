#pragma once

#include <cstdint>

namespace object {

// Vt12c9e80 - PLACEHOLDER name; derived engine-family class (base C1
// 0x86838c installs vptr 0x12cf7d0; embeds the Vt12c93a8 engine member at
// +0xf0). Factory chain: new 0x3d0 at 0x1100b8 builds a further-derived
// object. extent 0x1a0+ (lower bound) - details: doc/object/Vt12c9e80.md

class Vt12c9e80 {
 public:
  void* vtable;               // 0x00 - 0x12c9e80; GOT cell 0x13103f8 holds
                              // 0x12c9e70 = vt-0x10
  uint8_t mPad08[0xe8];       // 0x08 - base body (base C1 0x86838c memsets
                              // +0x08..0x58 and builds list heads at
                              // +0x58/+0x7c/+0x88; unproven interior)
  char mSubF0[0x30];          // 0xf0 - engine member, C 0x7b976c (installs
                              // vptr 0x12c93a8), dtor 0x7b978c
  uint8_t mPad120[0x10];      // 0x120 - unproven
  uint32_t mField130;         // 0x130 - ctor 0x01000000 (0x71007f87a8)
  uint8_t mPad134[0x8];       // 0x134 - unproven
  uint8_t mField13c[0x8];     // 0x13c - ctor zeroes (0x71007f87d8)
  uint8_t mField144[0x8];     // 0x144 - ctor zeroes (0x71007f87d0)
  uint8_t mListHead14c[0x8];  // 0x14c - empty-list head, points at itself
                              // (0x71007f87b8/0x71007f87c4)
  uint32_t mField154;         // 0x154 - ctor zeroes (0x71007f87bc)
  uint8_t mPad158[0x48];      // 0x158 - ctor writes up to +0x19c
                              // (unproven interior)
};

}  // namespace object
