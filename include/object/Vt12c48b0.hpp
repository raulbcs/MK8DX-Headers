#pragma once

#include <cstdint>

// Vt12c48b0 - PLACEHOLDER name; 35-slot parameter entry, C2
// FUN_71007b1874; holds a linked object ptr, an int and an optional
// 0x280 Vt12c50e0 child seeded with the "scale" float defaults.
// extent 0x2d8 - details: doc/object/Vt12c48b0.md

namespace object {
class Vt12c48b0 {
 public:
  void* mVtable;           // 0x000 - 0x12c48b0 (via GOT cell 0x130fb30)
  uint8_t mPad8[0x280];    // 0x008 - unproven padding
  void* mF288;             // 0x288 - arg x1 (linked object, receives floats)
  int32_t mF290;           // 0x290 - arg w2
  uint8_t mF294;           // 0x294 - arg w3 & 1
  uint8_t mPad295[3];      // 0x295 - unverified
  uint8_t mF298[0xC];      // 0x298 - optional Vt12c50e0 child (size 0x280)
  uint8_t mPad2A4[0x34];   // 0x2A4 - FUN_71007ae16c(this+0x2a4,1,0)
                           // sub-init region; unverified layout
};
}  // namespace object
