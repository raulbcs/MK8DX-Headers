#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Intermediate physics-body base between the root and the item bodies.
    // Vtable .data 0x11b13a8 (GOT cell 0x12fb8c0), ctor 0x71003703c — calls
    // the root ctor 0x116a4 then writes its own fields at 0x328..0x390.
    // Size 0x390: the Koura body (derived) starts its own fields at 0x390.
    class KartPhysicsBodyMid : public KartPhysicsBody
    {
    public:
        uint32_t mField328;    // 0x328 — zeroed on ctor
        char mPad32c[4];       // 0x32c
        uint64_t mField330;    // 0x330 — zeroed on ctor
        char mPad338[0x30];    // 0x338 — untouched by the ctor head
        uint32_t mField368;    // 0x368 — zeroed on ctor
        char mPad36c[4];       // 0x36c
        uint64_t mField370;    // 0x370 — zeroed on ctor
        char mPad378[8];       // 0x378
        uint32_t mField380;    // 0x380 — zeroed on ctor
        char mPad384[4];       // 0x384
        uint64_t mField388;    // 0x388 — zeroed on ctor
    };
}
