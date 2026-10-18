#pragma once

#include <cstdint>

namespace object {
// Vt12d79f0 - PLACEHOLDER name. Heap-built (new 0x240) sibling of Vt12d7128 /
// Vt12d78d0 / Vt12d7960 / Vt12d7a80 (shared slots 2..12 cluster); typeinfo
// record 0x12d7a60, base record 0x128d520.
// extent 0x240 - details: doc/object/Vt12d79f0.md
class Vt12d79f0 {
 public:
  void* vtable;      // 0x00 - 0x12d79f8 (GOT cell 0x1312248 holds 0x12d79e8 =
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
  char padC4[0x14];  // 0xc4..0xd7 - unproven gap
  void* mD8;         // 0xd8 - ctor 0
  void* mE0;         // 0xe0 - ctor 0
  char padE8[0x10];  // 0xe8..0xf7 - unproven gap
  void* mF8;         // 0xf8 - ctor 0
  char pad100[0xc8]; // 0x100..0x1c7 - unproven
  char pad1C8[0x38]; // 0x1c8..0x1ff - member subobject (dtor re-installs vptr
                     //   0x12d7588 = cell 0x1312110 + 0x10; sibling dtor also
                     //   touches +0x1d8 = cell 0x1312118 + 0x10)
  char pad200[0x40]; // 0x200..0x23f - member subobject (vptr 0x128c698 = cell
                     //   0x130b4a8 + 0x10)
};
}  // namespace object
