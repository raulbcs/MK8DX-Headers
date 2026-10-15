#pragma once

#include "KartPhysicsBody.hpp"

namespace object {
// Address-anchored suffix. TS_ItemTeresa evidence; 108 slots.
// Vtable .data 0x11b2310 (GOT cell 0x12fb9f0), ctor 0x710003bfe0, size 0x390
// (factory allocation immediately before the ctor call). Root-derived
// (ctor calls 0x116a4);
class KartPhysicsBodyTeresaVt108 : public KartPhysicsBody {
 public:
  uint32_t mField328;    // 0x328
  uint8_t mPad32c[0x4];  // 0x32c — unproven gap
  uint64_t mField330;    // 0x330
  uint64_t mField338;    // 0x338
  uint8_t mField340;     // 0x340
  uint8_t mPad341;       // 0x341 — ctor zero
  uint8_t mField342;     // 0x342
  uint8_t mField343;     // 0x343
  uint32_t mZero344;     // 0x344 — ctor zero
  void* mSelf348;        // 0x348 — ctor stores `this`
  uint64_t mField350;    // 0x350
  uint64_t mField358;    // 0x358
  uint64_t mField360;    // 0x360 — ctor: call result
  uint32_t mField368;    // 0x368
  uint32_t mField36c;    // 0x36c
  uint32_t mField370;    // 0x370
  uint8_t mPad374;       // 0x374 — ctor zero
  uint8_t mPad375[0x3];  // 0x375 — unproven gap
  uint32_t mField378;    // 0x378
  uint32_t mField37c;    // 0x37c
  uint8_t mPad380;       // 0x380 — ctor zero
  uint8_t mPad381[0x3];  // 0x381 — unproven gap
  uint32_t mField384;    // 0x384
  uint32_t mZero388;     // 0x388 — ctor zero
  uint8_t mField38c;     // 0x38c
  uint8_t pad_38D[0x3];  //0x38D — unproven gap
};
}  // namespace object

// Naming: per item/kart physics-body variant; no distinguishing ctor strings, and the body's semantic identity requires the combo dictionary.
