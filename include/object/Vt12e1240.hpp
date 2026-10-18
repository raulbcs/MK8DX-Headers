#pragma once

#include <cstdint>

// Vt12e1240 — polymorphic MI object (vptr 0x12e1248, 5 slots, GOT cell 0x1313ea8 holds vptr-0x10).
// C1 0x9cbfb4 installs primary at +0 and secondary 0x12e1280 at +0x10; factory new 0x600 at 0x9be2b8.
// extent 0x600 (operator-new size at factory 0x9be2a4) -
// details: doc/object/Vt12e1240.md

namespace object {
class Vt12e1240 {
 public:
  void* mVtable;          // 0x00 — 0x12e1248 (primary)
  uint8_t mPad8[0x8];     // 0x08 — unproven padding
  void* mVtable2;         // 0x10 — 0x12e1280 (secondary, offset-to-top -0x10, thunks 0x9cc01c/0x9cc070)
  uint8_t mPad18[0x5E8];  // 0x18 — unproven padding
};
}  // namespace object
