#pragma once

#include <cstdint>

// Vt12c4660 - PLACEHOLDER name; 35-slot node of the "scale"-parameter family
// (base ctor FUN_71007aae24 / Vt12c3af8); nodes are built in a loop inside
// FUN_71007b100c and chained into the owner's slot array.
// extent 0x290 - details: doc/object/Vt12c4660.md

namespace object {
class Vt12c4660 {
 public:
  void* mVtable;           // 0x000 - 0x12c4660 (via GOT cell 0x130fb28)
  uint8_t mPad8[0x1B8];    // 0x008 - unproven padding
  uint32_t mC1C0;          // 0x1C0 - ctor stores 12
  uint32_t mC1C4;          // 0x1C4 - ctor stores 5
  uint8_t mPad1C8[0xB0];   // 0x1C8 - unproven padding
  void* mOwner;            // 0x278 - owning FUN_71007b100c object
  void* mF280;             // 0x280 - copy of owner+0x278
  int32_t mF288;           // 0x288 - zeroed by ctor
  int32_t mF28C;           // 0x28C - zeroed by ctor (loop counter base)
};
}  // namespace object
