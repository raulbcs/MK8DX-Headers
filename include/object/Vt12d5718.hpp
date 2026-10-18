#pragma once

#include <cstdint>

// Vt12d5718 — PLACEHOLDER name; vptr 0x12d5718, n=12; derives base family
// 0x12d5630; variant of Vt12d56a0 chosen when [src+0x20] == 1.
// extent 0x28 - details: doc/object/Vt12d5718.md

namespace object {
class Vt12d5718 {
 public:
  void* mVtable;    // 0x00 - 0x12d5718 (GOT cell 0x1311d08 holds 0x12d5708 =
                    //   vt-0x10; installed = cell+0x10)
  float m8;         // 0x08 - accumulated float (ctor 0)
  uint32_t mC;      // 0x0c - ctor 0
  uint32_t m10;     // 0x10 - element count (getters 0x8d6410 / 0x8d63f0)
  uint32_t m14;     // 0x14 - ctor 0
  void** m18;       // 0x18 - element array; ctor 0
  uint8_t m20;      // 0x20 - flag byte (ctor 0)
  char pad21[0x7];  // 0x21..0x27 - tail slack to the 0x28 allocation size
};
}  // namespace object
