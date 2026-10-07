#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceDirectorManagerBase — PROVISIONAL vtable-anchored name. Vtable
// 0x12c5638 (GOT cell 0x130fea8, holds vptr-0x10), far-family gap member
// reclassified: it is the PRIMARY BASE of RaceDirectorManager, not a
// member. The manager ctor (0x71005876c) calls 0x7b98bc at offset 0 — it
// runs ctor 0x7b976c (RaceDirectorBase38), zeroes 0x38..0x67 and stores
// this vptr; the manager then overwrites the vptr with its own and starts
// its fields at 0x68.
// Baptism audit 2026-10-07: base-subobject gap member: identity is defined by the derived ctor 0x7b98bc alone; no consumer names it.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceDirectorManagerBase : public RaceDirectorBase38
    {
        public:
            uint32_t mField38;   //0x38 — ctor zero (the child-array cursor)
            uint8_t pad3c[4];    //0x3c
            void* mField40;      //0x40 — ctor zero (child array base)
            uint64_t mZero48;    //0x48 — ctor zero
            uint64_t mZero50;    //0x50 — ctor zero
            uint64_t mZero58;    //0x58 — ctor zero
            uint64_t mZero60;    //0x60 — ctor zero
            // (0x68 total)
    };
}
