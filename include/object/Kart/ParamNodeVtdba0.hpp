#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVtdba0 — PROVISIONAL vtable-anchored name (vptr 0x12bdba0, cell 0x130e918, n=29, site 0x606e1c, ctor 0x606e0c).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    // Ctor-evidence note: recorded ctor 0x7100606e0c stores a pointer at
    // [x20,#0xe8] via an intermediate register chain — likely a sub-object field,
    // base/sub-object split unproven; own fields unmapped — evidence insufficient.
    class ParamNodeVtdba0
    {
    public:
        void* vtable;          // 0x00
        // (own fields unmapped; see ctor-evidence note)
    };
}
