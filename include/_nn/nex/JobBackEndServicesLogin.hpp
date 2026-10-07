#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex23JobBackEndServicesLoginE).
    // vptr 0x12e6cd0 (GOT cell 0x1314c28, n=13, ctor 0xa39964, sole construction site 0xa399d0).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobBackEndServicesLogin
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint32_t mFielda0;    // 0xa0 — ctor-written
        uint8_t  mPada4[0xc];      // 0xa4 — unproven gap
        uint8_t  mZerob0;     // 0xb0 — ctor zero
        uint8_t  mPadb1[0xf];      // 0xb1 — unproven gap
        uint64_t mFieldc0;    // 0xc0 — ctor-written
        uint64_t mFieldc8;    // 0xc8 — ctor-written (stp high half)
        uint64_t mFieldd0;    // 0xd0 — ctor-written
        uint8_t  mPadd8[0x3e0];      // 0xd8 — unproven gap
        uint64_t mField4b8;   // 0x4b8 — ctor-written
        uint64_t mField4c0;   // 0x4c0 — ctor-written
        uint8_t  mInit4c8;       // 0x4c8 — member-init call (subobject starts here) (size unknown)
        uint8_t mPad4C9[0x7]; // 0x4C9 — unproven gap
        uint8_t  mPad4d0[0x30];      // 0x4d0 — unproven gap
        uint64_t mZero500;    // 0x500 — ctor zero
        uint64_t mField508;   // 0x508 — ctor-written
        uint64_t mField510;   // 0x510 — ctor-written
        uint64_t mField518;   // 0x518 — ctor-written
    // Object size 0x520 (allocation size at the factory new preceding ctor 0xa39964).
    };
}
