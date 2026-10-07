#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetChildActor80 — PROVISIONAL vtable-anchored name. Fallback
// child director of RaceDirectorPlayerSet: ctor 0x710006e5e0 (Actor base),
// vtable 0x11b46d8 (GOT 0x12fbf90). Size 0x80 (factory alloc 0x6f12c; used
// in the fallback dispatch branch). Owner back-pointer at +0x58.
// Baptism audit fallback child ctor 0x6e5e0; only the factory branch 0x6f12c names nothing.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorSetChildActor80 : public Actor
 {
 public:
 uint8_t pad38[0x20]; //0x38 — ctor zeroes 0x38-0x57
 void* mOwner58; //0x58 — ctor arg x1
 uint8_t pad60[0x20]; //0x60 — zeroes to 0x7F
 };
}
