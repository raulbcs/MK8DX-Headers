#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Slot names carry TS_ItemTeresa evidence (Boo body). 96 slots.
    // Vtable .data 0x11aeac0 (GOT cell 0x12fb490), ctor 0x7100023aec, size 0x348
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4);
    class KartPhysicsBodyTeresa : public KartPhysicsBody
    {
    public:
        uint32_t mField328;    // 0x328 — ctor-written
        uint8_t mPad32c[0x4];  // 0x32c — unproven gap
        uint64_t mField330;    // 0x330 — ctor-written
        uint64_t mZero338;     // 0x338 — ctor zero
        uint8_t mField340;     // 0x340 — ctor-written
    };
}
