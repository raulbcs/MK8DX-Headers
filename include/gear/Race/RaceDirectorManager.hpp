#pragma once

#include <cstdint>

// RaceDirectorManager — PROVISIONAL vtable-anchored name ("A" in the
// hierarchy pass). Vtable 0x11b3808 (GOT 0x12fbd40), typeinfo 0x58568
// (predicate on this+0x9c). Ctor 0x710005876c — base ctor 0x7b98bc is NOT
// the Actor chain: it is RaceDirectorManagerBase (vtable 0x12c5638,
// size 0x68 — see RaceDirectorManagerBase.hpp); this class overwrites the
// vptr at offset 0 and starts its own fields at 0x68. Kept flat here (the
// named 0x08/0x50/0x58 fields sit inside the base extent, written by this
// ctor). The class reuses the child-array pattern
// 0x38/0x40/0x4C. Size 0x1A0, proven by the allocation site 0x710013d994.
// Top-level race director manager: owns the per-player directors
// (RaceDirectorPlayer) and ~14 per-player data tables.
// Baptism audit 2026-10-07: consumers: allocation site 0x13d994 and the per-player loop 0x58c44-0x58cd8; the class owns the per-player RaceDirectorPlayer vector, but no string or method-tree entry names it.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceDirectorManager
    {
        public:
            void* vtable;           //0x00 — vtable ptr (ctor 0x5879c)
            void* mObj8;            //0x08 — object built by 0x62ee28
            uint8_t pad10[0x40];    //0x10 — unproven padding
            void* mTable50;         //0x50 — new(0x59C0) via ctor 0x66940 (0x58bd4)
            uint32_t mVec58lo;      //0x58 — per-player director vector: the loop
            uint32_t mVec5c;        //0x5C — bound is loaded from [this+0x5C]
                                    // (0x58c44-0x58cd8); 0x58/0x5C form a
                                    // non-8-aligned pair — declare as raw u32s
            void* mVec60;           //0x60 — vector end/cap
            uint8_t pad68[0x28];    //0x68 — unproven padding
            void* mObj90;           //0x90 — ctor writes (0x588c0 region)
            uint8_t pad98[0x14];    //0x98 — unproven padding
            uint32_t mFieldAc;      //0xAC — ctor writes
            uint8_t padB0[0x10];    //0xB0 — unproven padding
            // +0xC0..+0x198: ~14 allocated arrays (0x60b3fc + memset 0xb52770),
            // per-player data tables (ctor 0x58d7c-0x59244)
            uint8_t mTablesC0[0xd8]; //0xC0 - 0x197
            uint8_t pad198[8];      //0x198 — unproven padding
            // (0x1A0 total)
    };
}
