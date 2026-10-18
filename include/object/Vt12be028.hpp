#pragma once

#include <cstdint>

// Vt12be028 — PLACEHOLDER name; primary base of Vt12b6af8, vptr 0x12be028 at
// +0x00 (ctor 0x7100732620, D1/D0 0x7100732660/0x71007326ec).
// extent 0xd0 - details: doc/object/Vt12be028.md

namespace object {
class Vt12be028 {
 public:
  void* vtable;       // 0x00 — 0x12be028 (ctor 0x7100732648)
  char mPad8[0xb0];   // 0x08 — grandbase region (base ctor 0x71006ebb54) — unproven
  uint32_t mFieldB8;  // 0xb8 — ctor 1 (0x710073264c)
  char mPadBC[0x4];   // 0xbc — unproven
  uint32_t mFieldC0;  // 0xc0 — ctor zeroes (0x710073263c)
  char mPadC4[0x4];   // 0xc4 — unproven
  void* mArrayC8;     // 0xc8 — 0x38-stride element array (D1 0x7100732660)
};
}  // namespace object
