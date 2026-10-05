#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorManager — PROVISIONAL vtable-anchored name ("A" in the
// hierarchy pass). Vtable 0x11b3808 (GOT 0x12fbd40), typeinfo 0x58568
// (predicate on this+0x9c). Ctor 0x71005876c (base 0x7b98bc — NOT the
// RaceDirector chain, but reuses the child-array pattern 0x38/0x40/0x4c).
// Size 0x1A0, proven by the allocation site 0x710013d994. Top-level race
// director manager: owns the per-player directors and ~14 per-player data
// tables.
namespace gear
{
    class RaceDirectorManager : public Actor
    {
        public:
            void* mObj8;            //0x08 — object built by 0x62ee28
            uint8_t pad10[0x40];    //0x10
            void* mTable50;         //0x50 — new(0x59C0) via ctor 0x66940 (0x58bd4)
            void* mVec58;           //0x58 — per-player director vector (begin),
                                    // built with 0x60b930; loop 0x58c44-0x58cd8
            uint32_t mVec5c;        //0x5C — per-player count/size (loop bound)
            void* mVec60;           //0x60 — vector end/cap
            uint8_t pad68[0x28];    //0x68
            void* mObj90;           //0x90 — ctor writes (0x588c0 region)
            uint8_t pad98[0x14];    //0x98
            uint32_t mFieldAc;      //0xAC — ctor writes
            uint8_t padB0[0x10];    //0xB0
            // +0xC0..+0x198: ~14 allocated arrays (0x60b3fc + memset 0xb52770),
            // per-player data tables (ctor 0x58d7c-0x59244)
            uint8_t mTablesC0[0xd8]; //0xC0 - 0x197
            uint8_t pad198[8];      //0x198
            // (0x1A0 total)
    };
}
