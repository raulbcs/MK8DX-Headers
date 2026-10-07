#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object
{
    // KartParamCacheVtbb800 — address-anchored name (vptr 0x12bb800,
    // GOT cell 0x130e538, n=n/a). Mid2-derived variant: member at 0x1d0 (ctor 0x710066a2a4), secondary
    // vptr cell 0x12fada0 at 0x208, flags 0x200/0x218, writes to 0x328.
    // Extent 0x330.
    class KartParamCacheVtbb800 : public KartParamCacheMid2
    {
    public:
                               // additional writes by ctor 0x71006fe734
    };
}

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
