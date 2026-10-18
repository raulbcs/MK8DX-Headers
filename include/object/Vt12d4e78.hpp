#pragma once

#include <cstdint>

namespace object {
// Vt12d4e78 — PLACEHOLDER name (identity not proven); singleton-flavoured
// game class. vptr 0x12d4e78 (GOT cell 0x1311b90 holds vt-0x10, row header
// zeros). C1 0x8c7288 takes (this, ?, ?, x3) and stores x3 at +0x48; size
// proven by the allocating factory (operator new 0x50, align 8, 0x8cb068).
// extent 0x50 - details: doc/object/Vt12d4e78.md
class Vt12d4e78 {
 public:
  void* vtable;          // 0x00 — 0x12d4e78 (cell 0x1311b90 + 0x10)
  uint8_t mBase08[0x40]; // 0x08 — base region (base ctor 0x7440b8); unproven
  void* mPtr48;          // 0x48 — C1 stores its x3 argument (0x8c72a8)
};
}  // namespace object
