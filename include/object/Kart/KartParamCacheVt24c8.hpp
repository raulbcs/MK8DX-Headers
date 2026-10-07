#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheVt24c8 — address-anchored name (vptr
    // 0x12b24c8, GOT cell 0x130d960, n=9). Derived KartParamCache variant
    // built in ARRAYS by the factory at 0x7100648b0c-0x648d3c: element
    // stride 0x58, each element runs the KartParamCache ctor 0x7100669954
    // (vptr 0x12b1c30) and then overwrites the vptr with this one and
    // fills 0x48/0x50 (u32 zero, ptr zero). Owned by a parent that stores
    // the array at +0x460/+0x468 (count/ptr) — factory context reads
    // [x28+0x210] to size a follow-up table. Same pattern siblings:
    // 0x12b2738 (cell 0x130d9a0), 0x12b27b0 (0x130d9a8), 0x12b2668
    // (0x130d980), 0x12b1d08 (0x130d858).
    class KartParamCacheVt24c8 : public KartParamCache
    {
    public:
        uint8_t pad40[8];      // 0x40 — untouched by the ctors
        uint32_t mField48;     // 0x48 — factory zero
        uint8_t pad4c[4];      // 0x4c — unproven padding
        void* mPtr50;          // 0x50 — factory zero
        // (0x58 total)
    };
}

// Naming closure: only ctor string is the generic 'param_list'; array-element variant with factory case id only. Address-anchored name retained.
