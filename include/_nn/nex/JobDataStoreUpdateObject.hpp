#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex24JobDataStoreUpdateObjectE).
    // vptr 0x12f6ff8 (GOT cell 0x1315948, n=14, ctor 0xb193bc, sole construction site 0xb19444).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobDataStoreUpdateObject
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint32_t mZeroa0;     // 0xa0 — ctor zero
        uint8_t  mPada4[0x4];      // 0xa4 — unproven gap
        uint64_t mZeroa8;     // 0xa8 — ctor zero
        uint64_t mFieldb0;    // 0xb0 — ctor zero (stp high half)
        uint8_t  mFieldb8;    // 0xb8 — ctor-written
        uint8_t  mPadb9[0x7];      // 0xb9 — unproven gap
        uint64_t mZeroc0;     // 0xc0 — ctor zero
        uint64_t mFieldc8;    // 0xc8 — ctor zero (stp high half)
        uint64_t mZerod0;     // 0xd0 — ctor zero
        uint64_t mFieldd8;    // 0xd8 — ctor zero (stp high half)
        uint32_t mZeroe0;     // 0xe0 — ctor zero
        uint8_t  mPade4[0x4];      // 0xe4 — unproven gap
        uint64_t mZeroe8;     // 0xe8 — ctor zero
        uint64_t mFieldf0;    // 0xf0 — ctor zero (stp high half)
        uint8_t  mInitf8;       // 0xf8 — member-init call (subobject starts here) (size unknown)
        uint8_t mPadF9[0x7]; // 0xF9 — unproven gap
        uint8_t  mPad100[0xb8];      // 0x100 — unproven gap
        uint64_t mField1b8;   // 0x1b8 — ctor-written
        uint8_t  mZero1c0;    // 0x1c0 — ctor zero
        uint8_t  mPad1c1[0x7];      // 0x1c1 — unproven gap
        uint64_t mZero1c8;    // 0x1c8 — ctor zero
        uint32_t mZero1d0;    // 0x1d0 — ctor zero
        uint8_t  mPad1d4[0x4];      // 0x1d4 — unproven gap
        uint64_t mZero1d8;    // 0x1d8 — ctor zero
        uint64_t mField1e0;   // 0x1e0 — ctor zero (stp high half)
        uint64_t mZero1e8;    // 0x1e8 — ctor zero
        uint64_t mField1f0;   // 0x1f0 — ctor zero (stp high half)
        uint64_t mField1f8;   // 0x1f8 — ctor-written
        uint8_t  mZero200;    // 0x200 — ctor zero
        uint8_t  mPad201[0x7];      // 0x201 — unproven gap
        uint64_t mField208;   // 0x208 — ctor-written
        uint8_t  mZero210;    // 0x210 — ctor zero
        uint8_t  mPad211[0xf];      // 0x211 — unproven gap
        uint64_t mField220;   // 0x220 — ctor-written
        uint64_t mField228;   // 0x228 — ctor-written
        uint64_t mZero230;    // 0x230 — ctor zero
        uint64_t mZero238;    // 0x238 — ctor zero
        uint64_t mZero240;    // 0x240 — ctor zero
        uint64_t mZero248;    // 0x248 — ctor zero
        uint64_t mZero250;    // 0x250 — ctor zero
        uint64_t mZero258;    // 0x258 — ctor zero
        uint64_t mZero260;    // 0x260 — ctor zero
        uint64_t mZero268;    // 0x268 — ctor zero
        uint64_t mZero270;    // 0x270 — ctor zero
        uint64_t mZero278;    // 0x278 — ctor zero
        uint64_t mZero280;    // 0x280 — ctor zero
        uint8_t  mInit288;       // 0x288 — member-init call (subobject starts here) (size unknown)
        uint8_t mPad289[0x7]; // 0x289 — unproven gap
        uint8_t  mPad290[0x10];      // 0x290 — unproven gap
        uint64_t mZero2a0;    // 0x2a0 — ctor zero
    // Object size 0x2a8 (allocation size at the factory new preceding ctor 0xb193bc).
    };
}
