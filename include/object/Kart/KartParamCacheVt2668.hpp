#pragma once

#include <cstdint>

namespace object
{
    // KartParamCacheVt2668 — PROVISIONAL vtable-anchored name (vptr 0x12b2668,
    // GOT cell 0x130d980). Cluster variant (ctor 0x710064a708): first calls ctor 0x710064822c
    // (KartParamCacheVt2358 class, extent 0x38) on this, then the
    // KartParamCache base ctor, member at 0xd8, KartParamCacheNode member
    // at 0x128, zeros 0x120/0x158/0x160. Extent 0x168. Exact base chain
    // (Vt2358 vs member) map pending.
    class KartParamCacheVt2668
    {
    public:
        void* vtable;           // 0x00
        uint8_t pad08[0x30];    // 0x08   // 0x08
        uint8_t mPad8[0x30];    // 0x8 — unproven gap
        uint64_t mField38;      // 0x38 — ctor-written
        uint8_t mPad40[0x48];   // 0x40 — unproven gap
        uint64_t mField88;      // 0x88 — ctor-written
        uint8_t mPad90[0x18];   // 0x90 — unproven gap
        uint64_t mFielda8;      // 0xa8 — ctor-written
        uint32_t mFieldb0;      // 0xb0 — ctor-written
        uint8_t mPadb4[0x24];   // 0xb4 — unproven gap
        uint64_t mFieldd8;      // 0xd8 — ctor-written
        uint8_t mPade0[0x40];   // 0xe0 — unproven gap
        uint64_t mZero120;      // 0x120 — ctor zero
        uint64_t mField128;     // 0x128 — ctor-written
        uint8_t mPad130[0x28];  // 0x130 — unproven gap
        uint32_t mZero158;      // 0x158 — ctor zero
        uint8_t mPad15c[0x4];   // 0x15c — unproven gap
        uint64_t mZero160;      // 0x160 — ctor zero
        // (0x168 total)
    };
}
