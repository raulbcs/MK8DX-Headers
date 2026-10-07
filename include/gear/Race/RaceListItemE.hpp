#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceListItemE — PROVISIONAL vtable-anchored name ("E"). Manager list item
// of the far race family (NOT a RaceDirector child — reuses the enter/calc/
// exit slot block only). Vtable 0x11b89c8 (GOT 0x12fcc80). Ctor 0x7100c8138
// (Actor base 0x7b976c). Size 0xB00. Wired by its manager: child+0x18=self,
// +0x20 intrusive node, +0x28=&manager+0x178, +0x30=[manager+0x1A8];
// manager+0x1C0++.
// Baptism audit 2026-10-07: manager list item wired by the per-mode dispatcher (mgr+0x178/+0x1a8/+0x1c0); mode id selects ctor and size; no binary name.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceListItemE : public Actor
    {
        public:
            void* mList70;       //0x70 — intrusive list head
            void* mList88;       //0x88 — list head
            void* mList90;       //0x90 — list head
            uint32_t mFive98;    //0x98 — ctor sets 5
            uint8_t mNodeArrays140[0x24c]; //0x140 - 0x38B — fixed-stride node
                                 // arrays (next/prev self-links)
            uint8_t zero3B0[0x200]; //0x3B0 - 0x5AF — ctor zeroes
            struct Cfg30 { uint8_t bytes[0x30]; };
            Cfg30 mCfg5b8;       //0x5B8 — four 0x30-byte copies of the global
            Cfg30 mCfg618;       //0x618 — pair block [0x12fb188]; ctor overlays
            Cfg30 mCfg678;       //0x678 — f32 10.0 at +0x38 and f32 1.0 at +0x4C
            Cfg30 mCfg6d8;       //0x6D8 — of each block (0x5F0/0x650/0x6B0/0x710,
                                 // 0x604/0x664/0x6C4/0x724)
            uint8_t zero730[0x30]; //0x730
            void* mMember730;    //0x730 — ctor 0x62c3a8
            void* mMember7f0;    //0x7F0 — ctor 0x62c3a8 (stride 0xC0)
            void* mMember8b0;    //0x8B0 — ctor 0x62c3a8
            void* mMember970;    //0x970 — ctor 0x62c3a8
            uint8_t zero9b0[0x150]; //0x9B0 - 0xAFF
            // (0xB00 total)
    };
}
