#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheProjShadow — named from ctor string evidence: ctor string tag 'aglprojsdw' + params bias_scale/anim_swing_cyc_x/scroll anim (0xf1dc97-0xf1ddb4) (was PROVISIONAL vtable-anchored KartParamCacheVt3f60) (vptr 0x12f3f60, cell 0x1315460, n=13, site 0xade4d0, ctor 0xade480).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheProjShadow : public KartParamCache
    {
    public:
        uint8_t mPad40[0x344];  // 0x40 — unproven gap
        uint16_t mField384;     // 0x384 — ctor-written
        uint8_t mField386;      // 0x386 — ctor-written
        uint8_t mField387;      // 0x387 — ctor-written
        uint8_t mField388;      // 0x388 — ctor-written
        uint8_t mField389;      // 0x389 — ctor-written
        uint8_t mPad38a[0x36];  // 0x38a — unproven gap
        uint32_t mField3c0;     // 0x3c0 — ctor-written
        uint32_t mZero3c4;      // 0x3c4 — ctor zero
        uint64_t mField3c8;     // 0x3c8 — ctor-written
        uint32_t mZero3d0;      // 0x3d0 — ctor zero
        uint8_t mPad3d4[0x14];  // 0x3d4 — unproven gap
        uint64_t mField3e8;     // 0x3e8 — ctor-written
        uint8_t mPad3f0[0x28];  // 0x3f0 — unproven gap
        void* mSelf418;         // 0x418 — ctor stores `this`
        uint64_t mField420;     // 0x420 — ctor-written
        uint8_t mPad428[0x10];  // 0x428 — unproven gap
        uint32_t mField438;     // 0x438 — ctor-written
        uint32_t mField43c;     // 0x43c — ctor-written
        uint64_t mField440;     // 0x440 — ctor-written
        uint8_t mPad448[0x10];  // 0x448 — unproven gap
        uint32_t mField458;     // 0x458 — ctor-written
        uint32_t mField45c;     // 0x45c — ctor-written
        uint64_t mField460;     // 0x460 — ctor-written
        uint8_t mPad468[0x10];  // 0x468 — unproven gap
        uint32_t mZero478;      // 0x478 — ctor zero
        uint8_t mPad47c[0x4];   // 0x47c — unproven gap
        uint64_t mField480;     // 0x480 — ctor-written
        uint8_t mPad488[0x10];  // 0x488 — unproven gap
        uint32_t mZero498;      // 0x498 — ctor zero
        uint8_t mPad49c[0x4];   // 0x49c — unproven gap
        uint64_t mField4a0;     // 0x4a0 — ctor-written
        uint8_t mPad4a8[0x10];  // 0x4a8 — unproven gap
        uint32_t mField4b8;     // 0x4b8 — ctor-written
        uint32_t mField4bc;     // 0x4bc — ctor-written
        uint64_t mField4c0;     // 0x4c0 — ctor-written
        uint8_t mPad4c8[0x10];  // 0x4c8 — unproven gap
        uint32_t mField4d8;     // 0x4d8 — ctor-written
        uint32_t mField4dc;     // 0x4dc — ctor-written
        uint64_t mField4e0;     // 0x4e0 — ctor-written
        uint8_t mPad4e8[0x10];  // 0x4e8 — unproven gap
        uint32_t mZero4f8;      // 0x4f8 — ctor zero
        uint8_t mPad4fc[0x4];   // 0x4fc — unproven gap
        uint64_t mField500;     // 0x500 — ctor-written
        uint8_t mPad508[0x10];  // 0x508 — unproven gap
        uint32_t mZero518;      // 0x518 — ctor zero
        uint8_t mPad51c[0x4];   // 0x51c — unproven gap
        uint64_t mField520;     // 0x520 — ctor-written
        uint8_t mPad528[0x10];  // 0x528 — unproven gap
        uint8_t mPad538;        // 0x538 — ctor zero
        uint8_t mPad539[0x7];   // 0x539 — unproven gap
        uint8_t mPad540;        // 0x540 — ctor zero
    };
}
