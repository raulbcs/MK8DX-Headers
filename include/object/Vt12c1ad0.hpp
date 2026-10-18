#pragma once

#include <cstdint>

// Vt12c1ad0 — placeholder name; small parameter/easing-style leaf, primary
// table, RTTI-less; derives from the class whose primary vptr is 0x12c1b10.
// extent 0x40 - details: doc/object/Vt12c1ad0.md

namespace object {
class Vt12c1ad0 {
 public:
  void* mVtable;          // 0x00 — 0x12c1ad0 (ctor overwrites base 0x12c1b10)
  void* mPtr08;           // 0x08 — GOT cell 0x12fae28 +0x10, unverified target
  void* mPtr10;           // 0x10 — rodata ptr, unverified
  float mF18;             // 0x18 — 1.0f
  uint32_t mPad1C;        // 0x1C — 0
  float mF20;             // 0x20 — 1.0f
  float mF24;             // 0x24 — 2.0f
  float mF28;             // 0x28 — 2.0f
  uint32_t mU2C;          // 0x2C — 0
  float mF30;             // 0x30 — -0.0f
  float mF34;             // 0x34 — -0.0f
  float mF38;             // 0x38 — -0.0f
  float mF3C;             // 0x3C — -2.0f
};
}  // namespace object
