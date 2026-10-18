#pragma once

#include <cstdint>

// Vt12ba400 — PLACEHOLDER name; vptr 0x12ba400, 8 slots, no typeinfo (game-side).
// Derived from Vt12b6f58; secondary base vptr at +0x248, polymorphic member at +0x2e8.
// extent 0x308 - details: doc/object/Vt12ba400.md

namespace object {
class Vt12ba400 {
 public:
  void* mVtable;             // 0x00 — 0x12ba400 (via GOT cell 0x130e3a8, holds vt-0x10)
  uint8_t mBase8[0x240];     // 0x08 — padding, base Vt12b6f58 region
  void* mVtable248;          // 0x248 — secondary base vptr (cell 0x130e3a8 + 0x60)
  uint8_t mSub250[0x28];     // 0x250 — subobject initialized by 0x66a2a4 (before vptr overwrite)
  uint32_t mF_278;           // 0x278 — 1
  uint32_t mF_27c;           // 0x27c — 0
  void* mF_280;              // 0x280 — 0; virtually destroyed by D1
  uint64_t mPad288;          // 0x288 — padding, zeroed region remainder
  void* mF_290;              // 0x290 — 0
  void* mF_298;              // 0x298 — 0
  void* mF_2a0;              // 0x2a0 — 0
  void* mF_2a8;              // 0x2a8 — 0; virtually destroyed by D1
  void* mF_2b0;              // 0x2b0 — 0; virtually destroyed by D1
  uint32_t mF_2b8;           // 0x2b8 — 0 (count for +0x2c0 array)
  uint32_t mPad2bc;          // 0x2bc — padding, unproven
  void* mF_2c0;              // 0x2c0 — 0; operator-deleted by D1
  void* mF_2c8;              // 0x2c8 — 0; virtually destroyed by D1
  uint8_t mPad2d0[0x10];     // 0x2d0 — padding, zeroed region remainder
  void* mF_2e0;              // 0x2e0 — 0
  void* mVtable2e8;          // 0x2e8 — member subobject vptr (GOT cell 0x130e3b0 + 0x10)
  uint32_t mF_2f0;           // 0x2f0 — 1
  uint8_t mPad2f4[0x14];     // 0x2f4 — padding, rest of the object to 0x308
};
}  // namespace object
