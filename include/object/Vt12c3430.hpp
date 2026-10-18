#pragma once



#include <cstdint>



// Vt12c3430 - PLACEHOLDER name (identity not proven). 10-slot member of the

// 6-vtable sibling family built by factory FUN_7100795178 (cell 0x130f718 =

// vt-0x10); factory case overrides the base vptr 0x12c39e0 with 0x12c3430

// then writes f32 -1.0, -1.0 at +0x2C.

// extent 0x38 (lower bound) - details: doc/object/Vt12c3430.md



class Vt12c3430 {

 public:

  void* vtable;       // 0x00 - 0x12c3430 (factory 0x795288..0x795294; base

                      //        ctor 0x7a4ee0 first installs 0x12c39e0)

  void* mField8;      // 0x08 - base ctor zeroes (0x7a4eec)

  void* mField10;     // 0x10 - base ctor zeroes (0x7a4eec)

  void* mField18;     // 0x18 - base ctor zeroes (0x7a4eec)

  void* mField20;     // 0x20 - base ctor zeroes (0x7a4ef4)

  uint32_t mField28;  // 0x28 - base ctor zeroes (0x7a4ee0)

  float mField2C;     // 0x2C - -1.0 (factory 0x795298)

  float mField30;     // 0x30 - -1.0 (factory 0x795298)

  uint8_t mPad34[4];  // 0x34 - unproven gap
};
