#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSubActor60 — PROVISIONAL vtable-anchored name. The first
// sub-actor RaceDirector creates at +0x60 (ctor 0x7100066448, base
// 0x7b9a18). Size 0xB0, proven by the allocation site inside the
// RaceDirector ctor (0x4d8c0 `mov w0,#0xb0` — corrects the earlier
// "0xB8" note). Vtable 0x11b41c8 (GOT 0x12fbeb0). Owns one same-size
// child (ctor 0x66ba8) registered in its own child array.
// Baptism audit RaceDirector child at +0x60 (ctor 0x66448, size 0xB0); parent ctor is the only consumer; no name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 struct RaceDirectorSubActor60Child; // RaceDirectorSubActor60Child.hpp

 class RaceDirectorSubActor60 : public Actor
 {
 public:
 uint8_t pad38[0x28]; //0x38 — child array pattern (count/array/cursor),
 // registered by RaceDirector ctor
 RaceDirectorSubActor60Child* mChild60; //0x60 — new(0xB0), ctor 0x66ba8
 uint8_t pad68[0x48]; //0x68 — to 0xB0
 };
}
