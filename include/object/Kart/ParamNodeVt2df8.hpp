#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVt2df8 — PROVISIONAL vtable-anchored name (vptr 0x12f2df8, GOT cell
    // 0x1315230). Node class of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): vptr, fields to 0x30, recorder
    // channel-pair member at 0x30 (ctor pair 0x7100662f30/0x7100662f70),
    // tail to 0x50 (array stride 0x50 evidence, site 0xaa2ba4).
    // Shares the trivial hook band 0x647f40-0x647f6c (return-1/ret/slot-0x78
    // thunk/ID compare vs [this+0x1c]).
    class ParamNodeVt2df8
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[0x28];   // 0x08 — map pending (per-class ctor block)
        char mChan30[0x20];    // 0x30 — recorder channel-pair member
        // (0x50 total)
    };
}
