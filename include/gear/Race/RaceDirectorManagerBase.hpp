#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// gear::RaceDirectorManagerBase — PROVISIONAL vtable-anchored name;
// primary base of RaceDirectorManager (vtable 0x12c5638, size 0x68).
// Details: doc/gear/Race/RaceDirectorManagerBase.md

namespace gear {
class RaceDirectorManagerBase : public RaceDirectorBase38 {
 public:
  uint32_t mField38;  //0x38 — ctor zero (the child-array cursor)
  uint8_t pad3c[4];   //0x3c — unproven padding
  void* mField40;     //0x40 — ctor zero (child array base)
  uint64_t mZero48;   //0x48 — ctor zero
  uint64_t mZero50;   //0x50 — ctor zero
  uint64_t mZero58;   //0x58 — ctor zero
  uint64_t mZero60;   //0x60 — ctor zero
  // (0x68 total)
  // extent 0x68 (prior-survey total 0x68)
};
}  // namespace gear
