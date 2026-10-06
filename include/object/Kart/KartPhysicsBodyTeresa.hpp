#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Slot names carry TS_ItemTeresa evidence (Boo body). 96 slots.
    // Vtable .data 0x11aeac0 (GOT cell 0x12fb490), ctor 0x710023aec, size 0x348
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyTeresa : public KartPhysicsBody
    {
    public:
        char mOwn328[0x20];   // 0x328 — own-field region (map pending)
    };
}
