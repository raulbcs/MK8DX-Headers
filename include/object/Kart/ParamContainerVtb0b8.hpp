#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVtb0b8 — PROVISIONAL vtable-anchored name (vptr 0x12bb0b8, GOT cell
    // 0x130e4c0). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=28 slots, allocation
    // 0x2f0 at site 0x6fc2dc. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields mapped from the inlined construction at the quoted site
    // (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
    class ParamContainerVtb0b8
    {
    public:
        void* vtable;        // 0x00
        uint8_t mPad8[0x28];  // 0x8 — unproven gap (pre-secondary-base)
        uint8_t mPad30[0x8];  // 0x30 — secondary hook-band vptr (ctor-written)
        uint8_t mPad38[0x228];  // 0x38 — array/body region — unproven gap
        uint8_t mPad260[0x8];  // 0x260 — ctor-zeroed pair (0x260/0x268)
        uint8_t mPad268[0x4];  // 0x268 — unproven gap
        uint8_t mPad26c[0x4];  // 0x26c — unproven gap
        uint8_t mPad270[0x4];  // 0x270 — ctor-zero (param)
        uint8_t mPad274[0x4];  // 0x274 — ctor-written (param w22)
        uint8_t mPad278[0x78];  // 0x278 — unproven gap
        // (0x2f0 total, factory alloc)
    };
}
