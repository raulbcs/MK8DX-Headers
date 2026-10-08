#pragma once

#include <cstdint>

#include "RaceDirectorSetChainMid.hpp"

// RaceDirectorSetChainA — PROVISIONAL vtable-anchored name. Chain variant
// (ctor 0x7100061514, vtable 0x11b3c98 / GOT 0x12fbe18). Size 0x100 (factory
// allocs 0x6ed40/0x6ef10/0x6f00c/0x6f2d8).
// Baptism audit: chain variant: four factory allocs (0x6ed40/0x6ef10/0x6f00c/0x6f2d8) and no strings anywhere in the TU; behavior unmapped beyond the ctor.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear {
class RaceDirectorSetChainA : public RaceDirectorSetChainMid {
 public:
  uint64_t mListF8;  //0xF8 — ctor zero; list/map head
  // (0x100 total)
};
}  // namespace gear
