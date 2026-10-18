#pragma once

#include <cstdint>

// Vt12cdf48 — PLACEHOLDER name; 44-slot interface object of the 0x3835e8
// factory family (w1=2 base-ctor id). vptr 0x12cdf48 at +0x00.
// extent 0x1d0 - details: doc/object/Vt12cdf48.md

namespace object {
class Vt12cdf48 {
 public:
  void* vtable;        // 0x00 — 0x12cdf48 (ctor 0x710085141c)
  char mPad8[0x1c0];   // 0x08 — unproven
  uint16_t mField1c8;  // 0x1c8 — ctor zeroes (0x710085142c)
  uint8_t mField1ca;   // 0x1ca — ctor zeroes (0x7100851430)
  char mPad1cb[0x5];   // 0x1cb — unproven
};
}  // namespace object
