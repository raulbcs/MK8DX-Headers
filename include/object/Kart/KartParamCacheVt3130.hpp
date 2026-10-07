#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheVt3130 — PROVISIONAL vtable-anchored name (vptr 0x12b3130,
    // GOT cell 0x130da98, n=13). Mid2-derived variant: ctor memsets, member 0x710066a2a4, then a
    // table of u32 entries at 0x460..0x580 and pointers 0x588/0x590,
    // zeros to 0x5e0. Extent 0x5e8.
    class KartParamCacheVt3130 : public KartParamCacheMid2
    {
    public:
                               // additional writes by ctor 0x7100651ae4
    };
}
