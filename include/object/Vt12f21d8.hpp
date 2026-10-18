#pragma once

#include <cstdint>

// Vt12f21d8 — PLACEHOLDER name; sead::FileDevice subclass with a +0x80
// sub-object (init FUN_710060b930 / dtor FUN_710060b984). Inline-constructed.
// extent 0x98 - details: doc/object/Vt12f21d8.md

namespace object {
class Vt12f21d8 {
 public:
  void* vtable;         // 0x00 — 0x12f21d8 (inline ctor 0xa820f4)
  uint8_t mPad8[0x78];  // 0x08 — unproven
  uint8_t mSub80[0x18];  // 0x80 — sub-object (FUN_710060b930 init); unproven
};
}  // namespace object
