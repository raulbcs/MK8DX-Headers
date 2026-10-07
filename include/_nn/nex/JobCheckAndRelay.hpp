#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex16JobCheckAndRelayE).
    // vptr 0x12e3148 (GOT cell 0x13144d8, n=13, ctor 0x9f10e8, sole construction site 0x9f1120).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobCheckAndRelay
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint32_t mFielda0;    // 0xa0 — ctor-written
        uint8_t  mPada4[0x4];      // 0xa4 — unproven gap
        uint64_t mFielda8;    // 0xa8 — ctor-written
        uint8_t  mPadb0[0x4];      // 0xb0 — unproven gap
        uint8_t  mZerob4;     // 0xb4 — ctor zero
        uint8_t  mPadb5[0x3];      // 0xb5 — unproven gap
        uint64_t mZerob8;     // 0xb8 — ctor zero
        uint32_t mZeroc0;     // 0xc0 — ctor zero
        uint8_t  mPadc4[0x4];      // 0xc4 — unproven gap
        uint64_t mFieldc8;    // 0xc8 — ctor-written
        uint64_t mFieldd0;    // 0xd0 — ctor-written (stp high half)
        uint64_t mZerod8;     // 0xd8 — ctor zero
        uint64_t mFielde0;    // 0xe0 — ctor zero (stp high half)
        uint64_t mZeroe8;     // 0xe8 — ctor zero
        uint64_t mFieldf0;    // 0xf0 — ctor zero (stp high half)
        uint64_t mZerof8;     // 0xf8 — ctor zero
        uint8_t  mInit100;       // 0x100 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad108[0x10];      // 0x108 — unproven gap
        uint64_t mZero118;    // 0x118 — ctor zero
        uint32_t mZero120;    // 0x120 — ctor zero
        uint8_t  mPad124[0x4];      // 0x124 — unproven gap
        uint64_t mZero128;    // 0x128 — ctor zero
        uint64_t mField130;   // 0x130 — ctor zero (stp high half)
        uint64_t mZero138;    // 0x138 — ctor zero
        uint8_t  mInit140;       // 0x140 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad148[0x10];      // 0x148 — unproven gap
        uint64_t mField158;   // 0x158 — ctor-written
        uint64_t mField160;   // 0x160 — ctor-written
        uint8_t  mPad168[0x8];      // 0x168 — unproven gap
        uint64_t mField170;   // 0x170 — ctor-written
        uint64_t mField178;   // 0x178 — ctor-written (stp high half)
        uint64_t mZero180;    // 0x180 — ctor zero
        uint64_t mField188;   // 0x188 — ctor zero (stp high half)
        uint64_t mZero190;    // 0x190 — ctor zero
        uint64_t mField198;   // 0x198 — ctor zero (stp high half)
        uint64_t mField1a0;   // 0x1a0 — ctor-written
        uint64_t mField1a8;   // 0x1a8 — ctor-written (stp high half)
        uint64_t mZero1b0;    // 0x1b0 — ctor zero
        uint64_t mField1b8;   // 0x1b8 — ctor zero (stp high half)
        uint16_t mField1c0;   // 0x1c0 — ctor-written
        uint8_t  mZero1c2;    // 0x1c2 — ctor zero
    // Object size 0x1c8 (allocation size at the factory new preceding ctor 0x9f10e8).
    };
}
