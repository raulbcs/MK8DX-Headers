#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object
{
    // KartParamCacheVt3748 — PROVISIONAL vtable-anchored name (vptr 0x12b3748,
    // GOT cell 0x130db28). Derived KartParamCacheMid variant: ctor 0x710066092c
    // (calls the mid ctor with w1=4) built by the factory 0x710065efbc;
    // size 0x1b0 (factory alloc). Ctor 0x710066092c: after the mid ctor, five
    // 0x20 channel-pair members at 0x110..0x190 (KartParamCacheChanBase
    // ctor 0x7100662f30 + w32 field written by 0x7100662f70 at 0x128/0x148/0x168/0x188/0x1a8).
    class KartParamCacheVt3748 : public KartParamCacheMid
    {
    public:
        char mChanPair110[0xa0]; // 0x110 — five 0x20 channel pairs (ChanBase ctor 0x7100662f30), w32 tail fields at 0x128/0x148/0x168/0x188/0x1a8
        // (0x1b0 total)
    };
}
