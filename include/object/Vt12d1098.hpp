#pragma once

#include <cstdint>

// Vt12d1098 - PLACEHOLDER name; intrusive node created in pairs by the
// FUN_710087xxxx container builder, three 9-entry sub-tables at +0x40..+0x57.
// extent 0x60 - details: doc/object/Vt12d1098.md

namespace object {

class Vt12d1098 {
 public:
  void* mVtable;        // 0x00 - 0x12d1098 (GOT cell 0x1311198 holds 0x12d1088
                       //        = vt-0x10; no typeinfo row, ot = 0)
  char mPad08[0x30];   // 0x08..0x37 - unproven
  void* mField38;      // 0x38 - zeroed by C1
  void* mSub40;        // 0x40 - sub-object #1, init 0x888c30(9, 0x3b, 999)
  void* mSub48;        // 0x48 - sub-object #2, init 0x888c30(9, 0x3b, 999)
  void* mSub50;        // 0x50 - sub-object #3, init 0x888c30(9, 0x3b, 999)
  uint8_t mFlag58;     // 0x58 - set to 1 by C1
  char mPad59[0x7];    // 0x59..0x5f - unproven
}  // namespace object
