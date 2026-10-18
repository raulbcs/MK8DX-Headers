#pragma once

#include "object/Vt12c8698.hpp"

// PROVISIONAL (no RTTI: typeinfo slot zero). Minimal Vt12c8698 derivative:
// base layout plus a single zeroed u32; size proven by operator new 0x78
// (0xcc858-0xcc868). extent 0x78 - details: doc/object/Vt12c8cf0.md

namespace object {
class Vt12c8cf0 : public Vt12c8698 {
 public:
  uint32_t mField70;        // 0x70 — zeroed (0x7e9af8)
  uint8_t mPad74[0x4];      // 0x74 — unproven tail pad to 0x78
};
}  // namespace object
