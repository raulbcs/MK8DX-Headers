#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheOfx — named from ctor string evidence: ctor string tag 'aglofx' (0xf1f263) (was PROVISIONAL vtable-anchored KartParamCacheVt4bb8) (vptr 0x12f4bb8, cell 0x1315530, n=13, site 0xaf5744, ctor 0xaf56f8).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheOfx : public KartParamCache
    {
    public:
        uint8_t mPad40[0x190];    // 0x40 — unproven gap
        uint64_t mField1d0;       // 0x1d0 — ctor-written
        uint32_t mField1d8;       // 0x1d8 — ctor-written
        uint32_t mField1dc;       // 0x1dc — ctor-written
        uint32_t mField1e0;       // 0x1e0 — ctor-written
        uint8_t mPad1e4[0x4];     // 0x1e4 — unproven gap
        uint64_t mField1e8;       // 0x1e8 — ctor-written
        uint8_t mPad1f0[0x8];     // 0x1f0 — unproven gap
        uint32_t mField1f8;       // 0x1f8 — ctor-written
        uint8_t mPad1fc[0x104];   // 0x1fc — unproven gap
        uint64_t mZero300;        // 0x300 — ctor zero
        uint64_t mZero308;        // 0x308 — ctor zero
        uint64_t mZero310;        // 0x310 — ctor zero
        uint32_t mZero318;        // 0x318 — ctor zero
        uint8_t mPad31c[0x804];   // 0x31c — unproven gap
        uint64_t mFieldb20;       // 0xb20 — ctor-written
        uint8_t mPadb28[0x40];    // 0xb28 — unproven gap
        uint32_t mZerob68;        // 0xb68 — ctor zero
        uint8_t mPadb6c[0x4];     // 0xb6c — unproven gap
        uint64_t mZerob70;        // 0xb70 — ctor zero
        void* mSelfb78;           // 0xb78 — ctor stores `this`
        uint8_t mPadb80[0x8];     // 0xb80 — unproven gap
        uint32_t mZerob88;        // 0xb88 — ctor zero
        uint8_t mPadb8c[0x4];     // 0xb8c — unproven gap
        uint64_t mZerob90;        // 0xb90 — ctor zero
        uint32_t mZerob98;        // 0xb98 — ctor zero
        uint8_t mPadb9c[0x4];     // 0xb9c — unproven gap
        uint64_t mZeroba0;        // 0xba0 — ctor zero
        uint64_t mZeroba8;        // 0xba8 — ctor zero
        uint64_t mFieldbb0;       // 0xbb0 — ctor-written
        uint64_t mFieldbb8;       // 0xbb8 — ctor-written
        uint32_t mFieldbc0;       // 0xbc0 — ctor-written
        uint8_t mPadbc4[0x104];   // 0xbc4 — unproven gap
        uint64_t mFieldcc8;       // 0xcc8 — ctor-written
        uint64_t mFieldcd0;       // 0xcd0 — ctor-written
        uint32_t mFieldcd8;       // 0xcd8 — ctor-written
        uint8_t mPadcdc[0x104];   // 0xcdc — unproven gap
        uint64_t mZerode0;        // 0xde0 — ctor zero
        uint64_t mZerode8;        // 0xde8 — ctor zero
        uint64_t mFielddf0;       // 0xdf0 — ctor-written
        uint64_t mFielddf8;       // 0xdf8 — ctor-written
        uint32_t mFielde00;       // 0xe00 — ctor-written
        uint8_t mPade04[0x204];   // 0xe04 — unproven gap
        uint64_t mZero1008;       // 0x1008 — ctor zero
        uint32_t mZero1010;       // 0x1010 — ctor zero
        uint8_t mPad1014[0x4];    // 0x1014 — unproven gap
        uint32_t mZero1018;       // 0x1018 — ctor zero
        uint8_t mPad101c[0x4];    // 0x101c — unproven gap
        uint64_t mZero1020;       // 0x1020 — ctor zero
        uint64_t mZero1028;       // 0x1028 — ctor zero
        uint64_t mField1030;      // 0x1030 — ctor-written
        uint64_t mField1038;      // 0x1038 — ctor-written
        uint32_t mField1040;      // 0x1040 — ctor-written
        uint8_t mPad1044[0x10c];  // 0x1044 — unproven gap
        uint64_t mField1150;      // 0x1150 — ctor-written
        uint64_t mField1158;      // 0x1158 — ctor-written
        uint32_t mField1160;      // 0x1160 — ctor-written
        uint8_t mPad1164[0x204];  // 0x1164 — unproven gap
        uint64_t mZero1368;       // 0x1368 — ctor zero
        uint32_t mZero1370;       // 0x1370 — ctor zero
        uint8_t mPad1374[0x4];    // 0x1374 — unproven gap
        uint32_t mZero1378;       // 0x1378 — ctor zero
        uint8_t mPad137c[0x4];    // 0x137c — unproven gap
        uint64_t mZero1380;       // 0x1380 — ctor zero
        uint64_t mZero1388;       // 0x1388 — ctor zero
        uint64_t mField1390;      // 0x1390 — ctor-written
        uint64_t mField1398;      // 0x1398 — ctor-written
        uint32_t mField13a0;      // 0x13a0 — ctor-written
        uint8_t mPad13a4[0x10c];  // 0x13a4 — unproven gap
        uint64_t mField14b0;      // 0x14b0 — ctor-written
        uint64_t mField14b8;      // 0x14b8 — ctor-written
        uint32_t mField14c0;      // 0x14c0 — ctor-written
        uint8_t mPad14c4[0x404];  // 0x14c4 — unproven gap
        uint64_t mField18c8;      // 0x18c8 — ctor-written
        uint64_t mField18d0;      // 0x18d0 — ctor-written
        uint32_t mField18d8;      // 0x18d8 — ctor-written
        uint8_t mPad18dc[0x404];  // 0x18dc — unproven gap
        uint64_t mField1ce0;      // 0x1ce0 — ctor-written
        uint64_t mField1ce8;      // 0x1ce8 — ctor-written
        uint32_t mField1cf0;      // 0x1cf0 — ctor-written
        uint8_t mPad1cf4[0x404];  // 0x1cf4 — unproven gap
        uint64_t mZero20f8;       // 0x20f8 — ctor zero
        uint64_t mZero2100;       // 0x2100 — ctor zero
        uint32_t mField2108;      // 0x2108 — ctor-written
        uint8_t mPad210c[0x4];    // 0x210c — unproven gap
        uint64_t mField2110;      // 0x2110 — ctor-written
        uint8_t mPad2118[0x150];  // 0x2118 — unproven gap
        uint64_t mField2268;      // 0x2268 — ctor-written
        uint8_t mPad2270[0x90];   // 0x2270 — unproven gap
        uint64_t mField2300;      // 0x2300 — ctor-written
        uint8_t mPad2308[0x150];  // 0x2308 — unproven gap
        uint64_t mField2458;      // 0x2458 — ctor-written
        uint8_t mPad2460[0x90];   // 0x2460 — unproven gap
        uint64_t mField24f0;      // 0x24f0 — ctor-written
        uint8_t mPad24f8[0x150];  // 0x24f8 — unproven gap
        uint64_t mField2648;      // 0x2648 — ctor-written
        uint8_t mPad2650[0x90];   // 0x2650 — unproven gap
        uint64_t mField26e0;      // 0x26e0 — ctor-written
        uint8_t mPad26e8[0x150];  // 0x26e8 — unproven gap
        uint64_t mField2838;      // 0x2838 — ctor-written
    };
}
