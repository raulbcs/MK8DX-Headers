#pragma once

#include <cstdint>

// Vt12c8718 — PLACEHOLDER name; composite holder; ctor FUN_71007e2b78(this,
// int); primary vptr via GOT cell 0x1310108 = vt-0x10, secondary at +0x10.
// extent 0x118 (lower bound) - details: doc/object/Vt12c8718.md

namespace object {
class Vt12c8718 {
 public:
  void* vtable;          // 0x00 — 0x12c8718 (ctor 0x7e2b90..0x7e2bb0)
  int32_t mField8;       // 0x08 — ctor arg w1 (0x7e2b8c)
  char mPadC[0x4];       // 0x0C — unproven (alignment)
  void* vtableSecondary; // 0x10 — 0x12c8778 via cell 0x1310110 (ctor 0x7e2b9c..0x7e2bb8)
  uint32_t mField18;     // 0x18 — 0 written by ctor 0x7e2b98
  char mPad1C[0x4];      // 0x1C — unproven (alignment)
  void* mField20;        // 0x20 — pointer to the +0x30 subobject (ctor 0x7e2c30)
  void* mField28;        // 0x28 — new 0xC0 object, ctor 0x62c3a8 (0x7e2c24..0x7e2c40)
  char mInner30[0xE8];   // 0x30 — inline subobject: vptr 0x12b0de8 (cell 0x130dc88)
};
}  // namespace object
