#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Slot names carry ItemKillerS evidence (bullet bill body). 96 slots.
    // Vtable .data 0x11afcb0 (GOT cell 0x12fba90), ctor 0x710029e10, size 0x340
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyKiller : public KartPhysicsBody
    {
    public:
        char mOwn328[0x18];   // 0x328 — own-field region (map pending)
    };
}
