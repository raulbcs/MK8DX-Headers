#pragma once

#include <cstdint>

// Vt12d45b0 — PLACEHOLDER name; vptr 0x12d45b0, n=95, primary table.
// extent 0x1F0 - details: doc/object/Vt12d45b0.md

namespace object {
class Vt12d45b0 {
 public:
  void* vtable;          // 0x00 — 0x12d45b0 (via GOT cell 0x1311A28)
  uint8_t mPad8[0x1e8];  // unproven padding — 0x08-0x1F0 unproven (C2 writes 0x1D0/-1, 0x1D4/0)
};
}  // namespace object
