#pragma once

#include <cstdint>

// Vt12ce230 - PLACEHOLDER name (theme unproven); vptr 0x12ce230, 54 slots.
// Ctor 0x8537b0, factory new(0x8d0) at 0x383754; sibling of Vt12cf618.
// extent 0x8d0 - details: doc/object/Vt12ce230.md

namespace object {
class Vt12ce230 {
 public:
  void* vtable;                // 0x00 - 0x12ce230
  std::uint8_t pad08[0x5a8];   // 0x08 - interior layout unproven
  std::uint64_t f5b0;          // 0x5b0 - zeroed by ctor 0x8537e0
  std::uint64_t f5b8;          // 0x5b8 - zeroed by ctor 0x8537d4
  void* f630[42];              // 0x630 - self-pointer chain, stride 0x18
                               //        (ctor 0x8537f0-0x85385c; count unproven)
  std::uint8_t pad780[0x150];  // 0x780 - [0x7f8] zeroed by ctor 0x8537e4
                               //        (rest unproven)
};
}  // namespace object
