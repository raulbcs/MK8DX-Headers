#pragma once

#include <cstdint>

// Vt12f34c8 — PLACEHOLDER name; vptr 0x12f34c8, n=7, primary table; large
// object with a secondary row 0x12f3510 (offset unverified).
// extent 0x7B0 - lower bound (deepest ctor store +0x7A8); unverified -
// details: doc/object/Vt12f34c8.md

namespace object {
class Vt12f34c8 {
 public:
  void* mVtable;            // 0x00 — 0x12f34c8 (via GOT cell 0x13152E8)
  uint8_t mPad8[0x798];     // 0x08 — unproven padding (ctor body 0xABE640-0xABE6B4)
  uint16_t mFlags7A0;       // 0x7A0 — OR-writes of 0x80 and halfword stores
  uint8_t mPad7A2[0x6];     // 0x7A2 — unproven padding
  uint8_t mSub7A8[0x8];          // 0x7A8 — constructed subobject via 0x654990
};
}  // namespace object
