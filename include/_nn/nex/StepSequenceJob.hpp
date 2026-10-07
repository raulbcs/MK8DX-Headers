#pragma once

#include <cstdint>

namespace nn::nex
{
    // RTTI-confirmed (typeinfo mangled name: N2nn3nex15StepSequenceJobE).
    // vptr 0x128d060 (GOT cell 0x130b7a8, n=13, ctor 0x588b04, sole construction site 0x588b50).
    // Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
    // secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
    // base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
    class StepSequenceJob
    {
    public:
        void* vtable;          // 0x00
        uint8_t mBase08[0x98]; // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
        uint32_t mFlag08;          // 0x08 — ctor stlr 1 (atomic flag)
        uint8_t  mPad0c[0x4];      // 0x0c — ctor zero
        uint64_t mPtr10;           // 0x10 — ctor zero
        uint64_t mPtr18;           // 0x18 — ctor zero
        uint8_t  mFlag20;          // 0x20 — ctor zero
        uint64_t mPtr28;           // 0x28 — ctor zero
        uint32_t mField30;         // 0x30 — ctor zero
        uint32_t mArg38;           // 0x38 — ctor-written (arg w1)
        uint64_t mPtr40;           // 0x40 — ctor zero
        uint32_t mField48;         // 0x48 — ctor zero
        uint8_t  mPad4c[0x4];      // 0x4c — unproven gap
        uint64_t mPtr50;           // 0x50 — ctor zero
        uint64_t mPtr58;           // 0x58 — ctor zero
        uint8_t  mFlag60;          // 0x60 — ctor zero
        uint8_t  mFlag61;          // 0x61 — ctor 1
        uint64_t mPtr68;           // 0x68 — ctor zero
        uint32_t mField70;         // 0x70 — ctor zero
        uint8_t  mPad74[0x4];      // 0x74 — unproven gap
        uint64_t mVptr78;          // 0x78 — secondary vptr (cell 0x130b798)
        uint64_t mPtr80;           // 0x80 — ctor zero
        uint64_t mPtr88;           // 0x88 — ctor zero
        uint64_t mPtr90;           // 0x90 — ctor zero
        uint64_t mPtr98;           // 0x98 — ctor zero
    // Full layout proven: this class is produced by the shared job base ctor 0x588b04 itself (extent 0xa0).
    };
}
