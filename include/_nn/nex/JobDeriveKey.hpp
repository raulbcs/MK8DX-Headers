#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex12JobDeriveKeyE).
    // vptr 0x128c9a8 (GOT cell 0x130b700, n=12, ctor 0x582648, sole construction site 0x5826d0).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobDeriveKey
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint8_t  mZeroa0;     // 0xa0 — ctor zero
        uint8_t  mZeroa1;     // 0xa1 — ctor zero
        uint8_t  mZeroa2;     // 0xa2 — ctor zero
        uint8_t  mPada3[0x11];      // 0xa3 — unproven gap
        uint8_t  mZerob4;     // 0xb4 — ctor zero
        uint8_t  mPadb5[0x3];      // 0xb5 — unproven gap
        uint64_t mFieldb8;    // 0xb8 — ctor-written
        uint64_t mZeroc0;     // 0xc0 — ctor zero
        uint64_t mFieldc8;    // 0xc8 — ctor zero (stp high half)
        uint64_t mZerod0;     // 0xd0 — ctor zero
        uint8_t  mZerod8;     // 0xd8 — ctor zero
        uint8_t  mZerod9;     // 0xd9 — ctor zero
        uint8_t  mZeroda;     // 0xda — ctor zero
        uint8_t  mPaddb[0x5];      // 0xdb — unproven gap
        uint64_t mZeroe0;     // 0xe0 — ctor zero
        uint64_t mFielde8;    // 0xe8 — ctor zero (stp high half)
        uint64_t mFieldf0;    // 0xf0 — ctor-written
    // Object size unknown (factory function 0x582648 performs no direct allocation).
    };
}
