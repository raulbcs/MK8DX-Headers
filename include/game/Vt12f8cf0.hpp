#pragma once

#include <cstdint>

// Vt12f8cf0 — PLACEHOLDER name; primary vptr row 0x12F8CF8 (typeinfo slot
// 0x12f8cf0, typeinfo object 0x12F8D30), ctor 0xB4A5E0; secondary vptr at
// +0x28. size 0x58 (lower bound: deepest store +0x50, unverified) -
// details: doc/game/Vt12f8cf0.md

namespace game {
class Vt12f8cf0 {
 public:
  void* mVtable;            // 0x00 — 0x12F8CF8 (via GOT cell 0x1315F70, holds row-8)
  uint32_t mField8;         // 0x08 — zeroed by base ctor 0x567CB8
  uint32_t mFieldC;         // 0x0C — zeroed by base ctor
  uint8_t mZero10[0x18];    // 0x10 — zeroed by base ctor (0x10..0x27)
  void* mVtable2;           // 0x28 — cell 0x1313040+0x10 = 0x12DB178
  uint8_t mPad30[0x8];      // 0x30 — unproven padding
  uint8_t mZero38[0x10];    // 0x38 — zeroed by ctor (0xB4A5F8 region)
  uint8_t mFlag48;          // 0x48 — zeroed by ctor
  uint8_t mPad49[0x7];      // 0x49 — unproven padding
  void* mPtr50;             // 0x50 — zeroed by ctor
};
}  // namespace game
