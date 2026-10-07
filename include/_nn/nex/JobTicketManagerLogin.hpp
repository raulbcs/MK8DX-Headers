#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex21JobTicketManagerLoginE).
    // vptr 0x12e6b00 (GOT cell 0x1314ba8, n=13, ctor 0xa343d0, sole construction site 0xa34424).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class JobTicketManagerLogin
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint32_t mFielda0;    // 0xa0 — ctor-written
        uint8_t  mPada4[0x4];      // 0xa4 — unproven gap
        uint64_t mFielda8;    // 0xa8 — ctor-written
        uint64_t mFieldb0;    // 0xb0 — ctor-written (stp high half)
        uint8_t  mPadb8[0x4];      // 0xb8 — unproven gap
        uint8_t  mZerobc;     // 0xbc — ctor zero
        uint8_t  mPadbd[0x3];      // 0xbd — unproven gap
        uint64_t mZeroc0;     // 0xc0 — ctor zero
        uint32_t mZeroc8;     // 0xc8 — ctor zero
        uint8_t  mPadcc[0x4];      // 0xcc — unproven gap
        uint64_t mFieldd0;    // 0xd0 — ctor-written
        uint64_t mFieldd8;    // 0xd8 — ctor-written (stp high half)
        uint64_t mZeroe0;     // 0xe0 — ctor zero
        uint64_t mFielde8;    // 0xe8 — ctor zero (stp high half)
        uint64_t mZerof0;     // 0xf0 — ctor zero
        uint64_t mFieldf8;    // 0xf8 — ctor zero (stp high half)
        uint64_t mZero100;    // 0x100 — ctor zero
        uint8_t  mInit108;       // 0x108 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad110[0x10];      // 0x110 — unproven gap
        uint64_t mZero120;    // 0x120 — ctor zero
        uint32_t mZero128;    // 0x128 — ctor zero
        uint8_t  mPad12c[0x4];      // 0x12c — unproven gap
        uint64_t mZero130;    // 0x130 — ctor zero
        uint64_t mField138;   // 0x138 — ctor zero (stp high half)
        uint8_t  mInit140;       // 0x140 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad148[0x20];      // 0x148 — unproven gap
        uint8_t  mInit168;       // 0x168 — member-init call (subobject starts here) (size unknown)
        uint8_t  mZero170;    // 0x170 — ctor zero
        uint8_t  mPad171[0xf];      // 0x171 — unproven gap
        uint64_t mField180;   // 0x180 — ctor-written
        uint64_t mField188;   // 0x188 — ctor-written (stp high half)
        uint64_t mField190;   // 0x190 — ctor-written
        uint8_t  mPad198[0x8];      // 0x198 — unproven gap
        uint64_t mField1a0;   // 0x1a0 — ctor-written
        uint64_t mField1a8;   // 0x1a8 — ctor-written (stp high half)
        uint64_t mField1b0;   // 0x1b0 — ctor-written
        uint8_t  mInit1b8;       // 0x1b8 — member-init call (subobject starts here) (size unknown)
        uint8_t  mPad1c0[0xb8];      // 0x1c0 — unproven gap
        uint64_t mField278;   // 0x278 — ctor-written
        uint8_t  mPad280[0x4];      // 0x280 — unproven gap
        uint8_t  mZero284;    // 0x284 — ctor zero
        uint8_t  mPad285[0x2b];      // 0x285 — unproven gap
        uint64_t mField2b0;   // 0x2b0 — ctor-written
        uint8_t  mInit2b8;       // 0x2b8 — member-init call (subobject starts here) (size unknown)
        uint8_t  mZero2c0;    // 0x2c0 — ctor zero
        uint8_t  mPad2c1[0xf];      // 0x2c1 — unproven gap
        uint64_t mField2d0;   // 0x2d0 — ctor-written
        uint64_t mField2d8;   // 0x2d8 — ctor-written
        uint64_t mField2e0;   // 0x2e0 — ctor-written
    // Object size 0x2e8 (allocation size at the factory new preceding ctor 0xa343d0).
    };
}
