#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVt32a8 — PROVISIONAL vtable-anchored name (vptr 0x12f32a8, cell 0x13152b8, n=23, site 0x9c633c, ctor 0x9c6310).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    class ParamNodeVt32a8
    {
    public:
        void* vtable;         // 0x00
        uint8_t mPad8[0x28];  // 0x8 — unproven gap
        uint16_t mField30;    // 0x30 — ctor-written
    };
}
