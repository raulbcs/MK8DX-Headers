#pragma once

#include <cstdint>

// Vt12cba38 — PLACEHOLDER name; vptr 0x12cba38, n=87, primary table.
// Derived from Vt12b63f0 (base primary at [this+0x00], shared secondary base
// vptr at [this+0xB8] -> 0x12cb900). extent 0x320 - details: doc/object/Vt12cba38.md

namespace object {
class Vt12cba38 {
 public:
  void* vtable;          // 0x00 — 0x12cba38 (via GOT cell 0x1310858)
  uint8_t mPad8[0x318];  // unproven padding — 0x08-0x320 unproven (base layout + derived fields 0x2F0-0x31C)
};
}  // namespace object
