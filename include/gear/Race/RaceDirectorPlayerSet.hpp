#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorPlayerSet — PROVISIONAL vtable-anchored name ("C"). Per-player
// child-director set/factory: vtable 0x11b4818 (GOT 0x12fbfd8), ctor
// 0x71006eb5c (the director factory, base 0x7c2938), secondary vtable
// 0x11b3c78 at +0x58. Size 0xD0 (allocated by RaceDirectorPlayer ctor
// 0x70e5c). Builds ~17 child directors (alloc -> ctor -> register at the
// 0x38/0x40/0x4C cursor -> store into a set field), dispatching on
// getRaceCheckManager [x0+8]/[x0+0xc] == 3. Named fields hold the
// RaceDirectorVt* chain members.
namespace gear
{
    struct RaceDirectorSetHelper;        // RaceDirectorSetHelper.hpp
    struct RaceDirectorSetLanePool;      // RaceDirectorSetLanePool.hpp
    struct RaceDirectorSetStatePod;      // RaceDirectorSetStatePod.hpp

    class RaceDirectorPlayerSet : public Actor
    {
        public:
            uint8_t pad38[0x18]; //0x38 — child array pattern
            RaceDirectorSetHelper* mHelper50; //0x50 — new(0x40), ctor 0x689c8
            void* mSecondary58;  //0x58 — secondary vptr (0x11b3c78)
            uint8_t mB60;        //0x60 — ctor 0, later 6
            uint8_t mB62;        //0x62 — ctor 0
            uint8_t mB63;        //0x63 — ctor 1
            uint8_t mB64;        //0x64 — ctor 0
            void* mChild68;      //0x68 — self (0x6f3fc)
            void* mSub70;        //0x70 — alloc(0x60) via 0x60b04c (member-offset
                                 // table entries {offset,1} for 0xc8-0x120, 0x6f4a8+)
            void* mSub78;        //0x78 — alloc(0x60)
            void* mSub80;        //0x80 — alloc(0x60)
            void* mChain90;      //0x90 — RaceDirectorSetChainA ctor 0x61514
                                 // (alloc 0x100 @0x6ed40); also Vt2 0x4e2f4 (0x6f11c)
            void* mA8;           //0xA8 — director chain members (0x6ed4c: ctor
                                 // 0x61514, alloc 0x100; also 0x511a8->Vt5 @0x6f338,
                                 // 0x702e0 @0x6f388, 0x628bc @0x6f1e4)
            RaceDirectorSetLanePool* mB0; //0xB0 — new(0xA8), ctor 0x702e0 (0x6f388);
                                 // the Vt3/Vt4/Vt6/Vt7 ctors (0x6eda0/0x6ee88/0x6ef70/
                                 // 0x6f074) dispatch into the chain fields instead
            RaceDirectorSetStatePod* mB8; //0xB8 — new(0x3C), ctor 0x585c4 (0x6f3dc)
            RaceDirectorSetStatePod* mC0; //0xC0 — second POD; also stored into
                                 // [[set+0xb0]+0x78]
            // plus: plain RaceDirector instance (0x4d7d8, alloc 0x90 @0x6f244),
            // Vt2 (0x6f11c), 0x6e9d0/0x6ded4/0x620a0/0x6e5e0 members
            // (0xD0 total)
    };
}
