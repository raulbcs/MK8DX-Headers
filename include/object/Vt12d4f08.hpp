#pragma once

#include <cstdint>

namespace object {
// Vt12d4f08 - PLACEHOLDER name; embedded member initialized in place at
// owner+0x430 (ctor near 0x837d00): [m]=vptr, [m+0x10]=raw row pointer.
// No standalone allocation found.
// size >= 0x18 - details: doc/object/Vt12d4f08.md
class Vt12d4f08 {
 public:
  void* vtable;      // 0x00 - 0x12d4f08 (GOT cell 0x1311a18 holds 0x12d4ef8 =
                     //   vt-0x10)
  char pad08[0x08];  // 0x08..0x0f - unproven gap
  void* m10;         // 0x10 - owner stores raw GOT value 0x12d4ef8 (row-0x10),
                     //   not an installed vptr
};
}  // namespace object
