#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"
#include <object/Kart/KartParamCache.hpp>
#include <object/Kart/KartParamCacheMid2.hpp>

namespace object::Kart {
// KartParamCacheVt77d8 — address-anchored name (vptr 0x12b77d8, GOT cell
// 0x130e238; cell holds vt-0x10). Very large Mid2-derived cache variant;
// size 0xb060 (member slot [outer+0x4d8, outer+0xb538) in factory 0x717900).
// Ctor 0x71006cb040.
// extent 0xb060 - details: doc/object/Kart/KartParamCacheVt77d8.md
class KartParamCacheVt77d8 : public KartParamCacheMid2 {
 public:
  void* vptr;                // 0x00 — cell 0x130e238 + 0x10 (0x6cb098)
  uint8_t mOwn8[0x1c8];      // 0x08 — own-field region (Mid2 covers to 0x1d0)
  char mMember1d0[0x30];     // 0x1d0 — member ctor 0x710066a2a4 (0x6cb0a4)
  char mMember200[0x48];     // 0x200 — member ctor 0x7100669954, vptr cell
                             // 0x130e240; u8 @0x248 zeroed (0x6cb0a8-0x6cb0c8)
  uint8_t mZero248;          // 0x248 — ctor zero (0x6cb0bc)
  uint8_t mPad249[7];        // 0x249 — unproven padding
  uint8_t mPad250[0x9900];   // 0x250 — unproven padding (member ctor
                             // 0x71006cb614 touched 0x250)
  uint8_t mRing9b50[0xa00];  // 0x9b50 — 32 entries stride 0x50 (ctor pair
                             // 0x7100662f30 + 0x710061cc48, vptrs cells
                             // 0x130d910/0x130d9a0-0x9a8/0x12fb728;
                             // 0x6cb0d0-0x6cb158)
  uint8_t mBlocka550[0xb00]; // 0xa550 — 8 members stride 0x160, ctor
                             // 0x71006cabb0 (0x6cb164-0x6cb1f8)
  int32_t mMinus1b050;       // 0xb050 — -1 (0x6cb208)
  uint8_t mFlagb054;         // 0xb054 — 1 (0x6cb21c)
  uint8_t mPadb055[3];       // 0xb055 — unproven padding
  void* mZerob058;           // 0xb058 — ctor zero (0x6cb228)
};
}  // namespace object::Kart
