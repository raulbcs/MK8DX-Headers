#pragma once

#include <cstdint>

// Vt12f3260 — PLACEHOLDER name; vptr 0x12f3260, n=7, primary table; base of
// Vt12f30b0 (slots 2-6 shared); also embedded as a member elsewhere.
// extent 0x630 - lower bound (deepest member init +0x628); unverified -
// details: doc/object/Vt12f3260.md

namespace object {
class Vt12f3260 {
 public:
  void* mVtable;            // 0x00 — 0x12f3260 (via GOT cell 0x13152A8)
  uint8_t mPad8[0x190];     // 0x08 — unproven padding
  uint8_t mFlag198;         // 0x198 — set to 1 during construction
  uint8_t mPad199[0xFF];    // 0x199 — unproven padding
  uint8_t mSub298[0x398];   // 0x298 — constructed subobjects (+0x298/+0x368/+0x460/+0x530/+0x628)
};
}  // namespace object
