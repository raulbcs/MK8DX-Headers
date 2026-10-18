#pragma once

#include <cstdint>

// Vt12c5208 - 6-byte-token multi-value quant channel (qbits 11..16);
// selected by the vector factory FUN_71007b9400; quantization uses
// exp2f(15); +0x1c0 = 0xc (numValues), +0x1c4 = 6 (bytes per tick).
// extent 0x280 - details: doc/object/Vt12c5208.md

namespace object {
class Vt12c5208 {
 public:
  void* mVtable;           // 0x000 - 0x12c5208 (via GOT cell 0x130fe80)
  uint8_t mPad8[0x1B8];    // 0x008 - unproven padding
  uint32_t mF1C0;          // 0x1C0 - numValues (0xc)
  uint32_t mF1C4;          // 0x1C4 - token bytes per fresh tick (6)
  uint8_t mPad1C8[0x28];   // 0x1C8 - unproven padding
  float mF1F0;             // 0x1F0 - step
  float mF1F4;             // 0x1F4 - (2^15 - 1) / range
  float mF1F8;             // 0x1F8 - reciprocal of +0x1F4
  uint8_t mPad1FC[0x7C];   // 0x1FC - unproven padding
  void* mOwner;            // 0x278 - owning hub/backref (factory x19)
};
}  // namespace object
