#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object
{
    // Kart speed calculation runtime, "mini core" variant. Vtable .data
    // 0x124d0e8 (GOT cell 0x1306390 region), ctor 0x710034d2d8, size 0x300
    // (allocation 0x300 at 0x34d1ac). Slot names carry
    // KartCalcSpeed_mini_core_710034b558 evidence.
    class KartCalcSpeedMiniCore : public gear::Actor
    {
    public:
        uint8_t mPad8[0x30];    // 0x8 — unproven gap
        uint64_t mField38;      // 0x38 — ctor-written
        uint8_t mPad40[0xe8];   // 0x40 — unproven gap
        uint64_t mField128;     // 0x128 — ctor-written
        uint8_t mPad130[0xd8];  // 0x130 — unproven gap
        uint64_t mField208;     // 0x208 — ctor-written
        uint8_t mPad210[0x50];  // 0x210 — unproven gap
        uint64_t mField260;     // 0x260 — ctor-written
        uint8_t mField268;      // 0x268 — ctor-written
        uint8_t mPad269;        // 0x269 — ctor zero
        uint8_t mPad26a;        // 0x26a — ctor zero
        uint8_t mField26b;      // 0x26b — ctor-written
        uint32_t mZero26c;      // 0x26c — ctor zero
        void* mSelf270;         // 0x270 — ctor stores `this`
        uint64_t mField278;     // 0x278 — ctor-written
        uint64_t mField280;     // 0x280 — ctor-written
        uint64_t mField288;     // 0x288 — ctor: call result
        uint8_t mPad290;        // 0x290 — ctor zero
        uint8_t mPad291[0x7];   // 0x291 — unproven gap
        uint64_t mField298;     // 0x298 — ctor-written
        uint64_t mZero2a0;      // 0x2a0 — ctor zero
        uint8_t mPad2a8;        // 0x2a8 — ctor zero
        uint8_t mPad2a9[0x7];   // 0x2a9 — unproven gap
        uint32_t mField2b0;     // 0x2b0 — ctor-written
        uint32_t mZero2b4;      // 0x2b4 — ctor zero
        uint32_t mZero2b8;      // 0x2b8 — ctor zero
        uint8_t mPad2bc[0x8];   // 0x2bc — unproven gap
        uint32_t mField2c4;     // 0x2c4 — ctor-written
        uint8_t mField2c8;      // 0x2c8 — ctor-written
        uint8_t mPad2c9[0x1];   // 0x2c9 — unproven gap
        uint8_t mPad2ca;        // 0x2ca — ctor zero
        uint8_t mPad2cb[0x9];   // 0x2cb — unproven gap
        uint32_t mField2d4;     // 0x2d4 — ctor-written
        uint64_t mField2d8;     // 0x2d8 — ctor-written
        uint32_t mField2e0;     // 0x2e0 — ctor-written
        uint8_t mPad2e4[0x8];   // 0x2e4 — unproven gap
        uint32_t mField2ec;     // 0x2ec — ctor-written
        uint64_t mField2f0;     // 0x2f0 — ctor-written
        uint32_t mField2f8;     // 0x2f8 — ctor-written
    };
}
