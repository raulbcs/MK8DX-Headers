#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace gear
{
    // RaceDirector-family director that overrides prepare/enter (slots 0x20/
    // 0x28) while keeping the shared calc/render/exit/isDirector/accept
    // hooks — missed by the strict family signature, caught by the loose
    // scan. Vtable .data 0x11b93f8 (GOT cell 0x12fcf40), ctor 0x7100107c3c,
    // 0x228 bytes (allocation 0x398a9c: operator new[](0x228, nothrow)),
    // spawned by the race job manager like RaceDirectorVt8 (count +0x1c0,
    // list slot +0x250, owner back-ptrs +0x18/+0x28/+0x30).
    //
    // Ctor field writes: 0x38 = 0 (u32); 0x40/0x48/0x68 = 0; channel cells
    // 0x50/0x58 (GOT 0x12fcf48/0x12fcf50 +0x10); memset(this+0x70, 0, 0x14a)
    // → 0x70..0x1ba; pointer set at 0x78; node array init (0x60b930, 0x10
    // bytes each) at 0x88..0x148; zeros at 0x1bc/0x1c4; KartDirector-family
    // member ctor 0x628628 on the sub-object at 0x1d0; zeros 0x210/0x218;
    // byte 0x220 = 0.
    class RaceDirectorVt9 : public Actor
    {
    public:
        uint32_t mField38;     // 0x38 — zeroed on ctor
        uint8_t mPad3c[4];     // 0x3c
        uint64_t mField40;     // 0x40 — zeroed on ctor
        void* mChan48;         // 0x48 — zeroed on ctor
        void* mChan50;         // 0x50 — cell 0x12fcf48 (vptr, +0x10)
        void* mChan58;         // 0x58 — cell 0x12fcf50
        uint64_t mField60;     // 0x60 — zeroed on ctor
        uint64_t mField68;     // 0x68 — zeroed on ctor
        void* mField70;        // 0x70 — memset region start; ctor sets it
        void* mField78;        // 0x78 — owned node set by the ctor
        uint8_t mPad80[8];     // 0x80

        struct Node { uint64_t a, b; };
        Node mNodes[12];       // 0x88 — node array, 0x10 bytes each (init 0x60b930)

        uint8_t mPad148[8];    // 0x148
        char mPad150[0x6c];    // 0x150 — memset tail (to 0x1bc)
        uint32_t mField1bc;    // 0x1bc — zeroed on ctor (str = 32-bit)
        uint8_t mPad1c0[4];    // 0x1c0
        uint32_t mField1c4;    // 0x1c4 — zeroed on ctor
        uint8_t mPad1c8[4];    // 0x1c8
        uint8_t mPad1cc[4];    // 0x1cc
        char mSub1d0[0x40];    // 0x1d0 — member sub-object (ctor 0x628628)
        uint64_t mField210;    // 0x210 — zeroed on ctor
        uint64_t mField218;    // 0x218 — zeroed on ctor
        uint8_t mField220;     // 0x220 — zeroed on ctor
        uint8_t mPad221[7];    // 0x221
    };
}
