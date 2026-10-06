#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL suffix. TS_ItemTeresa evidence; 108 slots.
    // Vtable .data 0x11b2310 (GOT cell 0x12fc270), ctor 0x71003bfe0, size 0x390
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyTeresaVt108 : public KartPhysicsBody
    {
    public:
        char mOwn328[0x68];   // 0x328 — own-field region (map pending)
    };
}
