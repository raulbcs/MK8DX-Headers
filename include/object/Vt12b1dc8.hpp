#pragma once

#include <cstdint>

namespace object {
// Vt12b1dc8 - PLACEHOLDER name; 0x68-byte record with four f32 = 1.0 fields
// and a 0x48-byte zeroed tail (memset this+0x20). Derived override of the
// 0x12b0e38 family (cell 0x130d6f0). No RTTI (null typeinfo slot).
// extent 0x68 - details: doc/object/Vt12b1dc8.md
class Vt12b1dc8 {
 public:
  void* vtable;      // 0x00 - 0x12b1dc8 (GOT cell 0x130d880 holds vt-0x10)
  float m08;         // 0x08 - ctor 1.0f (or [param1] in the copy init)
  float m0c;         // 0x0c - ctor 1.0f
  void* m10;         // 0x10 - ctor 0 (or [param2] in the copy init)
  float m18;         // 0x18 - ctor 1.0f (or [param2+8] in the copy init)
  float m1c;         // 0x1c - ctor 1.0f
  char pad20[0x48];  // 0x20..0x67 - memset(this+0x20, 0, 0x48); unproven
};
}  // namespace object
