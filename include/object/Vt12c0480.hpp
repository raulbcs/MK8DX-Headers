#pragma once

#include <cstdint>

// Vt12c0480 - PLACEHOLDER name; vptr 0x12c0480, n=49, single vptr at +0x00;
// extent 0x170 - details: doc/object/Vt12c0480.md

namespace object {
class Vt12c0480 {
 public:
  void* vtable;           // 0x00 - 0x12c0480 (GOT cell 0x130ed80 + 0x10)
  uint8_t mPad08[0x168];  // 0x08 - 0x0170 — extent 0x170 proven by allocation; layout unproven
};
}  // namespace object
