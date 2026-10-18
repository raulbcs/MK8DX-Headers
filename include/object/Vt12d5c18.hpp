#pragma once

#include <cstdint>

// Vt12d5c18 - PLACEHOLDER name; 0x30 state object stored at [mgr+0x1368] by
// the crown-state builder FUN_71000d2d58 (strings "CrownDest"/"Angry").
// extent 0x30 - details: doc/object/Vt12d5c18.md

namespace object {

class Vt12d5c18 {
 public:
  void* mVtable;        // 0x00 - 0x12d5c18 (GOT cell 0x12fce08 holds 0x12d5c08
                       //        = vt-0x10; no typeinfo row, ot = 0)
  char mPad08[0x4];    // 0x08..0x0b - unproven
  float mF0c;          // 0x0c - 0xcccd3e4c (~-1.076e8, bit pattern 0xcccd3e4c) by the creator
  float mF10;          // 0x10 - same constant
  uint32_t mField14;   // 0x14 - creator store
  char mPad18[0x4];    // 0x18..0x1b - unproven
  uint32_t mField1c;   // 0x1c - creator store
  char mPad20[0x8];    // 0x20..0x27 - unproven
  uint32_t mField28;   // 0x28 - creator store
  char mPad2c[0x4];    // 0x2c..0x2f - unproven
};

}  // namespace object
