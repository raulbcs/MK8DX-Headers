#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVtaf38 — address-anchored name (vptr 0x12baf38, cell 0x130e4b0, n=38, site 0x6c3918, ctor 0x6c38b8, alloc 0xb0).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    class ParamNodeVtaf38
    {
    public:
        void* vtable;            // 0x00
        uint8_t mPad8[0x240];    // 0x8 — unproven gap
        uint64_t mField248;      // 0x248 — ctor-written
        uint8_t mPad250[0xaa0];  // 0x250 — unproven gap
        uint64_t mFieldcf0;      // 0xcf0 — ctor-written
        uint64_t mFieldcf8;      // 0xcf8 — ctor-written
        uint8_t mPadd00[0x8];    // 0xd00 — unproven gap
        uint32_t mFieldd08;      // 0xd08 — ctor-written
        uint8_t mPadd0c[0x4];    // 0xd0c — unproven gap
        uint64_t mFieldd10;      // 0xd10 — ctor-written
        uint8_t mPadd18[0x8];    // 0xd18 — unproven gap
        uint32_t mFieldd20;      // 0xd20 — ctor-written
    };
}

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
