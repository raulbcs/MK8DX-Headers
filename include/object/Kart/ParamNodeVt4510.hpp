#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVt4510 — address-anchored name (vptr 0x12f4510, cell 0x13154d8, n=22, site 0xaef788, ctor 0xaef760).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    class ParamNodeVt4510
    {
    public:
        void* vtable;            // 0x00
        uint8_t mPad8[0x28];     // 0x8 — unproven gap
        uint64_t mField30;       // 0x30 — ctor-written
        uint8_t mPad38[0xd8];    // 0x38 — unproven gap
        uint32_t mZero110;       // 0x110 — ctor zero
        uint8_t mPad114[0x1c];   // 0x114 — unproven gap
        uint64_t mField130;      // 0x130 — ctor-written
        uint64_t mField138;      // 0x138 — ctor-written
        uint32_t mField140;      // 0x140 — ctor-written
        uint8_t mPad144[0x24];   // 0x144 — unproven gap
        uint32_t mField168;      // 0x168 — ctor-written
        uint8_t mPad16c[0xc84];  // 0x16c — unproven gap
        uint32_t mFielddf0;      // 0xdf0 — ctor-written
        uint32_t mFielddf4;      // 0xdf4 — ctor-written
        uint32_t mFielddf8;      // 0xdf8 — ctor-written
        uint32_t mFielddfc;      // 0xdfc — ctor-written
        uint32_t mFielde00;      // 0xe00 — ctor-written
        uint32_t mFielde04;      // 0xe04 — ctor-written
        uint32_t mFielde08;      // 0xe08 — ctor-written
        uint32_t mFielde0c;      // 0xe0c — ctor-written
        uint32_t mFielde10;      // 0xe10 — ctor-written
        uint32_t mFielde14;      // 0xe14 — ctor-written
        uint32_t mFielde18;      // 0xe18 — ctor-written
        uint32_t mFielde1c;      // 0xe1c — ctor-written
        uint64_t mZeroe20;       // 0xe20 — ctor zero
        uint16_t mPade28;        // 0xe28 — ctor zero
        uint8_t mPade2a[0x6];    // 0xe2a — unproven gap
        uint64_t mFielde30;      // 0xe30 — ctor-written
        uint64_t mFielde38;      // 0xe38 — ctor-written
        uint32_t mFielde40;      // 0xe40 — ctor-written
        uint8_t mPade44[0x24];   // 0xe44 — unproven gap
        uint64_t mFielde68;      // 0xe68 — ctor-written
        uint64_t mFielde70;      // 0xe70 — ctor-written
        uint32_t mFielde78;      // 0xe78 — ctor-written
    };
}

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
