#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// RaceDirectorVt3 — PROVISIONAL vtable-anchored name. Vtable 0x11b31e8
// (.data 0x11b31d8, GOT 0x12fbcc0), typeinfo 0x4e6f8. Derives from
// RaceDirectorVt2 (ctor 0x710004e784 calls 0x4e2f4). Carries a 600-tick
// timer (0xa4) and -1 sentinels. Size 0xC0, proven by the sole allocation
// site 0x710006ed94 (new 0xC0, then shared actor-registration tail 0x6f348).
// The per-frame calc hook is the slot-0x108 override 0x4e7dc (reads [0x50]
// config and [0x58], RaceInfo lookup, then slot-0x138 vcall on the 0x58 child).
// Baptism audit 2026-10-07: 600-tick timer + -1 sentinels; per-frame calc 0x4e7dc reads config and calls a child vcall; no rodata name in the TU.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceDirectorVt3 : public RaceDirectorVt2
    {
        public:
            uint32_t mZero9c;  //0x9C — ctor zero (qword store covers 0x9c-0xa3)
            uint32_t mZeroa0;  //0xA0
            uint32_t mTicks600; //0xA4 — ctor sets 600 (0x258)
            uint32_t mZeroa8;  //0xA8 — ctor zero
            int32_t mMinus1ac; //0xAC — ctor sets -1
            int32_t mMinus1b0; //0xB0 — ctor sets -1
            int32_t mMinus1b8; //0xB8 — ctor copies *(u32*)rodata 0xf73bb4
                // (== 0xFFFFFFFF); rodata cell also holds 11 for Vt6/Vt7
            uint32_t mZerobc;  //0xBC
            // (0xC0 total)
    };
}
