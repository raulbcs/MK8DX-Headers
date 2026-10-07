#pragma once

#include "KartPhysicsBodyVt96b.hpp"

namespace object
{
    // Slot names carry UseItemCaller evidence. Derives Vt96b (ctor 0x2b444 calls 0x2a7c8).
    // Vtable .data 0x11b03f0 (GOT cell 0x12fbc30), ctor 0x71002b428, size 0x358
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4);
    class KartPhysicsBodyUseItem : public KartPhysicsBodyVt96b
    {
    public:
        uint32_t mField338;    // 0x338 — ctor-written
        uint8_t mPad33c[0x4];  // 0x33c — unproven gap
        uint64_t mField340;    // 0x340 — ctor-written
        uint32_t mField348;    // 0x348 — ctor-written
        uint8_t mPad34c[0x4];  // 0x34c — unproven gap
        uint64_t mField350;    // 0x350 — ctor-written
    };
}
