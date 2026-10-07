#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorPlayerSetBase — PROVISIONAL vtable-anchored name. Vtable
// 0x12c59b0 (GOT cell 0x130fee0), far-family gap member reclassified: the
// PRIMARY BASE of RaceDirectorPlayerSet. The factory ctor (0x71006eb5c)
// calls 0x7c2938 at offset 0 — it runs ctor 0x7b976c (RaceDirectorBase38),
// zeroes 0x38..0x57 and stores this vptr; the factory then overwrites the
// vptr with its own (0x12fbd48 cell) and starts its fields at 0x58.
// Baptism audit 2026-10-07: base-subobject gap member (ctor 0x7c2938); identity from the derived factory ctor only.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceDirectorPlayerSetBase : public RaceDirectorBase38
    {
        public:
            uint32_t mField38;   //0x38 — ctor zero (child-array cursor)
            uint8_t pad3c[4];    //0x3c
            uint64_t mZero40;    //0x40 — ctor zero (child array base)
            uint64_t mZero48;    //0x48 — ctor zero
            void* mField50;      //0x50 — ctor zero (child count)
            // (0x58 total)
    };
}
