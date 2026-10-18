#pragma once

#include <cstdint>

// Placeholder Vt12b7918: no RTTI (no typeinfo/offset-to-top rows). Embedded
// controller node; vptr 0x12b7918 (GOT cell 0x130e258, holds vt-0x10) installed
// at +0x13d0 of the outer manager by in-place init 0x6ce018 (outer ctor 0x6bb300).
// extent 0x1b8 - details: doc/object/Vt12b7918.md
class Vt12b7918 {
 public:
  void* vtable;            // 0x00 — vptr 0x12b7918
  void* mOwner;            // 0x08 — self/owner pointer (init stores `this` of the subobject)
  uint8_t mPad10[0x1a8];   // 0x10..0x1b8 — memset(0) by init 0x6ce018; slots touch 0x10/0x18/0xa8/0xb0/0xf8
};
