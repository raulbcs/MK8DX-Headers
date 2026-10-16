#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSubActor60 — PROVISIONAL vtable-anchored name. First sub-actor
// RaceDirector creates at +0x60; ctor 0x7100066448 (base 0x7b9a18), vtable
// 0x11b41c8, size 0xB0 (alloc 0x4d8c0). Owns one same-size child (0x66ba8).
// Details: doc/gear/Race/RaceDirectorSubActor60.md

namespace gear {
struct RaceDirectorSubActor60Child;  // RaceDirectorSubActor60Child.hpp

class RaceDirectorSubActor60 : public Actor {
 public:
  uint8_t pad38[0x28];  //0x38 — child array pattern (count/array/cursor),
  // registered by RaceDirector ctor
  RaceDirectorSubActor60Child* mChild60;  //0x60 — new(0xB0), ctor 0x66ba8
  uint8_t pad68[0x48];                    //0x68 — to 0xB0
};
}  // namespace gear
