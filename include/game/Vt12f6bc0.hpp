#pragma once

#include <cstdint>

// Vt12f6bc0 — PLACEHOLDER name; secondary-base vtable row 0x12f6bc8 (typeinfo
// slot 0x12f6bc0), installed at this+0xA0 of the complete class (primary row
// 0x12f6b30 via GOT cell 0x1315920).
// extent 0x2D0 (complete object) - details: doc/game/Vt12f6bc0.md

namespace game {
class Vt12f6bc0 {
 public:
  void* mVtable;            // 0x00 — 0x12f6b30 (primary)
  uint8_t mPad8[0x98];      // 0x08 — unproven padding
  void* mVtable2;           // 0xA0 — 0x12f6bc8 (assigned secondary row 0x12f6bc0+8)
  uint8_t mPadA8[0x228];    // 0xA8 — unproven padding
};
}  // namespace game
