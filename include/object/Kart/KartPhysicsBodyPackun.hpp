#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Slot names carry ItemPackunS evidence (Pakkun/plant body). 96 slots.
    // Vtable .data 0x11b1770 (GOT cell 0x12fbde0), ctor 0x71003940c, size 0x340
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyPackun : public KartPhysicsBody
    {
    public:
        char mOwn328[0x18];   // 0x328 — own-field region (map pending)
    };
}
