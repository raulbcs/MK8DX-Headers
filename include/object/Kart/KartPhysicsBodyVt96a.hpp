#pragma once

#include "KartPhysicsBody.hpp"

namespace object {
// Address-anchored name. 96 slots.
// Vtable .data 0x11af298 (GOT cell 0x12fb4f8), ctor 0x7100025a4c, size 0x340
// (factory allocation immediately before the ctor call). Root-derived
// (ctor calls 0x116a4);
class KartPhysicsBodyVt96a : public KartPhysicsBody {
 public:
  uint8_t mPad328[0x4];  // 0x328 — unproven gap
  uint8_t mPad32c;       // 0x32c — ctor zero
  uint8_t mPad32d[0x3];  // 0x32d — unproven gap
  uint32_t mField330;    // 0x330 — ctor-written
  uint8_t mPad334[0x4];  // 0x334 — unproven gap
  uint64_t mField338;    // 0x338 — ctor-written
};
}  // namespace object

// Naming closure: per item/kart physics-body variant; no distinguishing ctor strings, and the body's semantic identity requires the combo dictionary. Address-anchored name retained.
