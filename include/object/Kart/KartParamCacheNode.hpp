#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheNodeBase.hpp"

namespace object
{
    // KartParamCacheNode — PROVISIONAL vtable-anchored name (vptr 0x12b26b0,
    // GOT cell 0x130d988). The linked-node secondary base embedded at 0x68 (KartParamCacheMid),
    // 0x1d0 (Vt30a8, Vtbd6f8) and 0x128 (Vt2668); embedders pad it to
    // 0x28-0x30 with their own fields.
    class KartParamCacheNode : public KartParamCacheNodeBase
    {
    public:
        // (0x20 total — embedders pad to 0x28/0x30)
    };
}
