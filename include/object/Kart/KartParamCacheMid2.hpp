#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheMid2 — PROVISIONAL vtable-anchored name (vptr 0x12b4518,
    // GOT cell 0x130dc10, n=13). SECOND mid base of the cluster (used as base ctor by 0x12b3130,
    // 0x12bb800, 0x12bd030, 0x12bd6f8). Ctor calls the KartParamCache base
    // (0x7100669954), builds a 0x68-byte member at 0x48 (ctor 0x710061cc48)
    // and another member at 0xb0, fields 0x50/0x58/0xa0/0xa8/0xb8/0x1c8.
    class KartParamCacheMid2 : public KartParamCache
    {
    public:
        uint8_t mPad40[0x10];   // 0x40 — unproven gap
        uint64_t mField50;      // 0x50 — ctor-written
        uint32_t mField58;      // 0x58 — ctor-written
        uint8_t mPad5c[0x44];   // 0x5c — unproven gap
        uint32_t mFielda0;      // 0xa0 — ctor-written
        uint8_t mPada4[0x4];    // 0xa4 — unproven gap
        uint64_t mZeroa8;       // 0xa8 — ctor zero
        uint64_t mFieldb0;      // 0xb0 — ctor-written
        uint64_t mFieldb8;      // 0xb8 — ctor-written
        uint8_t mPadc0[0x108];  // 0xc0 — unproven gap
        uint64_t mZero1c8;      // 0x1c8 — ctor zero
                               // ctor 0x7100668d40 writes documented in the wip notes)
    };
}
