#pragma once

#include <cstdint>

// Vt12c4fb8 - quantized s8 scalar channel (qbits < 9); built inline by
// scalar factory FUN_71007b95a8; min/max fixed to -128.0f/+127.0f at
// +0x280/+0x284, quantization uses exp2f(7).
// extent 0x288 - details: doc/object/Vt12c4fb8.md

namespace object {
class Vt12c4fb8 {
 public:
  void* mVtable;           // 0x000 - 0x12c4fb8 (via GOT cell 0x130fe98)
  uint8_t mPad8[0x1B8];    // 0x008 - unproven padding
  uint32_t mF1C0;          // 0x1C0 - numValues (8 at the factory site)
  uint32_t mF1C4;          // 0x1C4 - width (2, s8 per tick)
  uint8_t mPad1C8[0x28];   // 0x1C8 - unproven padding
  float mF1F0;             // 0x1F0 - step
  float mF1F4;             // 0x1F4 - (2^7 - 1) / range
  float mF1F8;             // 0x1F8 - reciprocal of +0x1F4
  uint8_t mPad1FC[0x7C];   // 0x1FC - unproven padding
  void* mOwner;            // 0x278 - owning hub/backref (factory x19)
  float mMin280;           // 0x280 - -128.0f (rodata 0xed6874)
  float mMax284;           // 0x284 - +127.0f (rodata 0xed6624)
};
}  // namespace object
