#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object
{
    // KartParamCacheMultiFilterColorDrift — named from ctor string evidence: ctor name string 'MultiFilterColorDrift' + params drift_r/g/b (0xef9e5b-0xef9e8b) (was address-anchored KartParamCacheVt37d8) (vptr 0x12b37d8,
    // GOT cell 0x130db30). Derived KartParamCacheMid variant: ctor 0x7100660cc4
    // (calls the mid ctor with w1=5) built by the factory 0x710065efbc;
    // size 0x170 (factory alloc). Ctor 0x7100660cc4: after the mid ctor, three
    // 0x20 channel-pair members at 0x110/0x130/0x150 (KartParamCacheChanBase
    // ctor 0x7100662f30 + two w32 fields written by 0x7100662f70 at
    // 0x128+0x12c / 0x148+0x14c / 0x168+0x16c).
    class KartParamCacheMultiFilterColorDrift : public KartParamCacheMid
    {
    public:
        char mChanPair110[0x60]; // 0x110 — three 0x20 channel pairs (ChanBase ctor 0x7100662f30), each with two w32 tail fields (0x128/0x12c, 0x148/0x14c, 0x168/0x16c)
        // (0x170 total)
    };
}

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
