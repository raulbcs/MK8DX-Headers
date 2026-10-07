#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVtdcd8 — PROVISIONAL vtable-anchored name (vptr 0x12bdcd8, GOT cell
    // 0x130e928). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=33 slots, allocation
    // 0x488 at site 0x72f46c. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields mapped from the inlined construction at the quoted site
    // (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
    class ParamContainerVtdcd8
    {
    public:
        void* vtable;        // 0x00
        uint8_t mPad8[0x28];  // 0x8 — unproven gap (pre-secondary-base)
        uint8_t mPad30[0x8];  // 0x30 — secondary hook-band vptr (ctor-written)
        uint8_t mPad38[0x410];  // 0x38 — array/body region — unproven gap
        uint8_t mPad448[0x8];  // 0x448 — inner vptr (ctor-written)
        uint8_t mPad450[0x28];  // 0x450 — ctor-zeroed region (0x450-0x468 qword-zeroed)
        uint8_t mPad478[0x2];  // 0x478 — u16 count/flag — ctor-written
        uint8_t mPad47a[0x2];  // 0x47a — unproven gap
        uint8_t mPad47c[0x4];  // 0x47c — ctor-zero
        uint8_t mPad480[0x4];  // 0x480 — unproven gap
        uint8_t mPad484[0x2];  // 0x484 — u16 — ctor-written
        uint8_t mPad486[0x2];  // 0x486 — u16 — ctor-zero
        // (0x488 total, factory alloc)
    };
}
