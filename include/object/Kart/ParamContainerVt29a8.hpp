#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVt29a8 — address-anchored name (vptr 0x12d29a8, GOT cell
    // 0x1311590). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=25 slots, allocation
    // 0x340 at site 0x88e930. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields mapped from the inlined construction at the quoted site
    // (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
    class ParamContainerVt29a8
    {
    public:
        void* vtable;        // 0x00
        uint8_t mPad8[0x28];  // 0x8 — unproven gap (pre-secondary-base)
        uint8_t mPad30[0x8];  // 0x30 — secondary hook-band vptr (ctor-written)
        uint8_t mPad38[0x2c8];  // 0x38 — array/body region — unproven gap
        uint8_t mPad300[0x8];  // 0x300 — inner vptr (ctor-written)
        uint8_t mPad308[0x28];  // 0x308 — ctor-zeroed region (0x308-0x320 qword-zeroed)
        uint8_t mPad330[0x2];  // 0x330 — u16 count/flag — ctor-written
        uint8_t mPad332[0x2];  // 0x332 — unproven gap
        uint8_t mPad334[0x4];  // 0x334 — ctor-zero
        uint8_t mPad338[0x4];  // 0x338 — unproven gap
        uint8_t mPad33c[0x2];  // 0x33c — u16 — ctor-written
        uint8_t mPad33e[0x2];  // 0x33e — u16 — ctor-zero
        // (0x340 total, factory alloc)
    };
}

// Naming closure: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only). Address-anchored name retained.
