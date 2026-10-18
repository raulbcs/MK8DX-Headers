#pragma once

#include <cstdint>

// Vt12ba1f0 - PLACEHOLDER name (manager-embedded 0x7b8 member with a
// kart-param secondary interface at +0x248). Ctor 0x6dd190.
// extent 0x7b8 - details: doc/object/Vt12ba1f0.md

namespace object {
class Vt12ba1f0 {
 public:
  void* vtable;        // 0x00 - installed 0x12ba1f0 (cell 0x130e330)
  char mPad08[0x240];  // 0x08..0x247 - pre-secondary body (unproven)
  void* mSec_248;      // 0x248 - subobject inited by 0x668d40, vptr then
                       //        overwritten to 0x12ba248 (off-to-top -0x248)
  char mPad250[0x1d8];  // 0x250..0x427 - secondary subobject body (unproven)
  char mPad428[0x18];   // 0x428..0x43f - zeroed by ctor
  uint16_t mHw_440;    // 0x440 - ctor sets 2
  uint16_t mHw_442;    // 0x442 - ctor sets 0x40
  char mPad444[4];     // 0x444..0x447 - padding
  uint64_t mZero_448;  // 0x448 - zeroed by ctor
  char mPad450[0x38];   // 0x450..0x487 - zeroed by ctor
  char mPad488[0x30];   // 0x488..0x4b7 - member inited by 0x66a2a4 (unproven)
  char mPad4b8[0x300];  // 0x4b8..0x7b7 - member inited by 0x662f30 + tail
};
}  // namespace object
