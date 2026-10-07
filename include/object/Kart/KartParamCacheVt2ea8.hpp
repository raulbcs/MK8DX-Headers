#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheVt2ea8 — PROVISIONAL vtable-anchored name (vptr 0x12f2ea8, cell 0x1315240, n=13, site 0xaa3cac, ctor 0xaa3c6c).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheVt2ea8 : public KartParamCache
    {
    public:
        uint8_t mPad40[0x190];   // 0x40 — unproven gap
        uint32_t mZero1d0;       // 0x1d0 — ctor zero
        uint8_t mPad1d4[0x4];    // 0x1d4 — unproven gap
        uint64_t mZero1d8;       // 0x1d8 — ctor zero
        uint8_t mPad1e0[0xad0];  // 0x1e0 — unproven gap
        uint64_t mZerocb0;       // 0xcb0 — ctor zero
        uint32_t mZerocb8;       // 0xcb8 — ctor zero
        uint8_t mPadcbc[0x4];    // 0xcbc — unproven gap
        uint64_t mZerocc0;       // 0xcc0 — ctor zero
        uint32_t mZerocc8;       // 0xcc8 — ctor zero
        uint8_t mPadccc[0x8];    // 0xccc — unproven gap
        uint32_t mFieldcd4;      // 0xcd4 — ctor-written
        uint64_t mFieldcd8;      // 0xcd8 — ctor-written
        uint8_t mPadce0[0x238];  // 0xce0 — unproven gap
        uint8_t mPadf18;         // 0xf18 — ctor zero
    };
}
