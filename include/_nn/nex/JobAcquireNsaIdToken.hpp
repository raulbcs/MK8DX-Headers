#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex20JobAcquireNsaIdTokenE).
    // vptr 0x12e7c78 (GOT cell 0x1314e28, n=14, ctor 0xa44e08, sole construction site 0xa44e64).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobAcquireNsaIdToken
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint32_t mZeroa0;     // 0xa0 — ctor zero
        uint8_t  mPada4[0x4];      // 0xa4 — unproven gap
        uint8_t  mInita8;       // 0xa8 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPadb0[0x18];      // 0xb0 — unproven gap
        uint8_t  mZeroc8;     // 0xc8 — ctor zero
        uint8_t  mPadc9[0x2f];      // 0xc9 — unproven gap
        uint8_t  mZerof8;     // 0xf8 — ctor zero
        uint8_t  mPadf9[0x7];      // 0xf9 — unproven gap
        uint32_t mZero100;    // 0x100 — ctor zero
        uint8_t  mPad104[0x4];      // 0x104 — unproven gap
        uint8_t  mInit108;       // 0x108 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad110[0x20];      // 0x110 — unproven gap
        uint64_t mZero130;    // 0x130 — ctor zero
        uint64_t mField138;   // 0x138 — ctor zero (stp high half)
        uint64_t mZero140;    // 0x140 — ctor zero
        uint64_t mField148;   // 0x148 — ctor zero (stp high half)
    // Object size 0x150 (allocation size at the factory new preceding ctor 0xa44e08).
    };
}
