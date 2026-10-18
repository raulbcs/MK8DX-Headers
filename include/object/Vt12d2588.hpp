#pragma once

#include <cstdint>

// Vt12d2588 - PLACEHOLDER name; intrusive list node registered on a manager
// member at +0x178 by wrapper FUN_71003de7ac (alloc 0x50).
// extent 0x50 - details: doc/object/Vt12d2588.md

namespace object {

class Vt12d2588 {
 public:
  void* mVtable;        // 0x00 - 0x12d2588 (GOT cell 0x1311568 holds 0x12d2578
                       //        = vt-0x10; no typeinfo row, ot = 0)
  char mPad08[0x30];   // 0x08..0x37 - unproven
  void* mField38;      // 0x38 - zeroed by C1
  uint32_t mField40;   // 0x40 - zeroed by C1
  char mPad44[0x4];    // 0x44..0x47 - unproven
  void* mField48;      // 0x48 - zeroed by C1
};

}  // namespace object
