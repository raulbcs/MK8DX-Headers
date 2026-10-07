#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheColorCorrection — named from ctor string evidence: ctor string tag 'aglccr' + params hue/saturation/brightness/gamma/toycam_enable (EN/JP pairs at 0xef93f6-0xef94c4) (was address-anchored KartParamCacheVt30a8) (vptr
    // 0x12b30a8, GOT cell 0x130da78). Largest KartParamCache variant:
    // ctor 0x710064fb3c built by the factory 0x710065efbc (alloc 0x1a30).
    // NOT a KartParamCacheMid derive — it goes straight over the
    // KartParamCache base: embedded member at 0x1d0 (vptr 0x12b26b0, a
    // small cluster vtable — secondary base), recorder channel-pair
    // members from 0x200 on (pair 0x7100662f30/0x7100662f70, names
    // 0xef8f59/0xef8f60, cell 0x130d908), member writes up to 0x300+.
    class KartParamCacheColorCorrection : public KartParamCache
    {
    public:
        void* mSecVt1d0;          // 0x1d0 — secondary vptr (0x12b26b0 +0x10)
        char mSub1d8[0x28];       // 0x1d8 — secondary-base member body
        char mChan200[0x20];      // 0x200 — channel-pair member
        uint64_t mField220;       // 0x220 — ctor-written
        uint8_t mPad228[0x10];    // 0x228 — unproven gap
        uint32_t mZero238;        // 0x238 — ctor zero
        uint8_t mPad23c[0x4];     // 0x23c — unproven gap
        uint64_t mField240;       // 0x240 — ctor-written
        uint8_t mPad248[0x10];    // 0x248 — unproven gap
        uint32_t mField258;       // 0x258 — ctor-written
        uint8_t mPad25c[0x4];     // 0x25c — unproven gap
        uint64_t mField260;       // 0x260 — ctor-written
        uint8_t mPad268[0x10];    // 0x268 — unproven gap
        uint32_t mField278;       // 0x278 — ctor-written
        uint8_t mPad27c[0x4];     // 0x27c — unproven gap
        uint64_t mField280;       // 0x280 — ctor-written
        uint8_t mPad288[0x10];    // 0x288 — unproven gap
        uint32_t mField298;       // 0x298 — ctor-written
        uint8_t mPad29c[0x4];     // 0x29c — unproven gap
        uint64_t mField2a0;       // 0x2a0 — ctor-written
        uint8_t mPad2a8[0x10];    // 0x2a8 — unproven gap
        uint8_t mZero2b8;         // 0x2b8 — ctor zero
        uint8_t mPad2b9[0x7];     // 0x2b9 — unproven gap
        uint64_t mField2c0;       // 0x2c0 — ctor-written
        uint8_t mPad2c8[0x10];    // 0x2c8 — unproven gap
        uint8_t mZero2d8;         // 0x2d8 — ctor zero
        uint8_t mPad2d9[0x7];     // 0x2d9 — unproven gap
        uint64_t mField2e0;       // 0x2e0 — ctor-written
        uint8_t mPad2e8[0x10];    // 0x2e8 — unproven gap
        uint32_t mField2f8;       // 0x2f8 — ctor-written
        uint32_t mField2fc;       // 0x2fc — ctor-written
        uint32_t mField300;       // 0x300 — ctor-written
        uint32_t mField304;       // 0x304 — ctor-written
        uint64_t mField308;       // 0x308 — ctor-written
        uint8_t mPad310[0x10];    // 0x310 — unproven gap
        uint32_t mField320;       // 0x320 — ctor-written
        uint32_t mField324;       // 0x324 — ctor-written
        uint32_t mField328;       // 0x328 — ctor-written
        uint32_t mField32c;       // 0x32c — ctor-written
        uint64_t mField330;       // 0x330 — ctor-written
        uint8_t mPad338[0x10];    // 0x338 — unproven gap
        uint32_t mField348;       // 0x348 — ctor-written
        uint32_t mField34c;       // 0x34c — ctor-written
        uint32_t mField350;       // 0x350 — ctor-written
        uint32_t mField354;       // 0x354 — ctor-written
        uint64_t mField358;       // 0x358 — ctor-written
        uint8_t mPad360[0x10];    // 0x360 — unproven gap
        uint32_t mField370;       // 0x370 — ctor-written
        uint32_t mField374;       // 0x374 — ctor-written
        uint32_t mField378;       // 0x378 — ctor-written
        uint32_t mField37c;       // 0x37c — ctor-written
        uint64_t mField380;       // 0x380 — ctor-written
        uint8_t mPad388[0x10];    // 0x388 — unproven gap
        uint32_t mField398;       // 0x398 — ctor-written
        uint8_t mPad39c[0x4];     // 0x39c — unproven gap
        uint64_t mField3a0;       // 0x3a0 — ctor-written
        uint8_t mPad3a8[0x10];    // 0x3a8 — unproven gap
        uint32_t mField3b8;       // 0x3b8 — ctor-written
        uint8_t mPad3bc[0x4];     // 0x3bc — unproven gap
        uint64_t mField3c0;       // 0x3c0 — ctor-written
        uint8_t mPad3c8[0x10];    // 0x3c8 — unproven gap
        uint32_t mField3d8;       // 0x3d8 — ctor-written
        uint8_t mPad3dc[0x4];     // 0x3dc — unproven gap
        uint64_t mField3e0;       // 0x3e0 — ctor-written
        uint8_t mPad3e8[0x10];    // 0x3e8 — unproven gap
        uint32_t mField3f8;       // 0x3f8 — ctor-written
        uint8_t mPad3fc[0x4];     // 0x3fc — unproven gap
        uint64_t mField400;       // 0x400 — ctor-written
        uint8_t mPad408[0x10];    // 0x408 — unproven gap
        uint32_t mField418;       // 0x418 — ctor-written
        uint32_t mField41c;       // 0x41c — ctor-written
        uint32_t mField420;       // 0x420 — ctor-written
        uint32_t mField424;       // 0x424 — ctor-written
        uint8_t mPad428[0x8];     // 0x428 — unproven gap
        uint16_t mZero430;        // 0x430 — ctor zero
        uint8_t mPad432[0xa];     // 0x432 — unproven gap
        uint8_t mZero43c;         // 0x43c — ctor zero
        uint8_t mPad43d[0x6b];    // 0x43d — unproven gap
        uint64_t mZero4a8;        // 0x4a8 — ctor zero
        uint8_t mPad4b0[0x1230];  // 0x4b0 — unproven gap
        uint64_t mZero16e0;       // 0x16e0 — ctor zero
        uint32_t mZero16e8;       // 0x16e8 — ctor zero
        uint8_t mPad16ec[0x4];    // 0x16ec — unproven gap
        uint64_t mZero16f0;       // 0x16f0 — ctor zero
        uint32_t mZero16f8;       // 0x16f8 — ctor zero
        uint8_t mPad16fc[0x4];    // 0x16fc — unproven gap
        uint64_t mZero1700;       // 0x1700 — ctor zero
        uint32_t mZero1708;       // 0x1708 — ctor zero
        uint8_t mPad170c[0x30c];  // 0x170c — unproven gap
        uint32_t mField1a18;      // 0x1a18 — ctor-written
        uint8_t mPad1a1c[0x4];    // 0x1a1c — unproven gap
        uint64_t mZero1a20;       // 0x1a20 — ctor zero
        uint32_t mZero1a28;       // 0x1a28 — ctor zero
        uint8_t mPad1a2c[0x4];    // 0x1a2c — unproven gap
        // (0x1a30 total)
    };
}

// Naming closure: factory/array structural variant (base-call chain + factory case id only, no per-class strings). Address-anchored name retained.
