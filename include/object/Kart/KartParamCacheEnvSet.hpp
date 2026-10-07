#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheEnvSet — named from ctor string tag 'aglenvset' (0xef9116; was address-anchored KartParamCacheVt2738) (vptr 0x12b2738,
    // GOT cell 0x130d9a0). Mid2-derived variant (ctor 0x710064bdac calls 0x7100668d40): zeros
    // 0x1d0-0x1f8, then init 0x7100689f00 with a name pair (rodata
    // 0xef9120). Extent 0x200.
    class KartParamCacheEnvSet : public KartParamCacheMid2
    {
    public:
        // (0x200 total)
    };
}

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
