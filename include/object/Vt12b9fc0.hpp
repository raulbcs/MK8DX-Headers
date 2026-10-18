#pragma once

#include <cstdint>

// Vt12b9fc0 — PLACEHOLDER name; vptr 0x12b9fc0, 8 slots, no typeinfo (game-side).
// Derived from Vt12b6f58; secondary base vptr at +0x248 (row 0x12ba010).
// extent 0x300 - details: doc/object/Vt12b9fc0.md

namespace object {
class Vt12b9fc0 {
 public:
  void* mVtable;             // 0x00 — 0x12b9fc0 (via GOT cell 0x130e2a8, holds vt-0x10)
  uint8_t mBase8[0x240];     // 0x08 — padding, base Vt12b6f58 region
  void* mVtable248;          // 0x248 — secondary base vptr, row 0x12ba010 (cell + 0x60)
  uint8_t mSub250[0x28];     // 0x250 — subobject initialized by 0x66a2a4 (before vptr overwrite)
  uint8_t mSub278[0x58];     // 0x278 — memset 0 block
  float mF_2d0;              // 0x2d0 — 1.0f
  uint32_t mPad2d4;          // 0x2d4 — padding, unproven
  void* mF_2d8;              // 0x2d8 — 0
  uint8_t mPad2e0[0x10];     // 0x2e0 — padding, zeroed region remainder
  void* mF_2f0;              // 0x2f0 — 0; virtually destroyed by D1
  void* mF_2f8;              // 0x2f8 — 0; virtually destroyed by D1
};
}  // namespace object
