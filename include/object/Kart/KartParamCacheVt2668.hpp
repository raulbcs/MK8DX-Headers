#pragma once

#include <cstdint>

namespace object
{
    // KartParamCacheVt2668 — PROVISIONAL vtable-anchored name (vptr 0x12b2668,
    // GOT cell 0x130d980). Cluster variant (ctor 0x710064a708): first calls ctor 0x710064822c
    // (KartParamCacheVt2358 class, extent 0x38) on this, then the
    // KartParamCache base ctor, member at 0xd8, KartParamCacheNode member
    // at 0x128, zeros 0x120/0x158/0x160. Extent 0x168. Exact base chain
    // (Vt2358 vs member) map pending.
    class KartParamCacheVt2668
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[0x30];   // 0x08   // 0x08
        char mOwn38[0x130];    // 0x38 — own-field region (map pending)
        // (0x168 total)
    };
}
