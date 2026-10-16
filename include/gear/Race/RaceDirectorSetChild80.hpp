#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetChild80 — PROVISIONAL vtable-anchored name. Abstract-style
// child director of RaceDirectorPlayerSet; ctor 0x710006ded4, vtable
// 0x11b4650, size 0x80 (factory alloc 0x6f184); owner at +0x58.
// Details: doc/gear/Race/RaceDirectorSetChild80.md

namespace gear {
class RaceDirectorSetChild80 : public Actor {
 public:
  uint8_t pad38[0x20];  //0x38 — ctor zeroes 0x38-0x57
  void* mOwner58;       //0x58 — ctor arg x1 (the PlayerSet)
  uint8_t pad60[0x20];  //0x60 — ctor zeroes to 0x7F
};
}  // namespace gear
