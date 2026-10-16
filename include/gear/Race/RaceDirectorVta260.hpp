#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorVta260 — PROVISIONAL vtable-anchored name (vptr 0x12ca260,
// GOT cell 0x1310470). Far-family singleton; ctor 0x71007fd3d4; extent 0xc0.
// Sole getter caller 0x13cfa4 (nn::ldn/LAN init region) never names it.
// Details: doc/gear/Race/RaceDirectorVta260.md

namespace gear {
class RaceDirectorVta260 : public RaceDirectorBase38 {
 public:
  uint32_t mField38;     //0x38 — ctor zero
  uint8_t pad3c[4];      //0x3c — unproven padding
  uint64_t mZero40;      //0x40 — ctor zero
  uint64_t mZero48;      //0x48 — ctor zero
  uint8_t mPad50[0x60];  //0x50 — untouched by ctor
  uint64_t mZeroB0;      //0xb0 — ctor zero (final stp covers
  // 0xb0..0xbf, so extent 0xc0)
  uint64_t mZeroB8;  //0xb8 — ctor zero
  // (0xc0 total)
};
}  // namespace gear
