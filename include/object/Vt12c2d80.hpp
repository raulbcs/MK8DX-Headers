#pragma once

#include <cstdint>

// PROVISIONAL (no RTTI: typeinfo slot zero). Small wrapper over a base
// (ctor 0x78d66c) adding a null sink ptr and 1.0f scale; size proven by
// operator new 0x20 (0x7757e0-0x7757f4). extent 0x20 - details: doc/object/Vt12c2d80.md

namespace object {
class Vt12c2d80 {
 public:
  void* vtable;             // 0x00 — 0x12c2d80 (cell 0x130f628 + 0x10)
  uint8_t mBase08[0x8];     // 0x08 — base-ctor region (0x78d66c)
  void* mField10;           // 0x10 — zeroed (0x78d1e4)
  float mField18;           // 0x18 — 1.0f (0x78d1f0)
  uint8_t mPad1c[0x4];      // 0x1c — unproven tail pad to 0x20
};
}  // namespace object
