#pragma once

#include <cstdint>

// Vt12d71a0 — PLACEHOLDER name; vptr 0x12d71a8 (row 0x12d71a0 is the vt-8/descriptor slot,
// cell 0x1312140 holds 0x12d7198, installed vptr = cell+0x10). Descriptor slot = 0x12d74a0.
// extent 0x1c0 (operator-new size 0x1c0 at 0x8fe3c8) -
// details: doc/game/Vt12d71a0.md

namespace game {
class Vt12d71a0 {
 public:
  void* mVtable;         // 0x00 — 0x12d71a8 (0x8fe3e8-0x8fe40c)
  uint8_t mPad8[0x98];   // 0x08 — unproven; initialized by base ctor 0x588b04 (0x8fe3e4)
  uint32_t mFieldA0;     // 0xa0 — 0 (0x8fe3fc)
  uint32_t mFieldA4;     // 0xa4 — 0x10 (0x8fe3f0/0x8fe3fc)
  uint8_t mPadA8[0x10];  // 0xa8 — zeroed (0x8fe400)
  uint64_t mFieldB8;     // 0xb8 — 0 (0x8fe414)
  void* mVtableC0;       // 0xc0 — GOT cell 0x130b618+0x10 (0x8fe3f8/0x8fe408)
  uint32_t mFlagC8;      // 0xc8 — release-store 1 (0x8fe418/0x8fe41c)
  uint8_t mByteCC;       // 0xcc — 0 (0x8fe420)
  uint8_t mPadCD[0xF3];  // 0xcd — unproven padding
};
}  // namespace game
