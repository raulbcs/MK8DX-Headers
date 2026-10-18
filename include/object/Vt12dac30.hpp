#pragma once

#include <cstdint>

// Vt12dac30 - PLACEHOLDER name; nn::pia-region job object over base 0x97dc58
// with a 0x929ec0-class member at +0x60; vptr 0x12dac38, 9 slots.
// extent 0x90 (lower bound) - details: doc/object/Vt12dac30.md

namespace object {
class Vt12dac30 {
 public:
  void* vtable;       // 0x00 - 0x12dac38 (C1 0x93bbcc; GOT cell 0x1312b98
                      // holds 0x12dac28 = vt-0x8, vptr = cell+0x10)
  char mPad8[0x58];   // 0x08 - base region (base member ctor 0x97dc58 runs on
                      // this at C1 entry; D-tail base dtor 0x97dc8c)
  char mMember60[0x20];  // 0x60 - 0x929ec0-class member (ptr pair + flag
                         // byte); dtor 0x929ee0
  void* mPtr80;       // 0x80 - ctor nulls (0x93bbec)
  uint32_t mField88;  // 0x88 - ctor zeroes (0x93bbf0)
  char mPad8c[0x4];   // 0x8c - unproven padding to 0x90
};
}  // namespace object
