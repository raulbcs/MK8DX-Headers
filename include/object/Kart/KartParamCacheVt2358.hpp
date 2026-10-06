#pragma once

#include <cstdint>

namespace object
{
    // KartParamCacheVt2358 — PROVISIONAL vtable-anchored name (vptr 0x12b2358,
    // GOT cell 0x130d948). Small cluster class: ctor 0x710064822c (vptr, zeros 0x8..0x37).
    // Used as the first base call of Vt2668's ctor.
    class KartParamCacheVt2358
    {
    public:
        void* vptr;            // 0x00
        uint64_t mZero08;      // 0x08
        uint64_t mZero10;      // 0x10
        uint64_t mZero18;      // 0x18
        uint32_t mZero20;      // 0x20
        uint32_t mZero24;      // 0x24
        uint64_t mZero28;      // 0x28
        uint64_t mZero30;      // 0x30
        // (0x38 total)
    };
}
