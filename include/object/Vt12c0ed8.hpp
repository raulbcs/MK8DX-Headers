#pragma once

#include <cstdint>

// Vt12c0ed8 — PLACEHOLDER name (42-slot class, sibling family sharing base
// ctor 0x738d68); vptr 0x12c0ed8 at +0x00, inline factory init (0x73ab98).
// extent 0x80 - details: doc/object/Vt12c0ed8.md

namespace object {
class Vt12c0ed8 {
 public:
  void* vtable;         // 0x00 — 0x12c0ed8 (factory 0x73ab98)
  char mPad8[0x68];     // 0x08 — unproven (base-ctor-managed)
  uint8_t mField70;     // 0x70 — factory zeroes (0x73ac64)
  uint8_t mField71;     // 0x71 — factory 1 (0x73ac68)
  char mPad72[0x6];     // 0x72 — unproven
  void* mField78;       // 0x78 — factory zeroes (0x73ac74)
};
}  // namespace object
