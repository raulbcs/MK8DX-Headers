#pragma once

#include <cstdint>

// Vt12e2ec8 — PLACEHOLDER name (nn websocket/http-style connection); installed vptr 0x12e2ed0,
// 7 slots; GOT cell 0x1314340 holds vptr-0x10 (0x12e2ec8 is the typeinfo slot, typeinfo 0x12e4130).
// size 0x58 (operator new at 0x9F0AD8) -
// details: doc/object/Vt12e2ec8.md

namespace object {
class Vt12e2ec8 {
 public:
  void* mVtable;         // 0x00 — 0x12e2ed0 (via GOT cell 0x1314340)
  uint8_t mPad8[0x4];    // 0x08 — unproven
  uint8_t mC;            // 0x0C — zeroed by ctor
  uint8_t mD;            // 0x0D — zeroed by ctor
  uint8_t mE;            // 0x0E — zeroed by ctor
  uint8_t mPadF[0x1];    // 0x0F — unproven
  void* m10;             // 0x10 — ctor arg x2 (owner/context ptr)
  uint8_t mPad18[0x8];   // 0x18 — unproven ([0x18]=0xFF by ctor per raw byte store)
  uint8_t mPad20[0x18];  // 0x20 — unproven ([0x28] zeroed by ctor)
  void* mVtable2;        // 0x38 — embedded member vptr (GOT cell 0x1314348 -> 0x12E4D08+0x10)
  uint16_t m40;          // 0x40 — zeroed by ctor
  uint8_t mPad42[0x6];   // 0x42 — unproven
  void* m48;             // 0x48 — zeroed by caller 0x9F0B04
  void* m50;             // 0x50 — owner ptr stored by caller 0x9F0B08
};
}  // namespace object
