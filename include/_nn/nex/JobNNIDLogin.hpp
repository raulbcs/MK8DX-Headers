#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex12JobNNIDLoginE).
    // vptr 0x12e7af0 (GOT cell 0x1314dd0, n=13, ctor 0xa205c0, sole construction site 0xa205f4).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobNNIDLogin
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint8_t  mPada0[0xf0];      // 0xa0 — unproven gap
        uint64_t mZero190;    // 0x190 — ctor zero
        uint8_t  mPad198[0x8];      // 0x198 — unproven gap
        uint8_t  mInit1a0;       // 0x1a0 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad1a8[0x58];      // 0x1a8 — unproven gap
        uint8_t  mField200;   // 0x200 — ctor-written
    // Object size 0x78 (allocation size at the factory new preceding ctor 0xa205c0).
    };
}
