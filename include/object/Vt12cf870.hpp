#pragma once

#include <cstdint>

// Vt12cf870 — PLACEHOLDER name; named-subsystem SubEngine derivative
// (base C1 FUN_71007f3ffc, 38 slots). vptr 0x12cf870 via GOT cell
// 0x1310f20 (cell = vt-0x10, vptr = cell+0x10).
// extent 0x288 - details: doc/object/Vt12cf870.md

namespace object {
class Vt12cf870 {
 public:
  void* vtable;         // 0x00 — 0x12cf870 (ctor 0x71008697e4)
  char mBase8[0x1f0];   // 0x08 — SubEngine base subobject, unproven
  char m1f8[0x60];      // 0x1f8 — zeroed by ctor memset (0x7100869818-0x710086981c)
  char mPad258[0x30];   // 0x258 — unproven tail
};
}  // namespace object
