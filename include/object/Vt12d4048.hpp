#pragma once

#include <cstdint>

// Vt12d4048 - PLACEHOLDER name (theme unproven); vptr 0x12d4048, 66 slots.
// Ctor 0x8bbfc8, D1 0x3df590; factory allocates a dynamic size (0x3d6d84).
// extent 0x9c8 - details: doc/object/Vt12d4048.md

namespace object {
class Vt12d4048 {
 public:
  void* vtable;               // 0x00 - 0x12d4048
  std::uint8_t pad08[0x9a8];  // 0x08 - members at 0x178/0x1f8/0x270/0x3e8-0x940
                              //        seen in ctor 0x8bbfc8 / D1 0x3df590
                              //        (interior layout unproven)
  std::uint64_t f9b0;         // 0x9b0 - zeroed by factory 0x3d6dbc
  std::uint64_t f9b8;         // 0x9b8 - zeroed by factory 0x3d6dc0
};
}  // namespace object
