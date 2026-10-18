#pragma once

#include <cstdint>

// Vt12be2d0 - PLACEHOLDER name; 0x38-byte element of the gsys
// procedural-manager container whose D1 0x732660 is recovered as
// gsys::IModelProcedural (FUN_7100732660). 14-slot interface-shaped
// table with constant-query slots.
// extent 0x38 - details: doc/object/Vt12be2d0.md

namespace object {
class Vt12be2d0 {
 public:
  void* vtable;            // 0x00 - 0x12be2d0 (GOT cell 0x130e978 holds
                           // 0x12be2c0 = vt-0x10; no typeinfo row)
  void* mField08;          // 0x08 - target/handle ptr; set by slot2 param
                           // x1 (0x732ab4), dereferenced by slot13 vcall
  char mPad10[0x4];        // 0x10..0x13 - unproven
  uint16_t mField14;       // 0x14 - u16 written by slot2 param w2
  uint16_t mField16;       // 0x16 - u16 written by slot2 param w2; passed
                           // as arg1 of the slot13 vcall
  char mPad18[0x18];       // 0x18..0x2f - unproven (slot4-style readers
                           // touch +0x28 via out-param APIs)
  uint32_t mFlags30;       // 0x30 - container writes bit0 (0x73294c-0x32
                           // cset on arg bit); slot5 returns flags&1
  char mPad34[0x4];        // 0x34..0x37 - tail padding
};
}  // namespace object
