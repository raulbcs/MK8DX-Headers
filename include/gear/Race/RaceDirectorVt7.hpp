#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// RaceDirectorVt7 — PROVISIONAL vtable-anchored name. Vtable 0x11b36d0
// (GOT 0x12fbd28; 0x11b36e0 is the D1 slot), typeinfo 0x56b28
// ("(*(u32*)(this+0x9c) | 1) == 1" — accepts state 0 or 1). Derives from
// RaceDirectorVt2 (ctor 0x7100056ba8). Size 0xC8, proven by the allocation
// site 0x710006f06c (guarded by the race-check-manager flag at 0x6efac).
// Overrides both slot 0xd0 (0x58374) and 0xd8 (0x58338) — the only one of
// the set that does.
// Baptism audit predicate accepts state 0/1; only member overriding slots 0xd0/0xd8; no name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
 class RaceDirectorVt7 : public RaceDirectorVt2
 {
 public:
 uint32_t mState9c; //0x9C — ctor zero
 uint32_t mZeroa0; //0xA0
 uint32_t mZeroa4; //0xA4
 uint32_t mTicks600; //0xA8 — ctor sets 600
 int32_t mMinus1ac; //0xAC — ctor sets -1
 uint32_t mZerob0; //0xB0
 uint8_t mZerob4; //0xB4
 uint8_t mZerob5; //0xB5 — ctor zero (byte)
 uint8_t pad_b6[8]; //0xB6 - 0xBD — unproven padding
 uint16_t mUbe; //0xBE — ctor packs *(u32*)rodata 0xf73bb4 (== 11,
 // unaligned 4-byte store) over 0xbe..0xc1
 uint16_t mUc0; //0xC0 — upper half of the same rodata copy
 uint32_t mZeroc4; //0xC4
 // (0xC8 total)
 };
}
