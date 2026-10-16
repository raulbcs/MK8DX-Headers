#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetChildActor80 — PROVISIONAL vtable-anchored name. Fallback
// child director of RaceDirectorPlayerSet; ctor 0x710006e5e0, vtable
// 0x11b46d8, size 0x80 (factory alloc 0x6f12c); owner at +0x58.
// Details: doc/gear/Race/RaceDirectorSetChildActor80.md

namespace gear {
class RaceDirectorSetChildActor80 : public Actor {
 public:
  uint8_t pad38[0x20];  //0x38 — ctor zeroes 0x38-0x57
  void* mOwner58;       //0x58 — ctor arg x1
  uint8_t pad60[0x20];  //0x60 — zeroes to 0x7F
};
}  // namespace gear
