#pragma once

#include <cstdint>

// Vt12c50e0 - multi-value channel of the quant-channel family; selected by
// the vector factory FUN_71007b9400 for qbits 9..10 and reused with fixed
// 64.0f/0.01f/0.015625f defaults by the scale-family builders.
// extent 0x280 - details: doc/object/Vt12c50e0.md

namespace object {
class Vt12c50e0 {
 public:
  void* mVtable;           // 0x000 - 0x12c50e0 (via GOT cell 0x130fb10)
  uint8_t mPad8[0x1B8];    // 0x008 - unproven padding
  uint32_t mF1C0;          // 0x1C0 - site-dependent (4 at FUN_71007b9400,
                           //        0xc at the scale-family sites)
  uint32_t mF1C4;          // 0x1C4 - site-dependent (0xc / 4)
  uint8_t mPad1C8[0x28];   // 0x1C8 - unproven padding
  float mF1F0;             // 0x1F0 - step (64.0f at fixed-default sites)
  float mF1F4;             // 0x1F4 - quantization multiplier (0.01f fixed)
  float mF1F8;             // 0x1F8 - secondary step (0.015625f fixed)
  uint8_t mPad1FC[0x7C];   // 0x1FC - unproven padding
  void* mOwner;            // 0x278 - owner backref (hub or &owner+0x298)
};
}  // namespace object
