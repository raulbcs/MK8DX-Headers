#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeDirectionalLight — named from ctor string evidence: ctor params SkyColor/GroundColor/Intensity/Direction (EN/JP, 0xef9183-0xef92cd) (was address-anchored ParamNodeVt2c98) (vptr 0x12b2c98, cell 0x130d9e0, n=23, site 0x64d254, ctor 0x64d22c, alloc 0x28).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    class ParamNodeDirectionalLight
    {
    public:
        void* vtable;           // 0x00
        uint8_t mPad8[0x28];    // 0x8 — unproven gap
        uint64_t mField30;      // 0x30 — ctor-written
        uint8_t mPad38[0xd8];   // 0x38 — unproven gap
        uint64_t mField110;     // 0x110 — ctor-written
        uint8_t mPad118[0x10];  // 0x118 — unproven gap
        uint32_t mField128;     // 0x128 — ctor-written
        uint32_t mField12c;     // 0x12c — ctor-written
        uint32_t mField130;     // 0x130 — ctor-written
        uint32_t mField134;     // 0x134 — ctor-written
        uint64_t mField138;     // 0x138 — ctor-written
        uint8_t mPad140[0x10];  // 0x140 — unproven gap
        uint32_t mField150;     // 0x150 — ctor-written
        uint32_t mField154;     // 0x154 — ctor-written
        uint32_t mField158;     // 0x158 — ctor-written
        uint32_t mField15c;     // 0x15c — ctor-written
        uint64_t mField160;     // 0x160 — ctor-written
        uint8_t mPad168[0x10];  // 0x168 — unproven gap
        uint32_t mField178;     // 0x178 — ctor-written
        uint8_t mPad17c[0x4];   // 0x17c — unproven gap
        uint64_t mField180;     // 0x180 — ctor-written
        uint8_t mPad188[0x10];  // 0x188 — unproven gap
        uint32_t mField198;     // 0x198 — ctor-written
        uint32_t mField19c;     // 0x19c — ctor-written
        uint32_t mField1a0;     // 0x1a0 — ctor-written
        uint8_t mPad1a4[0x4];   // 0x1a4 — unproven gap
        uint32_t mZero1a8;      // 0x1a8 — ctor zero
        uint8_t mPad1ac[0x4];   // 0x1ac — unproven gap
        uint64_t mZero1b0;      // 0x1b0 — ctor zero
    };
}

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
