#pragma once

#include <cstdint>

#include "RaceDirectorSetChild80.hpp"

// RaceDirectorSetChild80Derived — PROVISIONAL vtable-anchored name. The
// concrete variant of RaceDirectorSetChild80: ctor 0x710006e9d0 only re-tags
// the vtable (0x11b4788, GOT 0x12fbfc0). Size 0x80 (factory allocs 0x6ece8/
// 0x6edd8/0x6eebc/0x6efb8/0x6f280 — built in EVERY dispatch branch; the
// primary child-director variant).
// Baptism audit: vtable re-tag ctor 0x6e9d0; built in every factory dispatch branch, yet no strings/method-tree in reach.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorSetChild80Derived : public RaceDirectorSetChild80 {};
}
