#pragma once

#include <cstdint>

// Vt12e12d0 - PLACEHOLDER name; vptr 0x12e12d8, n=50, single vptr at +0x00;
// extent 0x7210 - details: doc/object/Vt12e12d0.md

namespace object {
class Vt12e12d0 {
 public:
  void* vtable;            // 0x00 - 0x12e12d8 (GOT cell 0x1313eb0 + 0x10)
  uint8_t mPad08[0x7208];  // 0x08 - 0x7210 — extent 0x7210 proven by allocation; layout unproven
};
}  // namespace object
