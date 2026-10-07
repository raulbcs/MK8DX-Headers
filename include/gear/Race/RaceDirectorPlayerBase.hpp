#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorPlayerBase — PROVISIONAL vtable-anchored name. Vtable
// 0x12c5a88 (GOT cell 0x130fee8), far-family gap member reclassified: the
// PRIMARY BASE of RaceDirectorPlayer. The player ctor (0x7100070cb4) calls
// 0x7c2a90 at offset 0 — it runs ctor 0x7b976c (RaceDirectorBase38),
// zeroes 0x38..0x57 and stores this vptr; the player then overwrites the
// vptr with its own (0x12fc060 cell) and starts its fields at 0x58.
// Baptism audit: base-subobject gap member (ctor 0x7c2a90); nothing to baptize beyond the derived class.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorPlayerBase : public RaceDirectorBase38
 {
 public:
 uint32_t mField38; //0x38 — ctor zero (child-array cursor)
 uint8_t pad3c[4]; //0x3c — unproven padding
 uint64_t mZero40; //0x40 — ctor zero (child array base)
 uint64_t mZero48; //0x48 — ctor zero
 void* mField50; //0x50 — ctor zero (child count)
 // (0x58 total)
 };
}
