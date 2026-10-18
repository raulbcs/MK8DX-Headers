#pragma once

#include <cstdint>

// Vt12b63f0 — PLACEHOLDER name; vptr 0x12b63f0, n=87, primary table of the
// base class behind Vt12cba38 (size 0x320 there; derived-only fields start
// at 0x2F0). extent 0x2F0 (lower bound, unverified) -
// details: doc/object/Vt12b63f0.md

namespace object {
class Vt12b63f0 {
 public:
  void* mVtable;          // 0x00 — 0x12b63f0 (via GOT cell 0x130DFF0)
  uint8_t mPad8[0xB0];    // 0x08 — unproven padding
  void* mVtable2;         // 0xB8 — secondary base, 0x12b63f0+0x2C8
  uint8_t mPadC0[0x230];  // 0xC0 — unproven padding
};
}  // namespace object
