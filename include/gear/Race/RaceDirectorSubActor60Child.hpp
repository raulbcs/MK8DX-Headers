#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSubActor60Child — PROVISIONAL vtable-anchored name. The child
// RaceDirectorSubActor60 creates at +0x60: ctor 0x7100066ba8 (base 0x7c0b3c
// -> Actor), vtable 0x11b4348 (GOT 0x12fbf10). Size 0xB0 (alloc inside the
// parent ctor 0x66470-0x6647c). No own fields.
// Baptism audit: child ctor 0x66ba8 (base 0x7c0b3c), no own fields, no name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear {
class RaceDirectorSubActor60Child : public Actor {
 public:
  uint8_t pad38[0x78];  //0x38 - 0xAF — unproven padding
};
}  // namespace gear
