#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVt47a0 — address-anchored name (vptr 0x12f47a0, cell 0x13154e8, n=38, site 0xaf25b8, ctor 0xaf259c, alloc 0x48).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    class ParamNodeVt47a0
    {
    public:
        void* vtable;           // 0x00
        uint8_t mPad8[0x28];    // 0x8 — unproven gap
        uint64_t mField30;      // 0x30 — ctor-written
        uint8_t mPad38[0xe58];  // 0x38 — unproven gap
        uint64_t mZeroe90;      // 0xe90 — ctor zero
        uint64_t mZeroe98;      // 0xe98 — ctor zero
        uint64_t mZeroea0;      // 0xea0 — ctor zero
        uint64_t mZeroea8;      // 0xea8 — ctor zero
        uint32_t mZeroeb0;      // 0xeb0 — ctor zero
    };
}

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
