#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheContainer — PROVISIONAL vtable-anchored name (vptr 0x12bd0a8,
    // GOT cell 0x130e848, n=?). The KartParamCacheContainer of the KartSlotCap note (ctor
    // 0x710071db70): zeros across 0x660..0x8e8. Extent 0x8f0.
    
    class KartParamCacheContainer : public KartParamCacheMid2
    {
    public:
        char mOwn1d0[0x720];   // 0x1d0 — own-field region (Mid2 extent 0x1d0) (map pending;
                               // ctor 0x710071db70 writes documented in the wip notes)
    };
}
