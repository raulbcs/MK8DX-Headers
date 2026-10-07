#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex15SocketTransport12TransportJobE).
    // True nesting: nn::nex::SocketTransport::TransportJob.
    // vptr 0x12e4af8 (GOT cell 0x13146a0, n=12, ctor 0x9fd034, sole construction site 0x9fd19c).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class SocketTransportJob
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint8_t  mPada0[0x210];      // 0xa0 — unproven gap
        uint64_t mField2b0;   // 0x2b0 — ctor-written
        uint64_t mField2b8;   // 0x2b8 — ctor-written
        uint8_t  mPad2c0[0x250];      // 0x2c0 — unproven gap
        uint64_t mField510;   // 0x510 — ctor-written
    // Object size 0x58 (allocation size at the factory new preceding ctor 0x9fd034).
    };
}
