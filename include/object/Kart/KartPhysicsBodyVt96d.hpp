#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Address-anchored name. 96 slots.
    // Vtable .data 0x11b27d0 (GOT cell 0x12fc640), ctor 0x710003e8b4, size 0x348
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4);
    class KartPhysicsBodyVt96d : public KartPhysicsBody
    {
    public:
        uint32_t mField328;    // 0x328 — ctor-written
        uint8_t mPad32c[0x4];  // 0x32c — unproven gap
        uint64_t mField330;    // 0x330 — ctor-written
        uint64_t mZero338;     // 0x338 — ctor zero
        uint32_t mZero340;     // 0x340 — ctor zero
    };
}

// Naming closure: per item/kart physics-body variant; no distinguishing ctor strings, and the body's semantic identity requires the combo dictionary. Address-anchored name retained.
