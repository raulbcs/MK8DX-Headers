#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheVtbd030 — PROVISIONAL vtable-anchored name (vptr 0x12bd030,
    // GOT cell 0x130e840, n=?). Mid2-derived variant: ctor zeroes 0x1d0/0x1d8 and writes to 0x330.
    // Extent 0x338.
    class KartParamCacheVtbd030 : public KartParamCacheMid2
    {
    public:
        char mOwn1d0[0x168];    // 0x1d0 — own-field region (Mid2 extent 0x1d0) (map pending;
                               // ctor 0x710071d134 writes documented in the wip notes)
    };
}
