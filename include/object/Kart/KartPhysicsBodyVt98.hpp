#pragma once

#include "KartPhysicsBody.hpp"

namespace object
{
    // Address-anchored name ("Vt98"). Rigid body whose head
    // slots carry RigidVtableSwapInit_71000229f4 / RigidVt_0x18_7100022a2c
    // (a vtable-swap-init body). Vtable .data 0x11ae6b0 (GOT cell
    // 0x12fb3d8), ctor 0x710020520 — calls the root ctor 0x116a4 directly.
    // Size 0x450 (allocation 0x450 at 0x238a8, ctor call 0x238c8).
    class KartPhysicsBodyVt98 : public KartPhysicsBody
    {
    public:
        uint8_t mPad328[0x4];   // 0x328 — unproven gap
        uint32_t mZero32c;      // 0x32c — ctor zero
        uint64_t mField330;     // 0x330 — ctor-written
        uint32_t mField334;     // 0x334 — ctor-written
        uint32_t mField338;     // 0x338 — ctor-written
        uint32_t mField33c;     // 0x33c — ctor-written
        uint64_t mField340;     // 0x340 — ctor-written
        uint32_t mField344;     // 0x344 — ctor-written
        uint32_t mField348;     // 0x348 — ctor-written
        uint32_t mField34c;     // 0x34c — ctor-written
        uint32_t mField350;     // 0x350 — ctor-written
        uint32_t mField354;     // 0x354 — ctor-written
        uint32_t mField358;     // 0x358 — ctor-written
        uint32_t mField35c;     // 0x35c — ctor-written
        uint64_t mZero360;      // 0x360 — ctor zero
        uint32_t mField364;     // 0x364 — ctor-written
        uint64_t mZero368;      // 0x368 — ctor zero
        uint32_t mZero370;      // 0x370 — ctor zero
        uint32_t mField374;     // 0x374 — ctor-written
        uint32_t mField378;     // 0x378 — ctor-written
        uint32_t mField37c;     // 0x37c — ctor-written
        uint32_t mField380;     // 0x380 — ctor-written
        uint32_t mField384;     // 0x384 — ctor-written
        uint32_t mField388;     // 0x388 — ctor-written
        uint32_t mField38c;     // 0x38c — ctor-written
        uint32_t mField390;     // 0x390 — ctor-written
        uint32_t mField394;     // 0x394 — ctor-written
        uint32_t mField398;     // 0x398 — ctor-written
        uint32_t mField39c;     // 0x39c — ctor-written
        uint32_t mField3a0;     // 0x3a0 — ctor-written
        uint32_t mField3a4;     // 0x3a4 — ctor-written
        uint32_t mField3a8;     // 0x3a8 — ctor-written
        uint8_t mPad3ac[0x8];   // 0x3ac — unproven gap
        uint32_t mZero3b4;      // 0x3b4 — ctor zero
        uint32_t mField3b8;     // 0x3b8 — ctor-written
        uint32_t mField3bc;     // 0x3bc — ctor-written
        uint32_t mField3c0;     // 0x3c0 — ctor-written
        uint32_t mField3c4;     // 0x3c4 — ctor-written
        uint32_t mField3c8;     // 0x3c8 — ctor-written
        uint32_t mField3cc;     // 0x3cc — ctor-written
        uint32_t mField3d0;     // 0x3d0 — ctor-written
        uint32_t mField3d4;     // 0x3d4 — ctor-written
        uint32_t mField3d8;     // 0x3d8 — ctor-written
        uint32_t mField3dc;     // 0x3dc — ctor-written
        uint32_t mField3e0;     // 0x3e0 — ctor-written
        uint32_t mField3e4;     // 0x3e4 — ctor-written
        uint32_t mField3e8;     // 0x3e8 — ctor-written
        uint32_t mField3ec;     // 0x3ec — ctor-written
        uint32_t mField3f0;     // 0x3f0 — ctor-written
        uint32_t mField3f4;     // 0x3f4 — ctor-written
        uint32_t mField3f8;     // 0x3f8 — ctor-written
        uint32_t mField3fc;     // 0x3fc — ctor-written
        uint32_t mField400;     // 0x400 — ctor-written
        uint32_t mField404;     // 0x404 — ctor-written
        uint32_t mField408;     // 0x408 — ctor-written
        uint32_t mZero40c;      // 0x40c — ctor zero
        uint32_t mZero410;      // 0x410 — ctor zero
        uint32_t mZero414;      // 0x414 — ctor zero
        uint8_t mPad418;        // 0x418 — ctor zero
        uint8_t mPad419[0x17];  // 0x419 — unproven gap
        uint32_t mField430;     // 0x430 — ctor-written
        uint8_t mPad434[0x4];   // 0x434 — unproven gap
        uint64_t mField438;     // 0x438 — ctor-written
        uint32_t mField440;     // 0x440 — ctor-written
        uint8_t mPad444[0x4];   // 0x444 — unproven gap
        uint64_t mField448;     // 0x448 — ctor-written
    };
}

// Naming closure: per item/kart physics-body variant; no distinguishing ctor strings, and the body's semantic identity requires the combo dictionary. Address-anchored name retained.
