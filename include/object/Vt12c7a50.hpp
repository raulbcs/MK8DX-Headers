#pragma once

#include <cstdint>

// Vt12c7a50 — PLACEHOLDER name; vptr 0x12c7a50, >=31 slots, no RTTI
// (typeinfo slot holds shared no-op marker 0x7cae38). Base of Vt12d6088.
// extent 0x3a0 - details: doc/object/Vt12c7a50.md

namespace object {
class Vt12c7a50 {
 public:
  void* mVtable;           // 0x00 — 0x12c7a50
  uint32_t m28;            // 0x28 — flags (test/ori #1 in slot thunk 0x7cae44)
  uint8_t mPad8[0x20];     // 0x08 — init by 0x7c6aec; 1.0f triplet +0x2c/+0x34/+0x3c..0x5c
  uint8_t mPad2c[0x334];   // 0x2c — floats + zeroes through +0x360
  uint8_t mPad360[0x18];   // 0x360 — zeroed by init thunk (0x7c6b20-0x7c6b2c)
  void* m378;              // 0x378 — zeroed by C2
  void* m380;              // 0x380 — zeroed by C2
  void* m388;              // 0x388 — self-pointer stored by C2 (0x7cae18)
  void* m390;              // 0x390 — zeroed by C2
  uint32_t m398;           // 0x398 — zeroed by C2
  uint8_t mPad39c[0x4];    // 0x39c — unproven padding
};
}  // namespace object
