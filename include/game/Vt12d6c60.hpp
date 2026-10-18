#pragma once

#include <cstdint>

// Vt12d6c60 — PLACEHOLDER name; secondary vtable (offset-to-top -0x90) of a 0x108
// factory product in the Vt12d6xxx directive family; primary vptr 0x12d6cf8.
// extent 0x108 (operator-new size 0x108 at 0x8efc24) -
// details: doc/game/Vt12d6c60.md

namespace game {
class Vt12d6c60 {
 public:
  void* mVtable;         // 0x00 — primary vptr 0x12d6cf8 (GOT cell 0x1311fb8+0x10, 0x8efc78)
  uint8_t mPad8[0x20];   // 0x08 — unproven padding (base ctor 0x738d68)
  void* mSub28;          // 0x28 — pointer to the +0x80 subobject (0x8efc74)
  uint8_t mPad30[0x40];  // 0x30 — unproven padding
  uint8_t mByte70;       // 0x70 — 0 (0x8efc60)
  uint8_t mByte71;       // 0x71 — 1 (0x8efc50)
  uint8_t mPad72[0x6];   // 0x72 — unproven padding
  uint64_t mField78;     // 0x78 — 0 (0x8efc54)
  void* mVtable80;       // 0x80 — 0x12d6e58 (header form; = Vt12d6e58 row, 0x8efc7c)
  void* mOwner88;        // 0x88 — back-pointer to this (0x8efc84)
  uint8_t mPad90[0x78];  // 0x90 — unproven padding
};
}  // namespace game
