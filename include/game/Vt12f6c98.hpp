#pragma once

#include <cstdint>

// Vt12f6c98 — PLACEHOLDER name; secondary-base vtable row 0x12f6ca0 (typeinfo
// slot 0x12f6c98), installed at this+0xA0 of the complete class (primary row
// 0x12f6c08 via GOT cell 0x1315900; third vptr at +0x2B8).
// extent 0x320 (complete object) - details: doc/game/Vt12f6c98.md

namespace game {
class Vt12f6c98 {
 public:
  void* mVtable;            // 0x00 — 0x12f6c08 (primary)
  uint8_t mPad8[0x98];      // 0x08 — unproven padding
  void* mVtable2;           // 0xA0 — 0x12f6ca0 (assigned secondary row 0x12f6c98+8)
  uint8_t mPadA8[0x210];    // 0xA8 — unproven padding
  void* mVtable3;           // 0x2B8 — cell 0x1315910+0x10 (secondary D0 path 0xB26844)
  uint8_t mPad2C0[0x60];    // 0x2C0 — unproven padding
};
}  // namespace game
