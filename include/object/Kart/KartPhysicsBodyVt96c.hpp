#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name. 96 slots.
    // Vtable .data 0x11b1f70 (GOT cell 0x12fc050), ctor 0x71003b5cc, size 0x338
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyVt96c : public KartPhysicsBody
    {
    public:
        char mOwn328[0x10];   // 0x328 — own-field region (map pending)
    };
}
