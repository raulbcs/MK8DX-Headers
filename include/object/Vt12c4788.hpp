#pragma once

#include <cstdint>

// Vt12c4788 - PLACEHOLDER name; 35-slot container/manager built by
// FUN_71007b100c (0x1108 bytes); aggregates child parameter nodes and holds
// three u32 defaults copied from rodata 0xf57b7c via GOT cell 0x12fb148.
// extent 0x2d8 - details: doc/object/Vt12c4788.md

namespace object {
class Vt12c4788 {
 public:
  void* mVtable;           // 0x000 - 0x12c4788 (via GOT cell 0x130fb08)
  uint8_t mPad8[0x270];    // 0x008 - unproven padding
  void* mF278;             // 0x278 - arg[0x00]
  void* mF280;             // 0x280 - arg[0x08]
  void* mF288;             // 0x288 - arg[0x10]
  void* mF290;             // 0x290 - arg[0x18]
  int32_t mF298;           // 0x298 - ctor stores -1
  uint8_t mF29C;           // 0x29C - ctor stores 1
  uint8_t mPad29D[3];      // 0x29D - unverified
  uint32_t mF2A0;          // 0x2A0 - rodata default [0xf57b7c+0x00]
  uint32_t mF2A4;          // 0x2A4 - rodata default [0xf57b7c+0x04]
  uint32_t mF2A8;          // 0x2A8 - rodata default [0xf57b7c+0x08]
  uint32_t mF2AC;          // 0x2AC - slot-10 reset writes 0x01000100
  int32_t mF2B0;           // 0x2B0 - count of +0x2B8 array
  uint8_t mPad2B4[4];      // 0x2B4 - unproven padding
  void** mF2B8;            // 0x2B8 - array of Vt12c4538 node pointers
  int32_t mF2C0;           // 0x2C0 - count of +0x2C8 array
  uint8_t mPad2C4[4];      // 0x2C4 - unproven padding
  void** mF2C8;            // 0x2C8 - array of Vt12c4660 node pointers
  void* mF2D0;             // 0x2D0 - Vt12c4b00 node (size 0x2c8)
};
}  // namespace object
