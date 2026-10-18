#pragma once

#include <cstdint>

// Vt12ceff8 — interface row mixing local helpers and Network:: heap slots:
// 8-slot abstract table (never installed); concrete row 0x12cf048 (44 slots)
// installed by ctor FUN_710085f270 (site 0x85f294), class size 0xc8.
// extent 0xc8 - details: doc/object/Vt12ceff8.md

namespace object {
class Vt12ceff8 {
 public:
  void* vtable;      // 0x00 — concrete vptr 0x12cf048 (ctor 0x85f294)
  char mPad8[0xa0];  // 0x08 — managed by ctor, unproven
  void* mMember_a8;  // 0xa8 — new 0x50 subobject, ctor stores (0x85f2ec..)
  void* mMember_b0;  // 0xb0 — new 0x88 subobject, ctor stores (0x85f2cc..)
  char mPadb8[0xa];  // 0xb8 — unproven
  uint8_t mFlag_c2;  // 0xc2 — zeroed by ctor (0x85f2b4)
  char mPadc3[0x5];  // 0xc3 — unproven padding to 0xc8
};
}  // namespace object
