#pragma once

#include <cstdint>

// Vt12c49d8 - PLACEHOLDER name; 35-slot parameter entry, C2
// FUN_71007b19f4; holds a linked object ptr, an int, two u16 -1 sentinels
// and an optional 0x280 Vt12c50e0 child with the "scale" float defaults.
// extent 0x2e0 - details: doc/object/Vt12c49d8.md

namespace object {
class Vt12c49d8 {
 public:
  void* mVtable;           // 0x000 - 0x12c49d8 (via GOT cell 0x130fb38)
  uint8_t mPad8[0x280];    // 0x008 - unproven padding
  void* mF288;             // 0x288 - arg x1 (linked object, receives floats)
  int32_t mF290;           // 0x290 - arg w2
  uint16_t mF294;          // 0x294 - ctor stores -1
  uint16_t mF296;          // 0x296 - ctor stores -1
  void* mF298;             // 0x298 - zeroed by ctor
  uint8_t mF2A0;           // 0x2A0 - arg w3 & 1
  uint8_t mPad2A1[3];      // 0x2A1 - unverified
  uint8_t mF2A4[0x3C];     // 0x2A4 - optional Vt12c50e0 child + sub-init
};
}  // namespace object
