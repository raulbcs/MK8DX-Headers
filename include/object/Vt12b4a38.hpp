#pragma once

#include <cstdint>

// Vt12b4a38 - PLACEHOLDER name; vptr 0x12b4a38, n=46, single vptr at +0x00;
// extent 0x240 - details: doc/object/Vt12b4a38.md

namespace object {
class Vt12b4a38 {
 public:
  void* vtable;           // 0x00 - 0x12b4a38 (GOT cell 0x130dcf8 + 0x10)
  uint8_t mPad08[0x238];  // 0x08 - 0x0240 — extent 0x240 proven by allocation; layout unproven
};
}  // namespace object
