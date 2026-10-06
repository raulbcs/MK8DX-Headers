#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheVtbd6f8 — PROVISIONAL vtable-anchored name (vptr 0x12bd6f8,
    // GOT cell 0x130e8a8). Mid2-derived variant: ctor builds a member (0x710066a2a4) and
    // writes up to 0x288. Extent 0x290. Built in place (no alloc site).
    class KartParamCacheVtbd6f8 : public KartParamCacheMid2
    {
    public:
        char mOwn1d0[0xc0];    // 1d0 — own-field region (map pending)
        // (0x290 total)
    };
}
