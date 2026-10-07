#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVtbc88 — PROVISIONAL vtable-anchored name (vptr 0x12bbc88, GOT cell
    // 0x130e5e8). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=25 slots, allocation
    // 0x340 at site 0x706e90. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields (0x40+) map pending.
    class ParamContainerVtbc88
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[8];      // 0x08
        char mOwn10[0x330];    // 0x10 — own-field region (map pending)
        // (0x340 total, factory alloc)
    };
}
