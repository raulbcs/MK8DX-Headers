#pragma once

#include <cstdint>

namespace object {
// KartParamCacheVt6e60 — address-anchored name (vptr 0x12b6e60, GOT cell
// 0x130e1f8; cell holds vt-0x10). Single-vptr param-cache variant constructed
// in place at outer+0x16a0 by 0x71006c0b68 (size bounded 0x738 by the next
// member). C1 0x71006c0b68.
// extent 0x738 - details: doc/object/Kart/KartParamCacheVt6e60.md
class KartParamCacheVt6e60 {
 public:
  void* vptr;              // 0x00 — cell 0x130e1f8 + 0x10 (0x6c0be0)
  uint8_t mOwn8[0x240];    // 0x08 — own-field region (base stub 0x71006c6128)
  uint8_t mZero248[0x18];  // 0x248 — ctor zeros (0x6c0b8c-0x6c0bb0)
  float mF260;             // 0x260 — 1.0f (0x6c0bc8)
  uint32_t mFlags264;      // 0x264 — ctor flags, |0x30000 (0x6c0cc0)
  uint64_t mZero268;       // 0x268 — ctor zero (0x6c0bb0)
  uint64_t mMinus1_270;    // 0x270 — -1 (0x6c0cbc)
  uint64_t mMinus1_278;    // 0x278 — -1
  int32_t mMinus1_280;     // 0x280 — -1 (0x6c0cb4)
  float mF284;             // 0x284 — 100.0f (0x6c0bd4)
  uint64_t mMinus1_288;    // 0x288 — -1 (0x6c0ce8)
  uint8_t mBlock290[0x70]; // 0x290 — config pair block from globals
                           // [0x12fadb8]/[0x12fce50]/[0x12fce10]
                           // (0x6c0bd8-0x6c0d20; incl. -1 fills)
  uint8_t mZero300[0x18];  // 0x300 — ctor zeros (0x6c0c1c-0x6c0c30)
  char mChan318[0x18];     // 0x318 — member vptr cell 0x12fada0, ctor
                           // 0x710061cc48, u32 0x104 @0x328 (0x6c0c38-0x6c0c4c)
  uint8_t mPad330[0x100];  // 0x330 — unproven padding
  char mChan430[0x18];     // 0x430 — member vptr cell 0x130e200, u32 0x104
                           // @0x440 (0x6c0c64-0x6c0c88)
  uint8_t mPad448[0x100];  // 0x448 — unproven padding
  uint8_t mZero548[8];     // 0x548 — ctor zeros (0x6c0cc4/0x6c0d24)
  uint8_t mPad550[8];      // 0x550 — unproven padding
  char mMember558[0x1e0];  // 0x558 — member ctor 0x71006461e4; size to the
                           // 0x738 bound unverified
};
}  // namespace object
