#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVtd558 — PROVISIONAL vtable-anchored name (vptr 0x12bd558, GOT cell
    // 0x130e898). Node class of the 0x647f40 hook-band cluster
    // (param-cache super-family ring): vptr, fields to 0x30, recorder
    // channel-pair member at 0x30 (ctor pair 0x7100662f30/0x7100662f70),
    // tail to 0x50 (array stride 0x50 evidence, site 0x727d78).
    // Shares the trivial hook band 0x647f40-0x647f6c (return-1/ret/slot-0x78
    // thunk/ID compare vs [this+0x1c]).
    class ParamNodeVtd558
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[0x28];   // 0x08 — map pending (per-class ctor block)
        char mChan30[0x20];    // 0x30 — recorder channel-pair member
        // (0x50 total)
    };
}
