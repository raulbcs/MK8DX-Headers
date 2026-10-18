#pragma once

#include <cstdint>

// Vt12d8718 — PLACEHOLDER name; vptr 0x12d8718, n=97, primary table.
// extent 0x238 - details: doc/object/Vt12d8718.md

namespace object {
class Vt12d8718 {
 public:
  void* vtable;          // 0x00 — 0x12d8718 (via GOT cell 0x1312530)
  uint8_t mPad8[0x230];  // unproven padding — 0x08-0x238 unproven (factory zeroes 0x228, 0x230)
};
}  // namespace object
