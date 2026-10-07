#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex24JobConnectSecureEndPointE).
    // vptr 0x12e7070 (GOT cell 0x1314d50, n=12, ctor 0xa3f544, sole construction site 0xa3f58c).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobConnectSecureEndPoint
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint8_t  mPada0[0x88];      // 0xa0 — unproven gap
        uint64_t mField128;   // 0x128 — ctor-written
        uint64_t mField130;   // 0x130 — ctor-written (stp high half)
        uint64_t mZero138;    // 0x138 — ctor zero
        uint64_t mField140;   // 0x140 — ctor zero (stp high half)
        uint8_t  mPad148[0x8];      // 0x148 — unproven gap
        uint8_t  mInit150;       // 0x150 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad158[0xb8];      // 0x158 — unproven gap
        uint64_t mField210;   // 0x210 — ctor-written
        uint8_t  mPad218[0x4];      // 0x218 — unproven gap
        uint8_t  mZero21c;    // 0x21c — ctor zero
        uint8_t  mPad21d[0x3];      // 0x21d — unproven gap
        uint64_t mZero220;    // 0x220 — ctor zero
        uint32_t mZero228;    // 0x228 — ctor zero
        uint8_t  mPad22c[0x4];      // 0x22c — unproven gap
        uint64_t mField230;   // 0x230 — ctor-written
        uint64_t mField238;   // 0x238 — ctor-written
        uint64_t mZero240;    // 0x240 — ctor zero
        uint64_t mZero248;    // 0x248 — ctor zero
        uint64_t mZero250;    // 0x250 — ctor zero
        uint64_t mZero258;    // 0x258 — ctor zero
        uint64_t mZero260;    // 0x260 — ctor zero
        uint8_t  mInit268;       // 0x268 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad270[0x10];      // 0x270 — unproven gap
        uint64_t mZero280;    // 0x280 — ctor zero
        uint32_t mZero288;    // 0x288 — ctor zero
        uint8_t  mPad28c[0x4];      // 0x28c — unproven gap
        uint64_t mZero290;    // 0x290 — ctor zero
        uint64_t mZero298;    // 0x298 — ctor zero
        uint64_t mField2a0;   // 0x2a0 — ctor-written
        uint64_t mZero2a8;    // 0x2a8 — ctor zero
        uint64_t mField2b0;   // 0x2b0 — ctor-written
        uint64_t mField2b8;   // 0x2b8 — ctor-written
        uint64_t mZero2c0;    // 0x2c0 — ctor zero
        uint8_t  mInit2c8;       // 0x2c8 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad2d0[0x80];      // 0x2d0 — unproven gap
        uint8_t  mInit350;       // 0x350 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad358[0x68];      // 0x358 — unproven gap
        uint64_t mField3c0;   // 0x3c0 — ctor-written
        uint64_t mField3c8;   // 0x3c8 — ctor-written
        uint64_t mField3d0;   // 0x3d0 — ctor-written
        uint64_t mField3d8;   // 0x3d8 — ctor-written
        uint64_t mZero3e0;    // 0x3e0 — ctor zero
        uint32_t mZero3e8;    // 0x3e8 — ctor zero
        uint8_t  mPad3ec[0x4];      // 0x3ec — unproven gap
        uint64_t mZero3f0;    // 0x3f0 — ctor zero
    // Object size 0x3f8 (allocation size at the factory new preceding ctor 0xa3f544).
    };
}
