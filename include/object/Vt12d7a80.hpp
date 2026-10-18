#pragma once

#include <cstdint>

namespace object {
// Vt12d7a80 - PLACEHOLDER name. Heap-built (new 0x1a0) sibling of Vt12d7128 /
// Vt12d78d0 / Vt12d7960 / Vt12d79f0 (shared slots 2..12 cluster); typeinfo
// record 0x12d7af0, base record 0x128d520.
// extent 0x1a0 - details: doc/object/Vt12d7a80.md
class Vt12d7a80 {
 public:
  void* vtable;      // 0x00 - 0x12d7a88 (GOT cell 0x13122b8 holds 0x12d7a78 =
                     //   vt-0x10; installed = cell+0x10)
  char pad08[0x98];  // 0x08..0x9f - unproven
  uint32_t mA0;      // 0xa0 - ctor 0
  uint32_t mA4;      // 0xa4 - ctor 0x10
  void* mA8;         // 0xa8 - ctor 0
  void* mB0;         // 0xb0 - ctor 0
  void* mB8;         // 0xb8 - ctor 0
  void* mC0;         // 0xc0 - base-subobject vptr 0x128c798 (cell 0x130b618)
  uint32_t mC8;      // 0xc8 - stlr 1
  uint8_t mCC;       // 0xcc - ctor 0
  char padCD[0x03];  // 0xcd..0xcf - unproven gap
  void* mD0;         // 0xd0 - ctor 0
  char padD8[0xc8];  // 0xd8..0x19f - unproven tail of the 0x1a0 allocation
};
}  // namespace object
