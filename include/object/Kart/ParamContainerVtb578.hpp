#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVtb578 — PROVISIONAL vtable-anchored name (vptr 0x12bb578, GOT cell
    // 0x130e498). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=25 slots, allocation
    // 0x1678 at site 0x6fbdfc. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields (0x40+) map pending.
    class ParamContainerVtb578
    {
    public:
        void* vtable;        // 0x00
        uint8_t mPad8[0x28];  // 0x8 — unproven gap (pre-secondary-base)
        uint8_t mPad30[0x8];  // 0x30 — secondary hook-band vptr (ctor-written)
        uint8_t mPad38[0x1640];  // 0x38 — array/body region — unproven gap
        // (0x1678 total, factory alloc)
    };
}
