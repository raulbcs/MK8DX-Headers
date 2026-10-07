#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheVt48f8 — PROVISIONAL vtable-anchored name (vptr 0x12b48f8, cell 0x130dce0, n=13, site 0x67885c, ctor 0x678808).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheVt48f8 : public KartParamCache
    {
    public:
        uint8_t mPad40[0x190];   // 0x40 — unproven gap
        uint32_t mZero1d0;       // 0x1d0 — ctor zero
        uint8_t mPad1d4[0x14];   // 0x1d4 — unproven gap
        uint64_t mZero1e8;       // 0x1e8 — ctor zero
        uint8_t mPad1f0[0x10];   // 0x1f0 — unproven gap
        uint32_t mZero200;       // 0x200 — ctor zero
        uint32_t mField204;      // 0x204 — ctor-written
        uint64_t mZero208;       // 0x208 — ctor zero
        uint32_t mZero210;       // 0x210 — ctor zero
        uint8_t mPad214[0x4];    // 0x214 — unproven gap
        uint64_t mZero218;       // 0x218 — ctor zero
        uint32_t mZero220;       // 0x220 — ctor zero
        uint8_t mPad224[0x34c];  // 0x224 — unproven gap
        uint64_t mZero570;       // 0x570 — ctor zero
        uint32_t mZero578;       // 0x578 — ctor zero
        uint8_t mPad57c[0x4];    // 0x57c — unproven gap
        uint64_t mZero580;       // 0x580 — ctor zero
        uint32_t mZero588;       // 0x588 — ctor zero
        uint8_t mPad58c[0x34c];  // 0x58c — unproven gap
        uint64_t mZero8d8;       // 0x8d8 — ctor zero
        uint32_t mZero8e0;       // 0x8e0 — ctor zero
        uint8_t mPad8e4[0x4];    // 0x8e4 — unproven gap
        uint64_t mZero8e8;       // 0x8e8 — ctor zero
        uint32_t mZero8f0;       // 0x8f0 — ctor zero
    };
}
