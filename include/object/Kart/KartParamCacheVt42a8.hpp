#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheVt42a8 — PROVISIONAL vtable-anchored name (vptr 0x12f42a8, cell 0x13154b0, n=13, site 0xaed278, ctor 0xaed234).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheVt42a8 : public KartParamCache
    {
    public:
        uint8_t mPad40[0x190];   // 0x40 — unproven gap
        uint32_t mZero1d0;       // 0x1d0 — ctor zero
        uint8_t mPad1d4[0x4];    // 0x1d4 — unproven gap
        uint64_t mZero1d8;       // 0x1d8 — ctor zero
        uint32_t mZero1e0;       // 0x1e0 — ctor zero
        uint8_t mPad1e4[0x23c];  // 0x1e4 — unproven gap
        uint64_t mField420;      // 0x420 — ctor-written
        uint8_t mPad428[0x28];   // 0x428 — unproven gap
        uint64_t mField450;      // 0x450 — ctor-written
        uint8_t mPad458[0x10];   // 0x458 — unproven gap
        uint8_t mField468;       // 0x468 — ctor-written
        uint8_t mPad469[0x7];    // 0x469 — unproven gap
        uint64_t mField470;      // 0x470 — ctor-written
        uint8_t mPad478[0x10];   // 0x478 — unproven gap
        uint32_t mZero488;       // 0x488 — ctor zero
    };
}
