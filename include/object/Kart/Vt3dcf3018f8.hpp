#pragma once

#include <cstdint>

namespace object
{
    // Vt3dcf3018f8 — PROVISIONAL vtable-anchored name (vptr 0x12b18f8, cell 0x130d758, n=19, site 0x6366f8, ctor 0x6366b0).
    // Member of the 0x3dcf30 family (0x71003dcf30 = vt+0x40 dispatch anchor): nn::ae::AppletThread subclass.
    // Site context: site 0x6366f8 inside FUN_71006366b0 (vtable slots SceneVt00/SceneVt01) — scene-related thread; class name unconfirmed.
    //
    class Vt3dcf3018f8
    {
    public:
        void* vtable;           // 0x00
        uint8_t mPad8[0xf8];    // 0x8 — unproven gap
        uint64_t mField100;     // 0x100 — ctor-written
        uint64_t mField108;     // 0x108 — ctor: call result
        uint32_t mField110;     // 0x110 — ctor-written
        uint32_t mZero114;      // 0x114 — ctor zero
        uint32_t mZero118;      // 0x118 — ctor zero
        uint8_t mPad11c[0x4];   // 0x11c — unproven gap
        uint32_t mZero120;      // 0x120 — ctor zero
        uint8_t mPad124[0x14];  // 0x124 — unproven gap
        uint32_t mZero138;      // 0x138 — ctor zero
        uint8_t mPad13c[0x4];   // 0x13c — unproven gap
        uint64_t mField140;     // 0x140 — ctor: call result
    };
}
