#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name. 96 slots; two ctor callers.
    // Vtable .data 0x11b0050 (GOT cell 0x12fbb88), ctor 0x71002a7c8, size 0x338
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyVt96b : public KartPhysicsBody
    {
    public:
        char mOwn328[0x10];   // 0x328 — own-field region (map pending)
    };
}
