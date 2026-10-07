#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheVt1d08 — PROVISIONAL vtable-anchored name (vptr 0x12b1d08,
    // GOT cell 0x130d858). Mid2-derived variant (ctor 0x710063c87c calls the Mid2 overload
    // 0x7100668fc4): float constants 2.0f/-1.0f/3.0f/0.0906f at 0x1d8-0x1f4,
    // u32 at 0x204. Extent 0x208.
    class KartParamCacheVt1d08 : public KartParamCacheMid2
    {
    public:
        // (0x208 total)
    };
}
