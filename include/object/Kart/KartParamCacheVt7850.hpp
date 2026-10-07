#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheVt7850 — address-anchored name (vptr 0x12b7850,
    // GOT cell 0x130e240). Cluster variant whose ctor (0x71006ae398 region) writes flags
    // 0xc0/0x158/0x15b and inits a member via virtual call. Extent 0x160.
    class KartParamCacheVt7850 : public KartParamCache
    {
    public:
        char mOwn40[0x120];    // 40 — own-field region
        // (0x160 total)
    };
}

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
