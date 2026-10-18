#pragma once

#include <cstdint>

// Vt12b1150 - PLACEHOLDER name; sibling of Vt12b1050 whose slots build
// an inverse matrix from the +0x98..+0xac float block (extent lower
// bound). extent 0xbc - details: doc/object/Vt12b1150.md

namespace object {
class Vt12b1150 {
 public:
  void* vtable;           // 0x00 - 0x12b1150 (GOT cell 0x130d538 holds
                          // 0x12b1140 = vt-0x10; no typeinfo row)
  uint8_t mFlag08;        // 0x08 - set to 1 by the C1
  uint8_t mFlag09;        // 0x09 - set to 1 by the C1
  char mPad0a[0x82];      // 0x0a..0x8b - unproven
  uint32_t mField8c;      // 0x8c - copied from global cell 0x130d510
  uint32_t mField90;      // 0x90 - copied from global cell 0x130d518
  uint32_t mField94;      // 0x94 - copied from global cell 0x130d520
  float mF98;             // 0x98 - ctor float arg
  float mF9c;             // 0x9c - ctor float arg
  float mFa0;             // 0xa0 - ctor float arg
  float mFa4;             // 0xa4 - ctor float arg
  float mFa8;             // 0xa8 - ctor float arg
  float mFac;             // 0xac - ctor float arg
  char mPadB0[0xc];       // 0xb0..0xbb - unproven (extent lower bound)
};
}  // namespace object
