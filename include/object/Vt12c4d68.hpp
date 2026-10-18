#pragma once

#include <cstdint>

// Vt12c4d68 - quantized scalar channel, wide-range fallback (qbits >= 17 or
// degenerate min/max/step); built inline by scalar factory FUN_71007b95a8;
// min/max fixed to -2147483648.0f/+2147483648.0f at +0x280.
// extent 0x288 - details: doc/object/Vt12c4d68.md

namespace object {
class Vt12c4d68 {
 public:
  void* mVtable;           // 0x000 - 0x12c4d68 (via GOT cell 0x130fe88)
  uint8_t mPad8[0x1B8];    // 0x008 - unproven padding
  uint32_t mF1C0;          // 0x1C0 - numValues (8 at the factory site)
  uint32_t mF1C4;          // 0x1C4 - width (8)
  uint8_t mPad1C8[0x28];   // 0x1C8 - unproven padding
  float mF1F0;             // 0x1F0 - step
  float mF1F4;             // 0x1F4 - (2^bits - 1) / range
  float mF1F8;             // 0x1F8 - reciprocal of +0x1F4
  uint8_t mPad1FC[0x7C];   // 0x1FC - unproven padding
  void* mOwner;            // 0x278 - owning hub/backref (factory x19)
  float mMin280;           // 0x280 - -2147483648.0f (fixed)
  float mMax284;           // 0x284 - +2147483648.0f (fixed)
};
}  // namespace object
