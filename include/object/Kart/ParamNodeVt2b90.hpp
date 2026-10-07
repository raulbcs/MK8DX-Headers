#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVt2b90 — PROVISIONAL vtable-anchored name (vptr 0x12b2b90, cell 0x130da00, n=23, site 0x64f04c, ctor 0x64eea8).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    // Ctor-evidence note: recorded ctor 0x710064eea8 stores a float triple
    // (stp s1,s2 [x19]; str s0 [x19,#0x8]) but performs no vptr store — likely a
    // helper, not the true ctor; own fields unmapped — evidence insufficient.
    class ParamNodeVt2b90
    {
    public:
        void* vtable;          // 0x00
        // (own fields unmapped; see ctor-evidence note)
    };
}
