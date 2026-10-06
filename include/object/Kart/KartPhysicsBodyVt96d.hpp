#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name. 96 slots.
    // Vtable .data 0x11b27d0 (GOT cell 0x12fc640), ctor 0x71003e8b4, size 0x348
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyVt96d : public KartPhysicsBody
    {
    public:
        char mOwn328[0x20];   // 0x328 — own-field region (map pending)
    };
}
