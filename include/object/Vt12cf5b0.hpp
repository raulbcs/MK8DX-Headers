#pragma once

#include <cstdint>

// Vt12cf5b0 — interface row of a stub family sibling to Vt12ce1c8: 8-slot
// abstract table (never installed), stub row 0x12cf600, concrete row
// 0x12cf618 (54 slots) installed by ctor FUN_71008622f8.
// extent 0x638 - details: doc/object/Vt12cf5b0.md

namespace object {
class Vt12cf5b0 {
 public:
  void* vtable;       // 0x00 — concrete vptr 0x12cf618 (ctor 0x862324)
  char mPad8[0x630];  // 0x08 — managed by ctor FUN_71008622f8, unproven
};
}  // namespace object
