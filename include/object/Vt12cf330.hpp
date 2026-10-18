#pragma once

#include <cstdint>

// Vt12cf330 — PLACEHOLDER name; vptr 0x12cf330, 44 slots, typeinfo NULL (game-side).
// Ctor 0x8610c8 installs the vptr via GOT cell 0x1310ed0 (cell = vt-0x10).
// extent 0x60 - details: doc/object/Vt12cf330.md

namespace object {
class Vt12cf330 {
 public:
  void* mVtable;        // 0x00 — 0x12cf330 (via GOT cell 0x1310ed0)
  uint8_t mPad8[0x58];  // 0x08 — unproven padding (base ctor FUN_7100861ef0)
};
}  // namespace object
