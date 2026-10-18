#pragma once

#include <cstdint>

// Vt12b4bb8 - PLACEHOLDER name; vptr 0x12b4bb8, n=46, single vptr at +0x00;
// extent 0x248 - details: doc/object/Vt12b4bb8.md

namespace object {
class Vt12b4bb8 {
 public:
  void* vtable;           // 0x00 - 0x12b4bb8 (GOT cell 0x130dd00 + 0x10)
  uint8_t mPad08[0x240];  // 0x08 - 0x0248 — extent 0x248 proven by allocation; layout unproven
};
}  // namespace object
