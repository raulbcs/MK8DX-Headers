#pragma once

#include <cstdint>

namespace object
{
    // ParamContainerVt4aa0 — PROVISIONAL vtable-anchored name (vptr 0x12f4aa0, GOT cell
    // 0x1315508). Large container of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): n=25 slots, allocation
    // 0x1680 at site 0xaf527c. Shares the trivial hook band
    // 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
    // Own fields (0x40+) map pending.
    class ParamContainerVt4aa0
    {
    public:
        void* vtable;         // 0x00
        uint8_t pad08[8];     // 0x08
        char mOwn10[0x1670];  // 0x10 — own-field region
        // (0x1680 total, factory alloc)
    };
}
