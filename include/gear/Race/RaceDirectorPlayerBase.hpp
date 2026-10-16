#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// gear::RaceDirectorPlayerBase — PROVISIONAL vtable-anchored name;
// primary base of RaceDirectorPlayer (vtable 0x12c5a88, size 0x58).
// Details: doc/gear/Race/RaceDirectorPlayerBase.md

namespace gear {
class RaceDirectorPlayerBase : public RaceDirectorBase38 {
 public:
  uint32_t mField38;  //0x38 — ctor zero (child-array cursor)
  uint8_t pad3c[4];   //0x3c — unproven padding
  uint64_t mZero40;   //0x40 — ctor zero (child array base)
  uint64_t mZero48;   //0x48 — ctor zero
  void* mField50;     //0x50 — ctor zero (child count)
  // (0x58 total)
  // extent 0x58 (ctor 0x71007c2a90 stores reach 0x58)
};
}  // namespace gear
