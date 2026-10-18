#pragma once

#include <cstdint>

namespace object {
// Vt12d78d0 - PLACEHOLDER name. Heap-built (new 0x248) sibling of
// Vt12d7128/Vt12d7960/Vt12d79f0/Vt12d7a80 (shared slots 2..12 cluster);
// typeinfo record 0x12d7940, base record 0x128d520.
// extent 0x248 - details: doc/object/Vt12d78d0.md
class Vt12d78d0 {
 public:
  void* vtable;      // 0x00 - 0x12d78d8 (GOT cell 0x1312240 holds 0x12d78c8 =
                     //   vt-0x10; installed = cell+0x10)
  char pad08[0x98];  // 0x08..0x9f - unproven
  uint32_t mA0;      // 0xa0 - ctor 0
  uint32_t mA4;      // 0xa4 - ctor 0x10
  void* mA8;         // 0xa8 - base-subobject vptr 0x128c798 (cell 0x130b618)
  uint32_t mB0;      // 0xb0 - stlr 1
  uint8_t mB4;       // 0xb4 - ctor 0
  char padB5[0x03];  // 0xb5..0xb7 - unproven gap
  void* mB8;         // 0xb8 - ctor 0
  uint32_t mC0;      // 0xc0 - ctor 0
  char padC4[0x184]; // 0xc4..0x247 - unproven tail of the 0x248 allocation
};
}  // namespace object
