#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVtb690 — PROVISIONAL vtable-anchored name (vptr 0x12bb690, GOT cell
    // 0x130e4b8). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=25 slots, allocation
    // 0x1678 at site 0x6fc0a0. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields (0x40+) map pending.
    class ParamContainerVtb690
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[8];      // 0x08
        char mOwn10[0x1668];    // 0x10 — own-field region (map pending)
        // (0x1678 total, factory alloc)
    };
}
