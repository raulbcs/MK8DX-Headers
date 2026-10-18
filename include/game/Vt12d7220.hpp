#pragma once

#include <cstdint>

// Vt12d7220 — PLACEHOLDER name; vptr 0x12d7228 (row 0x12d7220 is the vt-8/descriptor slot,
// cell 0x1312178 holds 0x12d7218, installed vptr = cell+0x10). Descriptor slot = 0x12d74c0.
// extent 0x1a0 (operator-new size 0x1a0 at 0x8ffc3c) -
// details: doc/game/Vt12d7220.md

namespace game {
class Vt12d7220 {
 public:
  void* mVtable;         // 0x00 — 0x12d7228 (0x8ffc5c-0x8ffc80)
  uint8_t mPad8[0x98];   // 0x08 — unproven; initialized by base ctor 0x588b04 (0x8ffc58)
  uint32_t mFieldA0;     // 0xa0 — 0 (0x8ffc70)
  uint32_t mFieldA4;     // 0xa4 — 0x10 (0x8ffc64/0x8ffc70)
  uint8_t mPadA8[0x10];  // 0xa8 — zeroed (0x8ffc74)
  uint64_t mFieldB8;     // 0xb8 — 0 (0x8ffc88)
  void* mVtableC0;       // 0xc0 — GOT cell 0x130b618+0x10 (0x8ffc6c/0x8ffc7c)
  uint32_t mFlagC8;      // 0xc8 — release-store 1 (0x8ffc8c/0x8ffc90)
  uint8_t mPadCC[0xD4];  // 0xcc — unproven padding
};
}  // namespace game
