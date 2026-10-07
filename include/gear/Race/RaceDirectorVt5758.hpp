#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorVt5758 — PROVISIONAL vtable-anchored name (vptr 0x12c5758,
// GOT cell 0x130feb0). Far-family singleton: ctor 0x71007b9a2c (in the
// 0x71007b98bc lazy-init region) runs ctor 0x71007b976c
// (RaceDirectorBase38), then zeroes 0x40..0x7f, stores 1 at 0x84, a pair
// from the global object [0x12fb168] at 0x8c/0x94, zeros to 0xad, and
// builds a dynamic array at 0x40 plus three members at 0x68 (new 0x18,
// ctor 0x71007c27bc), 0x70 (new 0x18, ctor 0x71007c27bc) and 0x78 (new
// 0x70, virtual factory on arg x20 + init 0x71007c55cc). Extent 0xae;
// size 0xb0.
// Baptism audit 2026-10-07: lazy singleton in the 0x7b98bc init region; consumers unexamined beyond the ctor; no name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceDirectorVt5758 : public RaceDirectorBase38
    {
        public:
            uint32_t mField38;   //0x38 — ctor zero, set to 1 after the array
                                 // allocation succeeds
            uint8_t pad3c[4];    //0x3c — unproven padding
            void* mArray40;      //0x40 — new[] of [global 0x12fb168]+8 entries,
                                 // zero-filled loop
            uint8_t mPad48[0x4]; // 0x48 — unproven gap
            uint32_t mZero4c;    //0x4c — ctor zero
            uint8_t pad50[0x10]; //0x50 — unproven padding
            uint8_t mPad60[0x8]; // 0x60 — unproven gap
            void* mObj68;        //0x68 — new(0x18), ctor 0x71007c27bc
            void* mObj70;        //0x70 — new(0x18), ctor 0x71007c27bc
            void* mObj78;        //0x78 — new(0x70), virtual factory on the ctor
                                 // arg + init 0x71007c55cc
            uint8_t mZero80;     //0x80 — ctor zero
            uint8_t pad81[3];    //0x81 — unproven padding
            uint64_t mOne84;     //0x84 — ctor sets 1
            uint64_t mPair8c;    //0x8c — copied from [global 0x12fb168]
            uint32_t mPair94;    //0x94 — copied from [global+8]
            uint32_t mZero98;    //0x98 — ctor zero
            uint16_t mZero9c;    //0x9c — ctor zero
            uint8_t pad9e[2];    //0x9e — unproven padding
            uint8_t mZeroA0[0xe]; //0xa0 — ctor zeroes 0xa0..0xad (two
                                 // overlapping stores: u64 @0xa0, unaligned
                                 // u64 @0xa6)
            // (0xb0 total, binary extent 0xae)
    };
}
