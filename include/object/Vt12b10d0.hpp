#pragma once

#include <cstdint>

// Vt12b10d0 - PLACEHOLDER name; sibling of Vt12b1050 (extent lower
// bound, three C1 overloads incl. half-extent builder FUN_710062c8b0).
// extent 0xbc - details: doc/object/Vt12b10d0.md

namespace object {
class Vt12b10d0 {
 public:
  void* vtable;           // 0x00 - 0x12b10d0 (GOT cell 0x130d530 holds
                          // 0x12b10c0 = vt-0x10; no typeinfo row)
  uint8_t mFlag08;        // 0x08 - set to 1 by the C1 overloads
  uint8_t mFlag09;        // 0x09 - set to 1 by the default C1 only
  char mPad0a[0x82];      // 0x0a..0x8b - unproven
  uint32_t mField8c;      // 0x8c - copied from global cell 0x130d510
  uint32_t mField90;      // 0x90 - copied from global cell 0x130d518
  uint32_t mField94;      // 0x94 - copied from global cell 0x130d520
  float mF98;             // 0x98 - ctor arg / 1.0 (default) / mid x
  float mF9c;             // 0x9c - ctor arg / 0.5 (default) / mid y
  float mFa0;             // 0xa0 - ctor arg / half-extent x
  float mFa4;             // 0xa4 - ctor arg / -half-extent y
  float mFa8;             // 0xa8 - ctor arg / half-extent z
  float mFac;             // 0xac - ctor arg / -half-extent z
  char mPadB0[0xc];       // 0xb0..0xbb - unproven (extent lower bound)
};
}  // namespace object
