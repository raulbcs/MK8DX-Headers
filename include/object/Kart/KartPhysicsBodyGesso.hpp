#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Gesso (ink) physics body. Vtable .data 0x11af7f0 (GOT cell
    // 0x12fb5d0), ctor 0x7100027098 — calls the root ctor 0x116a4 directly.
    // Size 0x4c8 (allocation 0x4c8 at 0x29bcc, ctor call 0x29bec). Slot
    // names carry ItemGesso evidence.
    class KartPhysicsBodyGesso : public KartPhysicsBody
    {
    public:
        uint64_t mZero328;      // 0x328 — ctor zero
        uint64_t mZero330;      // 0x330 — ctor zero
        uint64_t mZero338;      // 0x338 — ctor zero
        uint64_t mZero340;      // 0x340 — ctor zero
        uint64_t mZero348;      // 0x348 — ctor zero
        uint64_t mZero350;      // 0x350 — ctor zero
        uint8_t mPad358[0xbc];  // 0x358 — unproven gap
        uint32_t mField414;     // 0x414 — ctor-written
        uint64_t mField418;     // 0x418 — ctor-written
        uint32_t mField420;     // 0x420 — ctor-written
        uint8_t mPad424[0x4];   // 0x424 — unproven gap
        uint32_t mField428;     // 0x428 — ctor-written
        uint8_t mPad42c[0x4];   // 0x42c — unproven gap
        uint64_t mField430;     // 0x430 — ctor-written
        uint16_t mField438;     // 0x438 — ctor-written
        uint16_t mField43a;     // 0x43a — ctor-written
        uint8_t mPad43c[0x4];   // 0x43c — unproven gap
        uint64_t mField440;     // 0x440 — ctor-written
        uint8_t mField448;      // 0x448 — ctor-written
        uint8_t mPad449;        // 0x449 — ctor zero
        uint8_t mField44a;      // 0x44a — ctor-written
        uint8_t mField44b;      // 0x44b — ctor-written
        uint32_t mZero44c;      // 0x44c — ctor zero
        void* mSelf450;         // 0x450 — ctor stores `this`
        uint64_t mField458;     // 0x458 — ctor-written
        uint64_t mField460;     // 0x460 — ctor-written
        uint64_t mField468;     // 0x468 — ctor: call result
        uint8_t mPad470[0x38];  // 0x470 — unproven gap
        uint32_t mField4a8;     // 0x4a8 — ctor-written
        uint8_t mPad4ac[0x4];   // 0x4ac — unproven gap
        uint64_t mField4b0;     // 0x4b0 — ctor-written
        uint32_t mField4b8;     // 0x4b8 — ctor-written
        uint32_t mField4bc;     // 0x4bc — ctor-written
        uint8_t mPad4c0;        // 0x4c0 — ctor zero
    };
}

        uint8_t mPad4C1[0x7]; // 0x4C1 — unproven gap