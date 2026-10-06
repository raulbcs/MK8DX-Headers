#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object
{
    // KartParamCacheVt3868 — PROVISIONAL vtable-anchored name (vptr 0x12b3868,
    // GOT cell 0x130db10). Derived KartParamCacheMid variant built by the
    // factory 0x710065efbc (case w1=6, inline extension of the mid ctor);
    // size 0x150 (factory alloc). The factory also copies a u32 pair from
    // the global [0x12fbb00] into 0x128/0x12c (this variant only).
    class KartParamCacheVt3868 : public KartParamCacheMid
    {
    public:
        char mChan110[0x18];   // 0x110 — channel-pair member (ctor pair
                               // 0x7100662f30/0x7100662f70, cell 0x130d9b8)
        uint32_t mField128;    // 0x128 — factory zero
        uint8_t pad12c[4];     // 0x12c
        char mChan130[0x20];   // 0x130 — channel-pair member (names
                               // 0xef9d06/0xef9d13)

        // (0x150 total)
    };
}
