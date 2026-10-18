#pragma once

#include <cstdint>

// Vt12c4b00 - PLACEHOLDER name; 35-slot data node (no dedicated C2 - built
// inline by FUN_71007b100c and FUN_71001e21b8); +0x298 is a length-initialized
// buffer registered back into the owner.
// extent 0x2c8 - details: doc/object/Vt12c4b00.md

namespace object {
class Vt12c4b00 {
 public:
  void* mVtable;           // 0x000 - 0x12c4b00 (via GOT cell 0x12ff1d8)
  uint8_t mPad8[0x270];    // 0x008 - unproven padding
  void* mOwner;            // 0x278 - owning object (varies per site)
  uint8_t mPad280[8];      // 0x280 - unproven padding
  void* mF288;             // 0x288 - source/linked pointer
  int32_t mF290;           // 0x290 - length or 0
  uint8_t mPad294[4];      // 0x294 - unverified
  uint8_t mBuffer[0x30];   // 0x298 - FUN_71007ae16c-initialized buffer
};
}  // namespace object
