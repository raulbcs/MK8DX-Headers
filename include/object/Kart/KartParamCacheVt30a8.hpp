#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheVt30a8 — PROVISIONAL vtable-anchored name (vptr
    // 0x12b30a8, GOT cell 0x130da78). Largest KartParamCache variant:
    // ctor 0x710064fb3c built by the factory 0x710065efbc (alloc 0x1a30).
    // NOT a KartParamCacheMid derive — it goes straight over the
    // KartParamCache base: embedded member at 0x1d0 (vptr 0x12b26b0, a
    // small cluster vtable — secondary base), recorder channel-pair
    // members from 0x200 on (pair 0x7100662f30/0x7100662f70, names
    // 0xef8f59/0xef8f60, cell 0x130d908), member writes up to 0x300+.
    class KartParamCacheVt30a8 : public KartParamCache
    {
    public:
        char mPad40[0x190];    // 0x40 — own-field region (map pending)
        void* mSecVt1d0;       // 0x1d0 — secondary vptr (0x12b26b0 +0x10)
        char mSub1d8[0x28];    // 0x1d8 — secondary-base member body
        char mChan200[0x20];   // 0x200 — channel-pair member
        char mPad220[0x1810];  // 0x220 — map pending (ctor writes to 0x300+)
        // (0x1a30 total)
    };
}
