#pragma once

#include <cstdint>

namespace object
{
    // KartParamCacheVt2668 — address-anchored name (vptr 0x12b2668,
    // GOT cell 0x130d980). Cluster variant, extent 0x168 (ctor 0x710064a708):
    // KartParamCacheEnv base (ctor 0x710064822c, extent 0x38), then
    // members: KartParamCacheMid2-shaped 0x48 member at 0x40 (ctor
    // 0x710061cc48), KartParamCacheVt24c8-shaped 0x20 member at 0x88 (ctor
    // 0x7100669954), KartParamCacheChanBase member at 0xa8 (ctor
    // 0x7100662f30), another 0x48 Mid2-shaped member at 0xd8, zero qword at
    // 0x120, KartParamCacheNodeBase member at 0x128 (ctor 0x710066a2a4),
    // zero w32 at 0x158 and zero qword at 0x160.
    class KartParamCacheVt2668
    {
    public:
        void* vtable;           // 0x00
        uint8_t mEnvBase08[0x30]; // 0x08 — KartParamCacheEnv base fields (ctor-zeroed)
        uint64_t mField38;      // 0x38 — ctor-written
        char mMid2Member40[0x48]; // 0x40 — member, ctor 0x710061cc48 (Mid2-shaped, extent 0x48)
        char mVt24c8Member88[0x20]; // 0x88 — member, ctor 0x7100669954 (Vt24c8-shaped, extent 0x20)
        void* mChanBaseA8;      // 0xa8 — KartParamCacheChanBase member vptr (ctor 0x7100662f30)
        uint32_t mFieldb0;      // 0xb0 — ctor-written (ChanBase ctor writes w0)
        uint8_t mPadb4[0x24];   // 0xb4 — unproven gap
        char mMid2Memberd8[0x48]; // 0xd8 — member, ctor 0x710061cc48 (Mid2-shaped, extent 0x48)
        uint64_t mZero120;      // 0x120 — ctor zero
        char mNodeBase128[0x20]; // 0x128 — member, ctor 0x710066a2a4 (KartParamCacheNodeBase)
        uint8_t mPad148[0x10];  // 0x148 — unproven gap
        uint32_t mZero158;      // 0x158 — ctor zero
        uint8_t mPad15c[0x4];   // 0x15c — unproven gap
        uint64_t mZero160;      // 0x160 — ctor zero
        // (0x168 total)
    };
}

// Naming closure: only ctor string is the debug icon 'Icon=CIRCLE_GREEN' (0xef90b0); no role evidence. Address-anchored name retained.
