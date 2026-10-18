#pragma once

#include <cstdint>

// Vt12da460 - PLACEHOLDER name; nn::pia-region job object over base 0x9a2264
// with three embedded members (+0x80/+0xb8/+0x138); vptr 0x12da468.
// extent 0x158 - details: doc/object/Vt12da460.md

namespace object {
class Vt12da460 {
 public:
  void* vtable;        // 0x00 - 0x12da468 (C1 0x93603c; GOT cell 0x13129b8
                       // holds 0x12da458 = vt-0x8, vptr = cell+0x10)
  char mPad8[0x48];    // 0x08 - base region (base member ctor 0x9a2264 runs on
                       // this at C1 entry; D-tail base dtor 0x9a22a8)
  void* mPtr50;        // 0x50 - ctor stores 0x800 (0x93606c..0x936070)
  char mPad58[0x28];   // 0x58 - unproven
  char mMember80[0x38];    // 0x80 - 0x9b38b8-class member (0x30-ish fields +
                           // sub-member at +0x30); dtor 0x9b3a40
  char mMemberB8[0x70];    // 0xb8 - pair of 0x38 members via 0x9b1fe8 (two
                           // 0x9b38b8-class objects); dtor 0x9b20b4
  uint8_t mPad128[8]; // 0x128 - unproven gap
  void* mPtr130;       // 0x130 - ctor nulls (0x936064)
  char mMember138[0x20];   // 0x138 - 0x929ec0-class member (ptr pair + flag);
                           // dtors 0x929f78/0x929ed0/0x929ee0
};
}  // namespace object
