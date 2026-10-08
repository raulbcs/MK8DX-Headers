#pragma once

#include "KartPhysicsBody.hpp"

namespace object {
// Address-anchored suffix. TS_ItemTeresa evidence; 108 slots.
// Vtable .data 0x11b2310 (GOT cell 0x12fb9f0), ctor 0x710003bfe0, size 0x390
// (factory allocation immediately before the ctor call). Root-derived
// (ctor calls 0x116a4);
class KartPhysicsBodyTeresaVt108 : public KartPhysicsBody {
 public:
  uint32_t mField328;    // 0x328 — ctor-written
  uint8_t mPad32c[0x4];  // 0x32c — unproven gap
  uint64_t mField330;    // 0x330 — ctor-written
  uint64_t mField338;    // 0x338 — ctor-written
  uint8_t mField340;     // 0x340 — ctor-written
  uint8_t mPad341;       // 0x341 — ctor zero
  uint8_t mField342;     // 0x342 — ctor-written
  uint8_t mField343;     // 0x343 — ctor-written
  uint32_t mZero344;     // 0x344 — ctor zero
  void* mSelf348;        // 0x348 — ctor stores `this`
  uint64_t mField350;    // 0x350 — ctor-written
  uint64_t mField358;    // 0x358 — ctor-written
  uint64_t mField360;    // 0x360 — ctor: call result
  uint32_t mField368;    // 0x368 — ctor-written
  uint32_t mField36c;    // 0x36c — ctor-written
  uint32_t mField370;    // 0x370 — ctor-written
  uint8_t mPad374;       // 0x374 — ctor zero
  uint8_t mPad375[0x3];  // 0x375 — unproven gap
  uint32_t mField378;    // 0x378 — ctor-written
  uint32_t mField37c;    // 0x37c — ctor-written
  uint8_t mPad380;       // 0x380 — ctor zero
  uint8_t mPad381[0x3];  // 0x381 — unproven gap
  uint32_t mField384;    // 0x384 — ctor-written
  uint32_t mZero388;     // 0x388 — ctor zero
  uint8_t mField38c;     // 0x38c — ctor-written
};
}  // namespace object

// Naming closure: per item/kart physics-body variant; no distinguishing ctor strings, and the body's semantic identity requires the combo dictionary. Address-anchored name retained.
