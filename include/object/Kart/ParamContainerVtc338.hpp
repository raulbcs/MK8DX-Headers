#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVtc338 — PROVISIONAL vtable-anchored name (vptr 0x12bc338, GOT cell
    // 0x130e660). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=25 slots, allocation
    // 0x370 at site 0x712cac. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields (0x40+) map pending.
    class ParamContainerVtc338
    {
    public:
        void* vtable;        // 0x00
        uint8_t mPad8[0x28];  // 0x8 — unproven gap (pre-secondary-base)
        uint8_t mPad30[0x8];  // 0x30 — secondary hook-band vptr (ctor-written)
        uint8_t mPad38[0x2f8];  // 0x38 — array/body region — unproven gap
        uint8_t mPad330[0x8];  // 0x330 — inner vptr (ctor-written)
        uint8_t mPad338[0x28];  // 0x338 — ctor-zeroed region (0x338-0x350 qword-zeroed)
        uint8_t mPad360[0x2];  // 0x360 — u16 count/flag — ctor-written
        uint8_t mPad362[0x2];  // 0x362 — unproven gap
        uint8_t mPad364[0x4];  // 0x364 — ctor-zero
        uint8_t mPad368[0x4];  // 0x368 — unproven gap
        uint8_t mPad36c[0x2];  // 0x36c — u16 — ctor-written
        uint8_t mPad36e[0x2];  // 0x36e — u16 — ctor-zero
        // (0x370 total, factory alloc)
    };
}
