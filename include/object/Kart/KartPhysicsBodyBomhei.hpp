#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // BomheiBomb (bomb) physics body. Vtable .data 0x11ae100 (GOT cell
    // 0x12fb2d0), ctor 0x71001bfbc — calls the root ctor 0x116a4 directly.
    // Size 0x3e8 (allocation 0x3e8 at 0x1fb18, ctor call 0x1fb2c). Slot 0
    // is PhysicsBodySingletonGetter_710001e258 (a lazily-guarded static
    // singleton accessor).
    class KartPhysicsBodyBomhei : public KartPhysicsBody
    {
    public:
        uint64_t mZero328;      // 0x328 — ctor zero
        uint64_t mZero330;      // 0x330 — ctor zero
        uint64_t mZero338;      // 0x338 — ctor zero
        uint64_t mField340;     // 0x340 — ctor-written
        uint8_t mPad348;        // 0x348 — ctor zero
        uint8_t mPad349[0x7];   // 0x349 — unproven gap
        uint32_t mField350;     // 0x350 — ctor-written
        uint8_t mPad354[0x4];   // 0x354 — unproven gap
        uint64_t mField358;     // 0x358 — ctor-written
        uint32_t mField360;     // 0x360 — ctor-written
        uint8_t mPad364[0x4];   // 0x364 — unproven gap
        uint64_t mField368;     // 0x368 — ctor-written
        uint32_t mField370;     // 0x370 — ctor-written
        uint8_t mPad374[0x4];   // 0x374 — unproven gap
        uint64_t mField378;     // 0x378 — ctor-written
        uint32_t mField380;     // 0x380 — ctor-written
        uint8_t mPad384[0x4];   // 0x384 — unproven gap
        uint64_t mField388;     // 0x388 — ctor-written
        uint64_t mField390;     // 0x390 — ctor-written
        uint8_t mField398;      // 0x398 — ctor-written
        uint8_t mPad399;        // 0x399 — ctor zero
        uint8_t mField39a;      // 0x39a — ctor-written
        uint8_t mField39b;      // 0x39b — ctor-written
        uint32_t mZero39c;      // 0x39c — ctor zero
        void* mSelf3a0;         // 0x3a0 — ctor stores `this`
        uint64_t mField3a8;     // 0x3a8 — ctor-written
        uint64_t mField3b0;     // 0x3b0 — ctor-written
        uint64_t mField3b8;     // 0x3b8 — ctor: call result
        uint64_t mZero3c0;      // 0x3c0 — ctor zero
        uint32_t mZero3c8;      // 0x3c8 — ctor zero
        uint32_t mField3cc;     // 0x3cc — ctor-written
        uint32_t mField3d0;     // 0x3d0 — ctor-written
        uint8_t mPad3d4[0x10];  // 0x3d4 — unproven gap
        uint32_t mField3e4;     // 0x3e4 — ctor-written
    };
}
