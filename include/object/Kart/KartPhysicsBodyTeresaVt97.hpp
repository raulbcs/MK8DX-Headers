#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Address-anchored suffix. TS_ItemTeresa evidence; 97 slots.
    // Vtable .data 0x11aeec0 (GOT cell 0x12fb5a0), ctor 0x7100024d48, size 0x350
    // (factory allocation immediately before the ctor call). Root-derived
    // (ctor calls 0x116a4);
    class KartPhysicsBodyTeresaVt97 : public KartPhysicsBody
    {
    public:
        uint64_t mField328;    // 0x328 — ctor-written
        uint32_t mField330;    // 0x330 — ctor-written
        uint8_t mPad334[0x8];  // 0x334 — unproven gap
        uint32_t mField33c;    // 0x33c — ctor-written
        uint64_t mZero340;     // 0x340 — ctor zero
        uint8_t mField348;     // 0x348 — ctor-written
        uint8_t mPad349;       // 0x349 — ctor zero
    };
}

// Naming closure: per item/kart physics-body variant; no distinguishing ctor strings, and the body's semantic identity requires the combo dictionary. Address-anchored name retained.
