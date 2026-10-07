#pragma once

#include <cstdint>

#include "RaceDirectorVt2.hpp"

// RaceDirectorVt5 — PROVISIONAL vtable-anchored name. Vtable 0x11b3460
// (GOT 0x12fbcf8), typeinfo 0x5114c ("*(u32*)(this+0x9c) == 0"). Derives
// from RaceDirectorVt2 (ctor 0x71000511a8). Size 0xC8, proven by the
// allocation site 0x710006f32c. Carries a state machine on +0x9c (states
// 0..0xa, jump table rodata 0xf210438) with RaceInfo distance checks and
// item-box tables ([child+0x150..0x188]) in its slot-0x70-family logic
// (0x51200+).
// Baptism audit 2026-10-07: state machine 0..0xa with item-box tables and RaceInfo distance checks; the state jump-table rodata carries no label.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceDirectorVt5 : public RaceDirectorVt2
    {
        public:
            uint32_t mState9c; //0x9C — state machine 0..0xa
            uint32_t mZeroa0;  //0xA0
            uint32_t mZeroa4;  //0xA4
            uint32_t mZeroa8;  //0xA8
            uint32_t mTicks600; //0xAC — ctor sets 600
            int32_t mMinus1b0; //0xB0 — ctor sets -1
            uint32_t mZerob4;  //0xB4
            uint32_t mZerob8;  //0xB8
            uint16_t mFfffbc;  //0xBC — ctor sets 0xFFFF
            uint16_t mFfffbe;  //0xBE — ctor sets 0xFFFF
            uint32_t mZeroc0;  //0xC0
            // (0xC8 total)
    };
}
