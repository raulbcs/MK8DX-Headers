#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVte3d0 — PROVISIONAL vtable-anchored name (vptr 0x12be3d0, cell 0x130e988, n=27, site 0x732d38, ctor 0x732d0c).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    class ParamNodeVte3d0
    {
    public:
        void* vtable;         // 0x00
        uint8_t mPad8[0x28];  // 0x8 — unproven gap
        uint64_t mField30;    // 0x30 — ctor-written
    };
}
