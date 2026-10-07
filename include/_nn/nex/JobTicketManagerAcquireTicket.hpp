#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex29JobTicketManagerAcquireTicketE).
    // vptr 0x12e6a88 (GOT cell 0x1314b70, n=13, ctor 0xa32e08, sole construction site 0xa32e4c).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobTicketManagerAcquireTicket
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint32_t mFielda0;    // 0xa0 — ctor-written
        uint8_t  mPada4[0x4];      // 0xa4 — unproven gap
        uint64_t mFielda8;    // 0xa8 — ctor-written
        uint64_t mFieldb0;    // 0xb0 — ctor-written (stp high half)
        uint64_t mFieldb8;    // 0xb8 — ctor-written
        uint64_t mFieldc0;    // 0xc0 — ctor-written (stp high half)
        uint8_t  mInitc8;       // 0xc8 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPadd0[0xb8];      // 0xd0 — unproven gap
        uint64_t mField188;   // 0x188 — ctor-written
        uint8_t  mPad190[0x4];      // 0x190 — unproven gap
        uint8_t  mZero194;    // 0x194 — ctor zero
        uint8_t  mPad195[0x2b];      // 0x195 — unproven gap
        uint8_t  mInit1c0;       // 0x1c0 — member-init call (subobject starts here) (size unknown)
    // Object size 0xb0 (allocation size at the factory new preceding ctor 0xa32e08).
    };
}
