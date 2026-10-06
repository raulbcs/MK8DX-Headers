#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL vtable-anchored name. Root-derived, 97 slots.
    // Vtable .data 0x11ad5a8 (GOT cell 0x12fb030), ctor 0x71000fcdc, size 0x348
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyVt97 : public KartPhysicsBody
    {
    public:
        char mOwn328[0x20];   // 0x328 — own-field region (map pending)
    };
}
