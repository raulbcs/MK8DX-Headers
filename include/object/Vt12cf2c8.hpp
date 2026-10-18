#pragma once

#include <cstdint>

// Vt12cf2c8 — interface row of a stub family sibling to Vt12ceb08: 8-slot
// abstract table (never installed), stub row 0x12cf318, concrete row
// 0x12cf330 (44 slots) installed by init entry 0x8610c8.
// extent 0x60 - details: doc/object/Vt12cf2c8.md

namespace object {
class Vt12cf2c8 {
 public:
  void* vtable;      // 0x00 — concrete vptr 0x12cf330 (init entry
                     //        0x8610c8, site 0x8610e4)
  char mPad8[0x58];  // 0x08 — managed by init FUN_7100860f2c, unproven
};
}  // namespace object
