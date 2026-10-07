#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// RaceDirectorVt6 — PROVISIONAL vtable-anchored name. Vtable 0x11b3598
// (GOT 0x12fbd10; the doc's 0x11b35a8 is the D1 slot, not the vptr),
// typeinfo 0x53720 ("*(u32*)(this+0x9c) == 0"). Derives from
// RaceDirectorVt2 (ctor 0x710005377c). Size 0xD8, proven by the allocation
// site 0x710006ef64. Seeds 0xb8 with the rodata constant 11 and copies two
// rodata tables ([0xf57b7c] u64 + u32) into 0xc0/0xc8.
// Baptism audit: rodata-seeded config (11 at 0xb8, two tables at 0xc0/0xc8); no name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorVt6 : public RaceDirectorVt2
 {
 public:
 uint32_t mState9c; //0x9C — ctor zero
 uint32_t mZeroa0; //0xA0
 uint32_t mZeroa4; //0xA4
 uint32_t mTicks600; //0xA8 — ctor sets 600
 int32_t mMinus1ac; //0xAC — ctor sets -1
 uint32_t mZerob0; //0xB0
 uint32_t mZerob4; //0xB4
 uint32_t mCount11b8; //0xB8 — ctor copies *(u32*)rodata 0xf73bb4 (== 11)
 uint32_t mZerobc; //0xBC
 uint64_t mTableC0; //0xC0 — ctor copies *(u64*)rodata 0xf57b7c
 uint32_t mTableC8; //0xC8 — ctor copies *(u32*)(0xf57b7c+8)
 uint16_t mZerocc; //0xCC — ctor zero (u16)
 uint32_t mZerod0; //0xD0
 // (0xD8 total)
 };
}
