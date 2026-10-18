#pragma once

#include <cstdint>

// Vt12c0708 - PLACEHOLDER name; vptr 0x12c0708, n=49, single vptr at +0x00;
// extent 0x160 - details: doc/object/Vt12c0708.md

namespace object {
class Vt12c0708 {
 public:
  void* vtable;           // 0x00 - 0x12c0708 (GOT cell 0x130edb0 + 0x10)
  uint8_t mPad08[0x158];  // 0x08 - 0x0160 — extent 0x160 proven by allocation; layout unproven
};
}  // namespace object
