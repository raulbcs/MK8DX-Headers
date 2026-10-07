#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Slot names carry ItemKillerS evidence (bullet bill body). 96 slots.
    // Vtable .data 0x11afcb0 (GOT cell 0x12fb678), ctor 0x7100029e10, size 0x340
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4);
    class KartPhysicsBodyKiller : public KartPhysicsBody
    {
    public:
        uint32_t mField328;    // 0x328 — ctor-written
        uint8_t mPad32c[0x4];  // 0x32c — unproven gap
        uint64_t mField330;    // 0x330 — ctor-written
        uint8_t mPad338;       // 0x338 — ctor zero
    };
}
