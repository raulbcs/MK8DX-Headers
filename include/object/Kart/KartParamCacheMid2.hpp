#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheMid2 — PROVISIONAL vtable-anchored name (vptr 0x12b4518,
    // GOT cell 0x130dc10, n=13). SECOND mid base of the cluster (used as base ctor by 0x12b3130,
    // 0x12bb800, 0x12bd030, 0x12bd6f8). Ctor calls the KartParamCache base
    // (0x7100669954), builds a 0x68-byte member at 0x48 (ctor 0x710061cc48)
    // and another member at 0xb0, fields 0x50/0x58/0xa0/0xa8/0xb8/0x1c8.
    class KartParamCacheMid2 : public KartParamCache
    {
    public:
        char mOwn40[0x190];    // 0x40 — own-field region (map pending;
                               // ctor 0x7100668d40 writes documented in the wip notes)
    };
}
