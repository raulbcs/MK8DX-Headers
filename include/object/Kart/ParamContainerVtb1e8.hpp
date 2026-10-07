#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVtb1e8 — PROVISIONAL vtable-anchored name (vptr 0x12bb1e8, GOT cell
    // 0x130e4c8). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=28 slots, allocation
    // 0x2f0 at site 0x6fc4d4. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields (0x40+) map pending.
    class ParamContainerVtb1e8
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[8];      // 0x08
        char mOwn10[0x2e0];    // 0x10 — own-field region (map pending)
        // (0x2f0 total, factory alloc)
    };
}
