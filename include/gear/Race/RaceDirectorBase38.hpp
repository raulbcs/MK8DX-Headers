#pragma once

#include <cstdint>

// gear::RaceDirectorBase38 — PROVISIONAL vtable-anchored name; 0x38 POD
// base of the far-family classes (ctor 0x71007b976c, vtable 0x12c55b8).
// Details: doc/gear/Race/RaceDirectorBase38.md

namespace gear {
class RaceDirectorBase38 {
 public:
  void* vtable;      //0x00 — vtable ptr (cell 0x130fea0)
  uint8_t pad08[8];  //0x08 — untouched by ctor
  uint64_t mZero10;  //0x10 — ctor zero
  uint64_t mZero18;  //0x18 — ctor zero
  uint64_t mZero20;  //0x20 — ctor zero
  uint64_t mZero28;  //0x28 — ctor zero
  uint64_t mZero30;  //0x30 — ctor zero
  // (0x38 total)
  // extent 0x38 (ctor 0x71007B976C stores reach 0x38)
};
}  // namespace gear
