#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetLanePool — PROVISIONAL vtable-anchored name. Per-lane
// entry-pool manager of RaceDirectorPlayerSet: ctor 0x7100702e0 (Actor
// base), primary vtable 0x11b4980 (GOT 0x12fc010), secondary at +0x38
// (0x11b4a00, GOT 0x12fc018). Size 0xA8 (factory alloc 0x6f380). Holds
// three 0x30 entry pools; entries are {fn, ctx} callback pairs filled from
// GOT code cells (0x704a4/0x704b0/0x70508/0x705a4). Config (qword+2 dwords)
// copied from the rodata default [0xf57b7c] (dword +8 = -1 at +0x94).
// Baptism audit 2026-10-07: entry-pool manager: {fn,ctx} callbacks from GOT code cells and rodata default [0xf57b7c]; behavior mapped, name not.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear
{
    class RaceDirectorSetLanePool : public Actor
    {
        public:
            uint8_t pad38[8];    //0x38 - 0x3F
            uint8_t b40;         //0x40 — ctor sets 3 (pool count base)
            uint8_t b41;         //0x41 — ctor zero
            uint8_t b42;         //0x42 — ctor zero
            uint8_t pad43;       //0x43
            uint32_t m44;        //0x44 — ctor zero
            void* mSelf48;       //0x48 — self pointer
            void* mPool50;       //0x50 — alloc(0x30) entry pool
            void* mPool58;       //0x58 — alloc(0x30)
            void* mPool60;       //0x60 — alloc(0x30)
            uint64_t mZero68;    //0x68 — ctor zero
            void* mOwner70;      //0x70 — ctor arg x1
            uint8_t pad78[0x10]; //0x78
            uint64_t mCfg88;     //0x88 — *(u64*)[0xf57b7c]
            uint32_t mCfg90;     //0x90 — *(u32*)([0xf57b7c]+8)
            int32_t mMinus1_94;  //0x94 — ctor -1
            uint32_t mZero98;    //0x98
            uint8_t mZer9c[4];   //0x9C — ctor zero
            uint8_t pad_a0[8];   //0xA0 - 0xA7
            // (0xA8 total)
    };
}
