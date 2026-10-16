#pragma once

#include <cstdint>

// RaceDirectorSetStatePod — PROVISIONAL vtable-anchored name. 0x3C-byte
// POD state record (ctor 0x71000585c4, NO vtable); 0.25f ratio at +0x24.
// Two instances per RaceDirectorPlayerSet (+0xB8, +0xC0).
// Details: doc/gear/Race/RaceDirectorSetStatePod.md

namespace gear {
struct RaceDirectorSetStatePod {
  uint8_t zero00[0x20];  //0x00 — ctor zeroes 0x00-0x1F
  uint32_t mZero20;      //0x20 — ctor zero
  float mRatio25;        //0x24 — ctor sets 0.25f
  uint32_t mZero28;      //0x28
  uint16_t mZero2c;      //0x2C
  uint8_t pad2e[2];      //0x2E — unproven padding
  uint32_t mZero30;      //0x30
  uint8_t pad34[4];      //0x34 — unproven padding
  uint32_t mZero38;      //0x38
  // (0x3C total)
  // extent 0x3c (ctor 0x71000585C4 stores reach 0x3c)
};
}  // namespace gear
