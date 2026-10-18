#pragma once

#include <cstdint>

// Vt12f30b0 — PLACEHOLDER name; vptr 0x12f30b0, n=7, primary table; derives
// from Vt12f3260 (slots 2-6 shared).
// extent 0x700 - lower bound (deepest member init +0x6F8); unverified -
// details: doc/object/Vt12f30b0.md

namespace object {
class Vt12f30b0 {
 public:
  void* mVtable;            // 0x00 — 0x12f30b0 (via GOT cell 0x1315290)
  uint8_t mPad8[0x190];     // 0x08 — unproven padding (base Vt12f3260 region)
  uint8_t mFlag198;         // 0x198 — set to 1 before base subobject inits
  uint8_t mPad199[0xFF];    // 0x199 — unproven padding
  uint8_t mSub298[0x468];   // 0x298 — five constructed subobjects (+0x298/+0x368/+0x460/+0x530/+0x628; pairs of 0x63A384/0x639F38)
};
}  // namespace object
