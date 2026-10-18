#pragma once

#include <cstdint>

namespace object {
// Vt12b1818 - PLACEHOLDER name; 0x30-byte node built by the factory inside
// a 0x6351xx setup function (in-place alloc 0x30 at 0x635164). Two f32
// fields converted from u32 params. No RTTI (null typeinfo slot).
// extent 0x30 - details: doc/object/Vt12b1818.md
class Vt12b1818 {
 public:
  void* vtable;  // 0x00 - 0x12b1818 (GOT cell 0x130d6f8 holds vt-0x10)
  void* m08;     // 0x08 - pointer loaded from [param+0x18]
  void* m10;     // 0x10 - ctor 0
  float m18;     // 0x18 - uctf(s0) of u32 at [sp+0x10]
  float m1c;     // 0x1c - ucvtf(s1) of u32 at [sp+0x14]
  void* m20;     // 0x20 - outer-scope pointer (x21)
  void* m28;     // 0x28 - outer-scope pointer (x24)
};
}  // namespace object
