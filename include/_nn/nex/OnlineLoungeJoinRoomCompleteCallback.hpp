#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex36OnlineLoungeJoinRoomCompleteCallbackE).
    // vptr 0x12d7350 (GOT cell 0x1312230, n=19, ctor 0x904610, sole construction site 0x9046b0).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class OnlineLoungeJoinRoomCompleteCallback
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint8_t  mPada0[0x10];      // 0xa0 — unproven gap
        uint64_t mFieldb0;    // 0xb0 — ctor-written
        uint64_t mFieldb8;    // 0xb8 — ctor-written
        uint64_t mFieldc0;    // 0xc0 — ctor-written (stp high half)
        uint8_t  mPadc8[0x8];      // 0xc8 — unproven gap
        uint64_t mFieldd0;    // 0xd0 — ctor-written
        uint8_t  mZerod8;     // 0xd8 — ctor zero
        uint8_t  mPadd9[0xf];      // 0xd9 — unproven gap
        uint64_t mFielde8;    // 0xe8 — ctor-written
        uint64_t mFieldf0;    // 0xf0 — ctor-written (stp high half)
        uint32_t mZerof8;     // 0xf8 — ctor zero
        uint8_t  mPadfc[0xc];      // 0xfc — unproven gap
        uint64_t mField108;   // 0x108 — ctor-written
    // Object size 0x110 (allocation size at the factory new preceding ctor 0x904610).
    };
}
