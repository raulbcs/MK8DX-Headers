#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// Baptism audit 2026-10-07: RECLASSIFIED by consumer evidence: ctor 0x7d5450 is the primary base of RaceListItemF (same chain cited in RaceListItemF.hpp); far-family base-subobject, not an independent director. Name stays PROVISIONAL.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    // RaceDirectorVt7e38 — PROVISIONAL vtable-anchored name (vptr written by
    // the ctor from cell 0x12fcd00; .data 0x12c7e38). Far-family director,
    // 30 slots. Ctor 0x7d5450, size 0x180 (alloc 0x8bc7a8: new 0x180).
    // Base: RaceDirectorBase38 (ctor 0x7b976c).
    //
    // Ctor field map: 0x38 u32 = 0; 0x40/0x48 u64 = 0; 0x50 list init
    // (0x60b918, count 4, end this+0x60); 0x80 u8 = 1; 0x88 u64 = 0;
    // 0x90 s32 = -1; 0x98 u64 = 0; 0xa0/0xa8 u64 = 0; 0xb0 s32 = -1;
    // 0xb4 u8 = 1; 0xb8 sub-object (ctor 0x8df668, to 0x130);
    // 0x130 u32 = 0; 0x138 u64 = 0; 0x140 member sub-object
    // (ctor 0x628628, extent 0x40 — fills the alloc to 0x180).
    // Gap: 0x60..0x7f and 0x8c..0x8f untouched by the ctor.
    class RaceDirectorVt7e38 : public RaceDirectorBase38
    {
    public:
        uint32_t mZero38;      // 0x38 — ctor zero
        uint8_t pad3c[4];      // 0x3c — unproven padding
        uint64_t mZero40;      // 0x40 — ctor zero
        uint64_t mZero48;      // 0x48 — ctor zero
        uint8_t mList50[0x30]; // 0x50 — list init 0x60b918 (count 4)
        uint8_t mOne80;        // 0x80 — ctor sets 1
        uint8_t pad81[7];      // 0x81 — unproven padding
        uint64_t mZero88;      // 0x88 — ctor zero
        int32_t mMinus190;     // 0x90 — ctor sets -1
        uint32_t pad94;        // 0x94 — unproven padding
        uint64_t mZero98;      // 0x98 — ctor zero
        uint64_t mZeroA0;      // 0xa0 — ctor zero
        uint64_t mZeroA8;      // 0xa8 — ctor zero
        int32_t mMinus1B0;     // 0xb0 — ctor sets -1
        uint8_t mOneB4;        // 0xb4 — ctor sets 1
        uint8_t padB5[3];      // 0xb5 — unproven padding
        uint8_t mSubB8[0x78];  // 0xb8 — sub-object (ctor 0x8df668)
        uint32_t mZero130;     // 0x130 — ctor zero
        uint32_t pad134;       // 0x134 — unproven padding
        uint64_t mZero138;     // 0x138 — ctor zero
        uint8_t mSub140[0x40]; // 0x140 — member sub-object (ctor 0x628628)
        // (0x180 total)
    };
}
