#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name. 96 slots.
    // Vtable .data 0x11af298 (GOT cell 0x12fb8d0), ctor 0x710025a4c, size 0x340
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyVt96a : public KartPhysicsBody
    {
    public:
        char mOwn328[0x18];   // 0x328 — own-field region (map pending)
    };
}
