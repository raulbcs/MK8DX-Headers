#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object
{
    // KartParamCacheVt37d8 — PROVISIONAL vtable-anchored name (vptr 0x12b37d8,
    // GOT cell 0x130db30). Derived KartParamCacheMid variant: ctor 0x7100660cc4
    // (calls the mid ctor with w1=5) built by the factory 0x710065efbc;
    // size 0x170 (factory alloc). Fields beyond the mid extent 0x110 are
    // map pending — declared as padding.
    class KartParamCacheVt37d8 : public KartParamCacheMid
    {
    public:
        char mPad110[0x60];    // 0x110 — own-field region (map pending)
        // (0x170 total)
    };
}
