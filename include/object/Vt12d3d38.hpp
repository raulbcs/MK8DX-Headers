#pragma once

#include <cstdint>

namespace object {
// Vt12d3d38 - PLACEHOLDER name; heap-built parse node: factory news 0x30,
// zeroes 0x10..0x2f, installs vptr, then invokes parse slot 0x896510 with a
// string (observed payload name "JumpJAArea", rodata 0xf0bc0b).
// extent 0x30 - details: doc/object/Vt12d3d38.md
class Vt12d3d38 {
 public:
  void* vtable;      // 0x00 - 0x12d3d38 (GOT cell 0x1311640 holds 0x12d3d28 =
                     //   vt-0x10)
  char pad08[0x08];  // 0x08..0x0f - unproven gap
  void* m10;         // 0x10 - factory zero
  void* m18;         // 0x18 - factory zero
  void* m20;         // 0x20 - factory zero
  void* m28;         // 0x28 - factory zero
};
}  // namespace object
