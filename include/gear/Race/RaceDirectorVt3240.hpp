#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// Naming: consumer proven — ctor 0x501c54 is the mode-id-4 branch of the
// per-mode list-node dispatcher 0x398c00-0x398e98; the dispatcher never names it.

namespace gear {
// RaceDirectorVt3240 — PROVISIONAL vtable-anchored name (vptr from cell
// 0x12fb038; .data 0x1283240). Far-family director, 24 slots; ctor 0x501c54,
// extent 0x138 (alloc 0x398e24). Base ctor 0x7b976c.
// Details: doc/gear/Race/RaceDirectorVt3240.md
class RaceDirectorVt3240 : public RaceDirectorBase38 {
 public:
  uint32_t mZero38;      // 0x38 — ctor zero
  uint8_t pad3c[4];      // 0x3c — unproven padding
  uint64_t mZero40;      // 0x40 — ctor zero
  uint64_t mZero48;      // 0x48 — ctor zero
  uint8_t mGap50[0x30];  // 0x50 — untouched by ctor
  uint64_t mZero80;      // 0x80 — ctor zero
  uint64_t mZero88;      // 0x88 — ctor zero
  uint64_t mZero90;      // 0x90 — ctor zero
  uint64_t mZero98;      // 0x98 — ctor zero
  uint64_t mZeroA0;      // 0xa0 — ctor zero
  uint32_t mZeroA8;      // 0xa8 — ctor zero
  int32_t mMinus1Ac;     // 0xac — ctor sets -1
  uint64_t mZeroB0;      // 0xb0 — ctor zero
  void* mVtableB8;       // 0xb8 — cell 0x12fb038 (+0x10), vptr-shaped
  uint64_t mZeroC0;      // 0xc0 — ctor zero
  uint8_t mZeroC8;       // 0xc8 — ctor zero
  uint8_t padC9[7];      // 0xc9 — unproven padding
  uint64_t mZeroD0;      // 0xd0 — ctor zero
  uint64_t mZeroD8;      // 0xd8 — ctor zero
  uint64_t mZeroE0;      // 0xe0 — ctor zero
  uint8_t mSubE8[0x34];  // 0xe8 — sub-object (vptr cell 0x12fd480, init 0x7c355c)
  uint64_t mZero11c;     // 0x11c — ctor zero
  uint8_t mPad124[0x4];  // 0x124 — unproven gap
  uint32_t mTwelve128;   // 0x128 — ctor sets 12
  uint32_t mZero12c;     // 0x12c — ctor zero
  uint16_t mZero130;     // 0x130 — ctor zero
  uint8_t mZero132;      // 0x132 — ctor zero
  uint8_t pad133;        // 0x133 — unproven padding
  int32_t mMinus150134;  // 0x134 — ctor sets -150
  // (0x138 total)
};
}  // namespace gear
