#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Slot names carry ItemSHorn evidence (Super Horn body). 96 slots.
    // Vtable .data 0x11b1b70 (GOT cell 0x12fbe60), ctor 0x71003a440, size 0x370
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4);
    class KartPhysicsBodySHorn : public KartPhysicsBody
    {
    public:
        uint32_t mField328;    // 0x328 — ctor-written
        uint8_t mPad32c[0x4];  // 0x32c — unproven gap
        uint64_t mField330;    // 0x330 — ctor-written
        uint64_t mField338;    // 0x338 — ctor-written
        uint8_t mPad340;       // 0x340 — ctor zero
        uint8_t mPad341[0x3];  // 0x341 — unproven gap
        uint32_t mZero344;     // 0x344 — ctor zero
        uint64_t mZero348;     // 0x348 — ctor zero
        uint64_t mField350;    // 0x350 — ctor-written
        uint32_t mField358;    // 0x358 — ctor-written
        uint8_t mPad35c[0x8];  // 0x35c — unproven gap
        uint32_t mField364;    // 0x364 — ctor-written
        uint32_t mZero368;     // 0x368 — ctor zero
        uint8_t mPad36c;       // 0x36c — ctor zero
        uint8_t mField36d;     // 0x36d — ctor-written
    };
}
