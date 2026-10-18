#pragma once

#include <cstdint>

// Vt12c7d88 — PLACEHOLDER name; base of a hierarchy (derived Vt12ca828);
// ctor FUN_71007d4c9c(this, u8 count, const void* data) via GOT cell
// 0x1310010 = vt-0x10. extent 0xd8 - details: doc/object/Vt12c7d88.md

namespace object {
class Vt12c7d88 {
 public:
  void* vtable;        // 0x00 — 0x12c7d88 (ctor 0x7d4cc0..0x7d4cd0)
  char mPad8[0x18];    // 0x08 — unproven (base init 0x7d34d8)
  uint32_t mField20;   // 0x20 — 6 written by ctor 0x7d4cf4
  char mPad24[0x88];   // 0x24 — unproven (base init 0x7d34d8)
  uint8_t mFieldAC;    // 0xAC — 0 written by ctor 0x7d4cc4
  char mPadAD[0x3];    // 0xAD — unproven (alignment)
  uint32_t mFieldB0;   // 0xB0 — count (arg w1 & 0xff), ctor 0x7d4cd8
  char mPadB4[0x4];    // 0xB4 — unproven (alignment)
  void* mArrayB8;      // 0xB8 — new[count * 0xC], ctor 0x7d4cf8..0x7d4d08
  void* mArrayC0;      // 0xC0 — new[count * 0xC], ctor 0x7d4d0c
  float mFieldC8;      // 0xC8 — 7.0f, ctor 0x7d4ce0
  float mFieldCC;      // 0xCC — 7.0f, ctor 0x7d4ce0
  float mFieldD0;      // 0xD0 — 7.0f, ctor 0x7d4ce4
  char mPadD4[0x4];    // 0xD4 — unproven (alignment)
};
}  // namespace object
