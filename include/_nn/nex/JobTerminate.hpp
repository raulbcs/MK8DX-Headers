#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex12JobTerminateE).
        uint8_t mPada0[0xa0]; // 0xa0 — unproven gap (object fully constructed by the shared
                              // inline job ctor 0x588b04 at the 0xa43d78 new; no further writes)
    // Object size 0x140 (allocation size at the factory new 0xa43d78, which constructs the
    // JobTerminate inline: shared job ctor 0x588b04 + vptr store from GOT cell 0x1314e00).
    // NOTE: nearby function 0xa43c10 is NOT this class's ctor — it is a manager method whose
    // [x19, #0x1c8] accesses hit the enclosing manager object, not this 0x140-byte job.
    // vptr 0x12e7b68 (GOT cell 0x1314e00, n=13; constructed inline by the factory at 0xa43d78).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobTerminate
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)

    };
}
