#pragma once

#include <cstdint>

// Vt12c2ed0 — PLACEHOLDER name (secondary interface). vptr 0x12c2ed0 (14
// slots), installed at [this+0x30] by C1 FUN_710078ef44; primary 0x12c2f40 at
// [this+0x00]. size 0x50 (operator new 0x50 in factory FUN_7100790050) -
// details: doc/object/Vt12c2ed0.md

namespace object {
class Vt12c2ed0 {
 public:
  void* mVtable;  // 0x00 — primary 0x12c2f40 (via GOT cell 0x130f638)
  uint8_t
      mPad8[0xC];        // 0x08 — unproven padding (slots read u32 state at +0x14)
  uint32_t mState14;     // 0x14 — state compared against 2 by slot 0 (unverified)
  uint8_t mPad18[0x10];  // 0x18 — unproven padding
  uint8_t mFlag28;       // 0x28 — bool, zeroed by ctor
  uint8_t mPad29[0x7];   // 0x29 — ctor writes nothing
  void* mVtable30;       // 0x30 — secondary 0x12c2ed0 (via GOT cell 0x130f640)
  uint64_t mZero38;      // 0x38 — zeroed by ctor (stp x8, xzr)
  void* mSelf40;         // 0x40 — set to this by ctor
  void* mOwner48;        // 0x48 — *(static via GOT cell 0x12fc0e70), set by ctor
};
}  // namespace object
