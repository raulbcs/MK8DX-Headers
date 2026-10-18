#pragma once

#include <cstdint>

// Vt12c3490 - PLACEHOLDER name (identity not proven). 10-slot member of the
// 6-vtable sibling family built by factory FUN_7100795178 (cell 0x130f6f8 =
// vt-0x10); factory case overrides the base vptr 0x12c39e0 with 0x12c3490
// and writes no extra fields.
// extent 0x30 (lower bound) - details: doc/object/Vt12c3490.md

class Vt12c3490 {
 public:
  void* vtable;       // 0x00 - 0x12c3490 (factory 0x795218..0x795228; base
                      //        ctor 0x7a4ee0 first installs 0x12c39e0)
  void* mField8;      // 0x08 - base ctor zeroes (0x7a4eec)
  void* mField10;     // 0x10 - base ctor zeroes (0x7a4eec)
  void* mField18;     // 0x18 - base ctor zeroes (0x7a4eec)
  void* mField20;     // 0x20 - base ctor zeroes (0x7a4ef4)
  uint32_t mField28;  // 0x28 - base ctor zeroes (0x7a4ee0)
  char mPad2C[0x4];   // 0x2C - unproven (sibling subtypes write -1 here)
};
