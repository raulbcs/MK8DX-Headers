#pragma once

#include <cstdint>

// Vt12db410 - PLACEHOLDER name; vptr 0x12db418, n=53, single vptr at +0x00;
// extent 0x588 - details: doc/object/Vt12db410.md

namespace object {
class Vt12db410 {
 public:
  void* vtable;           // 0x00 - 0x12db418 (GOT cell 0x1313168 + 0x10)
  uint8_t mPad08[0x580];  // 0x08 - 0x0588 — extent 0x588 proven by allocation; layout unproven
};
}  // namespace object
