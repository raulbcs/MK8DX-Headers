#pragma once

#include "KartPhysicsBodyVt96b.hpp"

namespace object
{
    // Slot names carry UseItemCaller evidence. Derives Vt96b (ctor 0x2b444 calls 0x2a7c8).
    // Vtable .data 0x11b03f0 (GOT cell 0x12fbc30), ctor 0x71002b428, size 0x358
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4); own-field map pending.
    class KartPhysicsBodyUseItem : public KartPhysicsBodyVt96b
    {
    public:
        char mOwn338[0x20];    // 0x338 — own-field region (map pending)
    };
}
