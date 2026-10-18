#pragma once

#include <cstdint>

// Vt12da1a0 - PLACEHOLDER name; nn::pia-region dispatch object (0x270 bytes,
// 39-slot getter table, factory-built array elements); vptr 0x12da1a8.
// extent 0x270 - details: doc/object/Vt12da1a0.md

namespace object {
class Vt12da1a0 {
 public:
  void* vtable;          // 0x00 - 0x12da1a8 (ctor 0x7100933328; GOT cell
                         // 0x1312960 holds 0x12da198 = vt-0x8, vptr = cell+0x10)
  char mPad08[0x8];      // 0x08 - u32 at +0x08 read by getter slot 3
                         // FUN_7100933444; rest unproven
  uint32_t mField10;     // 0x10 - ctor zeroes (0x7100933330)
  uint16_t mField14;     // 0x14 - ctor zeroes (0x7100933334)
  uint8_t mField16;      // 0x16 - ctor zeroes (0x7100933338)
  char mPad17[0x1];      // 0x17 - unproven
  char mZero18[0x18];    // 0x18 - ctor-zeroed block (0x71009339c..0x7100933b8)
  char mZero30[0x200];   // 0x30 - ctor-zeroed 0x200 block (memset 0x710093340c)
  uint32_t mField230;    // 0x230 - ctor zeroes (0x7100933394)
  uint16_t mField234;    // 0x234 - ctor zeroes (0x710093333c)
  char mPad236[0x2];     // 0x236 - unproven
  uint32_t mField238;    // 0x238 - ctor zeroes (0x7100933348)
  uint8_t mField23c;     // 0x23c - ctor zeroes (0x7100933354)
  char mPad23d[0x3];     // 0x23d - unproven
  void* mPtr240;         // 0x240 - ctor nulls (0x710093335c)
  void* mPtr248;         // 0x248 - ctor nulls (0x7100933360)
  uint8_t mField250;     // 0x250 - ctor zeroes (0x7100933364)
  char mPad251[0x7];     // 0x251 - unproven
  void* mVptr258;        // 0x258 - secondary vptr 0x12da318 (GOT cell 0x1312968
                         // holds 0x12da308; ctor 0x710093336c..0x7100933378)
  uint16_t mField260;    // 0x260 - ctor zeroes (0x710093337c)
  uint16_t mField262;    // 0x262 - ctor zeroes (0x7100933380)
  uint16_t mField264;    // 0x264 - ctor zeroes (0x7100933384)
  uint16_t mField266;    // 0x266 - ctor zeroes (0x710093338c)
  uint32_t mField268;    // 0x268 - ctor zeroes (0x710093338c..90); getter slot
                         // 13 FUN_7100933454 reads it
  char mPad26c[0x4];     // 0x26c - unproven
};
}  // namespace object
