#pragma once

#include <cstdint>

// Vt12ced30 — PLACEHOLDER name; vptr 0x12ced30, 53 slots, GOT cell 0x1310e88.
// Base of Vt12ceb70 (identical layout, same size 0x680); C1 allocates a counted
// 0x130-byte-element array at +0x80.
// extent 0x680 (via only derived Vt12ceb70) - details: doc/object/Vt12ced30.md

namespace object {
class Vt12ced30 {
 public:
  void* mVtable;            // 0x00 — 0x12ced30 (via GOT cell 0x1310e88)
  uint8_t mPad8[0x58];      // 0x08 — unproven padding
  uint32_t mField60;        // 0x60 — ctor arg w2 (mode/count, unverified)
  uint8_t mPad64[0x1C];     // 0x64 — unproven padding (zeroed +0x70 block)
  void* mArray80;           // 0x80 — new count*0x130 elements (C1 0x85d4cc-0x85d4e4)
  uint8_t mPad88[0x5F8];    // 0x88 — unproven padding to 0x680
};
}  // namespace object
