#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// RaceDirectorVt4 — PROVISIONAL vtable-anchored name. Vtable 0x11b3328
// (.data anchor; GOT 0x12fbce0), typeinfo 0x4fc94 (per-object predicate on
// this+0x9c). Derives from RaceDirectorVt2 (ctor 0x710004fd6c). Size 0xC0,
// proven by the allocation site 0x710006ee7c. Built by the director factory
// 0x710006eb5c (dispatches on getRaceCheckManager [x0+8]/[x0+0xc] == 3) and
// stored at [parent+0xa8].
// Baptism audit: predicate (this+0x9c) selector built when getRaceCheckManager flags == 3; no name evidence.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorVt4 : public RaceDirectorVt2
 {
 public:
 uint32_t mZero9c; //0x9C — ctor zero
 uint32_t mZeroa0; //0xA0
 uint32_t mZeroa4; //0xA4
 uint32_t mTicks600; //0xA8 — ctor sets 600 (0x258)
 int32_t mMinus1ac; //0xAC — ctor sets -1
 uint32_t mZerob0; //0xB0
 uint16_t mFfffb8; //0xB8 — ctor sets 0xFFFF
 // slot 0xd0 override getter returns the word at 0xB8
 uint16_t mFfffba; //0xBA — ctor sets 0xFFFF
 uint32_t mZerobc; //0xBC — slot 0xd8 override getter returns this word
 // (0xC0 total)
 };
}
