#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorVt5758 — PROVISIONAL vtable-anchored name (vptr 0x12c5758,
// GOT cell 0x130feb0). Far-family lazy singleton in the 0x7b98bc init
// region; ctor 0x71007b9a2c; extent 0xae, size 0xb0.
// Details: doc/gear/Race/RaceDirectorVt5758.md

namespace gear {
class RaceDirectorVt5758 : public RaceDirectorBase38 {
 public:
  uint32_t mField38;     //0x38 — ctor zero, set to 1 after the array allocation succeeds
  uint8_t pad3c[4];      //0x3c — unproven padding
  void* mArray40;        //0x40 — new[] of [global 0x12fb168]+8 entries, zero-filled loop
  uint8_t mPad48[0x4];   // 0x48 — unproven gap
  uint32_t mZero4c;      //0x4c — ctor zero
  uint8_t pad50[0x10];   //0x50 — unproven padding
  uint8_t mPad60[0x8];   // 0x60 — unproven gap
  void* mObj68;          //0x68 — new(0x18), ctor 0x71007c27bc
  void* mObj70;          //0x70 — new(0x18), ctor 0x71007c27bc
  void* mObj78;          //0x78 — new(0x70), virtual factory + init 0x71007c55cc
  uint8_t mZero80;       //0x80 — ctor zero
  uint8_t pad81[3];      //0x81 — unproven padding
  uint64_t mOne84;       //0x84 — ctor sets 1
  uint64_t mPair8c;      //0x8c — copied from [global 0x12fb168]
  uint32_t mPair94;      //0x94 — copied from [global+8]
  uint32_t mZero98;      //0x98 — ctor zero
  uint16_t mZero9c;      //0x9c — ctor zero
  uint8_t pad9e[2];      //0x9e — unproven padding
  uint8_t mZeroA0[0xe];  //0xa0 — ctor zeroes 0xa0..0xad (u64 @0xa0 + unaligned u64 @0xa6)
  uint8_t pad_AE[0x2];   //0xAE — unproven gap (0xb0 total, binary extent 0xae)
};
}  // namespace gear
