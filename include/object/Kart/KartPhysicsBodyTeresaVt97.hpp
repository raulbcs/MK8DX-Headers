#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // PROVISIONAL suffix. TS_ItemTeresa evidence; 97 slots.
    // Vtable .data 0x11aeec0 (GOT cell 0x12fb5a0), ctor 0x710024d48, size 0x350
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyTeresaVt97 : public KartPhysicsBody
    {
    public:
        char mOwn328[0x28];   // 0x328 — own-field region (map pending)
    };
}
