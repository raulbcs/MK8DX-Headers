#pragma once

#include <cstdint>

// Vt12cf048 — PLACEHOLDER name; 44-slot interface object of the 0x3835e8
// factory family (w1=3 base-ctor id), ctor at 0x710085f270.
// extent 0xc8 - details: doc/object/Vt12cf048.md

namespace object {
class Vt12cf048 {
 public:
  void* vtable;       // 0x00 — 0x12cf048 (ctor 0x710085f2a0)
  char mPad8[0x68];   // 0x08 — unproven
  uint32_t mField70;  // 0x70 — ctor zeroes (0x710085f288)
  uint16_t mField74;  // 0x74 — ctor zeroes (0x710085f28c)
  char mPad76[0x26];  // 0x76 — unproven
  uint32_t mField9c;  // 0x9c — ctor zeroes (0x710085f298)
  uint16_t mFielda0;  // 0xa0 — ctor zeroes (0x710085f2a4)
  char mPada2[0x6];   // 0xa2 — unproven
  void* mSuba8;       // 0xa8 — ctor stores new(0x88) object (0x710085f2e8)
  void* mSubb0;       // 0xb0 — ctor stores new(0x30) object (0x710085f2cc)
  uint64_t mTickb8;   // 0xb8 — nn::os::GetSystemTick() (0x710085f2ac)
  char mPadc0[0x2];   // 0xc0 — unproven
  uint8_t mFieldc2;   // 0xc2 — ctor zeroes (0x710085f2b4)
  char mPadc3[0x5];   // 0xc3 — unproven
};
}  // namespace object
