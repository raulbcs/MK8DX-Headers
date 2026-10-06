#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheVt2738 — PROVISIONAL vtable-anchored name (vptr 0x12b2738,
    // GOT cell 0x130d9a0). Mid2-derived variant (ctor 0x710064bdac calls 0x7100668d40): zeros
    // 0x1d0-0x1f8, then init 0x7100689f00 with a name pair (rodata
    // 0xef9120). Extent 0x200.
    class KartParamCacheVt2738 : public KartParamCacheMid2
    {
    public:
        char mOwn1d0[0x30];    // 0x1d0 — own-field region (map pending)
        // (0x200 total)
    };
}
