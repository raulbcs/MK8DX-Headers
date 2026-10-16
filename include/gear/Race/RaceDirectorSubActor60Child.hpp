#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSubActor60Child — PROVISIONAL vtable-anchored name. Child of
// RaceDirectorSubActor60 at +0x60; ctor 0x7100066ba8 (base 0x7c0b3c),
// vtable 0x11b4348, size 0xB0 (alloc 0x66470-0x6647c). No own fields.
// Details: doc/gear/Race/RaceDirectorSubActor60Child.md

namespace gear {
class RaceDirectorSubActor60Child : public Actor {
 public:
  uint8_t pad38[0x78];  //0x38 - 0xAF — unproven padding
};
}  // namespace gear
