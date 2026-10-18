#pragma once

#include <cstdint>

// Vt12f6ae8 — PLACEHOLDER name; secondary-base vtable row 0x12f6af0 (typeinfo
// slot 0x12f6ae8), installed at this+0xA0 of the complete class (primary row
// 0x12f6a58 via GOT cell 0x1315960).
// extent 0x2B0 (complete object) - details: doc/game/Vt12f6ae8.md

namespace game {
class Vt12f6ae8 {
 public:
  void* mVtable;            // 0x00 — 0x12f6a58 (primary)
  uint8_t mPad8[0x98];      // 0x08 — unproven padding
  void* mVtable2;           // 0xA0 — 0x12f6af0 (assigned secondary row 0x12f6ae8+8)
  uint8_t mPadA8[0x208];    // 0xA8 — unproven padding
};
}  // namespace game
