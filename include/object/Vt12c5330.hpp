#pragma once

#include <cstdint>

// Vt12c5330 - unquantized fallback of the vector quant-channel family
// (qbits >= 17 or degenerate min/max/step); built inline by vector factory
// FUN_71007b9400; skips the exp2f tail, raw token passthrough.
// extent 0x280 - details: doc/object/Vt12c5330.md

namespace object {
class Vt12c5330 {
 public:
  void* mVtable;           // 0x000 - 0x12c5330 (via GOT cell 0x130fe78)
  uint8_t mPad8[0x1B8];    // 0x008 - unproven padding
  uint32_t mF1C0;          // 0x1C0 - numValues (0xc)
  uint32_t mF1C4;          // 0x1C4 - token bytes per fresh tick (6)
  uint8_t mPad1C8[0x28];   // 0x1C8 - unproven padding
  float mF1F0;             // 0x1F0 - step (s8, stored raw)
  uint8_t mPad1F4[0x84];   // 0x1F4 - unproven padding (+0x1f4/+0x1f8 unset)
  void* mOwner;            // 0x278 - owning hub/backref (factory x19)
};
}  // namespace object
