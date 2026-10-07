#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid.hpp"

namespace object
{
    // KartParamCacheMultiFilterBlur — named from ctor string evidence: ctor name string 'MultiFilterBlur' + params blur_type/blur_num/gaussian_kernel (0xef9d6d-0xef9dd5) (was PROVISIONAL vtable-anchored KartParamCacheVt3628) (vptr 0x12b3628,
    // GOT cell 0x130db20). Derived KartParamCacheMid variant: ctor 0x710065ffec
    // (calls the mid ctor with w1=2) built by the factory 0x710065efbc;
    // size 0x170 (factory alloc). Ctor 0x710065ffec: after the mid ctor, three
    // 0x20 channel-pair members at 0x110/0x130/0x150 (KartParamCacheChanBase
    // ctor 0x7100662f30 + w32 field written by 0x7100662f70 at 0x128/0x148/0x168).
    class KartParamCacheMultiFilterBlur : public KartParamCacheMid
    {
    public:
        char mChanPair110[0x60]; // 0x110 — three 0x20 channel pairs (ChanBase ctor 0x7100662f30), w32 tail fields at 0x128/0x148/0x168
        // (0x170 total)
    };
}
