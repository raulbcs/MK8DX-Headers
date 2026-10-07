#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheVolumeMask — named from ctor string evidence: ctor string tag 'aglvolm' + param volume_mask (0xf1aa11-0xf01d00) (was PROVISIONAL vtable-anchored KartParamCacheVt2d18) (vptr 0x12f2d18, cell 0x1315208, n=14, site 0xa9cad8, ctor 0xa9ca94).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheVolumeMask : public KartParamCache
    {
    public:
        uint8_t mPad40[0x190];   // 0x40 — unproven gap
        uint64_t mField1d0;      // 0x1d0 — ctor-written
        uint8_t mPad1d8[0x40];   // 0x1d8 — unproven gap
        uint32_t mField218;      // 0x218 — ctor-written
        uint8_t mPad21c;         // 0x21c — ctor zero
        uint8_t mField21d;       // 0x21d — ctor-written
        uint8_t mPad21e[0x2];    // 0x21e — unproven gap
        uint32_t mZero220;       // 0x220 — ctor zero
        uint8_t mPad224[0x4];    // 0x224 — unproven gap
        uint64_t mZero228;       // 0x228 — ctor zero
        uint32_t mZero230;       // 0x230 — ctor zero
        uint8_t mPad234[0x4];    // 0x234 — unproven gap
        uint64_t mZero238;       // 0x238 — ctor zero
        uint32_t mField240;      // 0x240 — ctor-written
        uint32_t mZero244;       // 0x244 — ctor zero
        uint8_t mPad248;         // 0x248 — ctor zero
        uint8_t mPad249[0x3];    // 0x249 — unproven gap
        uint32_t mZero24c;       // 0x24c — ctor zero
        uint8_t mField24d;       // 0x24d — ctor-written
        uint16_t mPad24e;        // 0x24e — ctor zero
        uint8_t mPad250[0x238];  // 0x250 — unproven gap
        uint64_t mField488;      // 0x488 — ctor-written
        uint8_t mPad490[0x28];   // 0x490 — unproven gap
        uint64_t mField4b8;      // 0x4b8 — ctor-written
        uint8_t mPad4c0[0x18];   // 0x4c0 — unproven gap
        uint64_t mField4d8;      // 0x4d8 — ctor-written
        uint8_t mPad4e0[0x18];   // 0x4e0 — unproven gap
        uint64_t mField4f8;      // 0x4f8 — ctor-written
        uint8_t mPad500[0x18];   // 0x500 — unproven gap
        uint64_t mField518;      // 0x518 — ctor-written
        uint8_t mPad520[0x18];   // 0x520 — unproven gap
        uint32_t mZero538;       // 0x538 — ctor zero
        uint8_t mPad53c[0x4];    // 0x53c — unproven gap
        uint64_t mZero540;       // 0x540 — ctor zero
    };
}
