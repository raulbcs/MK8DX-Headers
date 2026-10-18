#pragma once

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorVtac30 — PROVISIONAL vtable-anchored name (vptr 0x12cac30,
// GOT cell 0x13105b8; cell holds vt-0x10, vptr = cell+0x10). Far-family
// director leaf, size 0x68. Details: doc/gear/Race/RaceDirectorVtac30.md

namespace gear {
class RaceDirectorVtac30 : public RaceDirectorBase38 {
 public:
  uint32_t mZero38;     //0x38 — ctor zero
  uint8_t pad3c[4];     //0x3c — unproven padding
  uint64_t mZero40;     //0x40 — ctor zero
  uint64_t mZero48;     //0x48 — ctor zero
  void* mParam50;       //0x50 — ctor arg1
  uint64_t mZero58;     //0x58 — ctor zero
  uint8_t mFF60;        //0x60 — ctor 0xff
  uint8_t pad61[0x7];   //0x61 — unverified (covered by derived new 0x68)
};
}  // namespace gear
