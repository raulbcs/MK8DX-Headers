#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Slot names carry ItemSHorn evidence (Super Horn body). 96 slots.
    // Vtable .data 0x11b1b70 (GOT cell 0x12fbe60), ctor 0x71003a440, size 0x370
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodySHorn : public KartPhysicsBody
    {
    public:
        char mOwn328[0x48];   // 0x328 — own-field region (map pending)
    };
}
