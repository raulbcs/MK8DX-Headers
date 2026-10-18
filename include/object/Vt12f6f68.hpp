#pragma once

#include <cstdint>

// Vt12f6f68 — PLACEHOLDER name (15-slot class, size 0x508, two identical
// inline factories 0xb19b20/0xb19ff0); vptr 0x12f6f70 at +0x00, D2 0xb2dc18.
// extent 0x508 - details: doc/object/Vt12f6f68.md

namespace object {
class Vt12f6f68 {
 public:
  void* vtable;        // 0x00 — 0x12f6f70 (factories 0xb19bec/0xb1a104)
  char mPad8[0x98];    // 0x08 — unproven (ctor 0x588b04-managed, arg w1=2)
  uint32_t mFieldA0;   // 0xA0 — factories zero (0xb19be8/0xb1a100)
  char mPadA4[0x4];    // 0xA4 — unproven
  void* mFieldA8;      // 0xA8 — factories zero (0xb19bd0/0xb1a0e8)
  void* mFieldB0;      // 0xB0 — factories zero (0xb19bd0/0xb1a0e8)
  uint8_t mFieldB8;    // 0xB8 — factories set to 1 (0xb19bd4/0xb1a0ec)
  char mPadB9[0x3];    // 0xB9 — unproven
  uint32_t mFieldBC;   // 0xBC — factories zero (0xb19bd8/0xb1a0f0)
  char mPadC0[0x448];  // 0xC0 — unproven (member ctors 0xa2bf88, 0x578f98;
                       //        memsets +0x1D8/+0x338 0x160 each; ptrs
                       //        +0x498..+0x4F8 zeroed by D2 cleanup)
};
}  // namespace object
