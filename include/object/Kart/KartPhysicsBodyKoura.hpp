#pragma once

#include "KartPhysicsBodyMid.hpp"

namespace object
{
    // Koura (shell) physics body. Vtable .data 0x11b0d98 (GOT cell
    // 0x12fb828), ctor 0x710030d50(w1 = item id ptr), allocation 0x460
    // (operator new at 0x35f10). Slot names carry ItemKoura_* evidence.
    //
    // TogezoBomb (vtable 0x11b0898, n=128) derives from this class — its
    // inlined ctor calls 0x30d50.
    //
    // Ctor own-field writes (after the KartPhysicsBodyMid base ctor):
    // secondary vptr at 0x390, byte flags 0x398-0x39b, u32 0x39c, zeros
    // 0x3a0-0x3c0, u16/u32 cluster 0x3c0-0x3d2, u64 0x3f8.
    class KartPhysicsBodyKoura : public KartPhysicsBodyMid
    {
    public:
        void* mSecVt390;       // 0x390 — secondary vtable (GOT cell +0x10)
        uint8_t mFlag398;      // 0x398 — zeroed on ctor
        uint8_t mFlag399;      // 0x399 — zeroed on ctor
        uint8_t mFlag39a;      // 0x39a — zeroed on ctor
        uint8_t mFlag39b;      // 0x39b — zeroed on ctor
        uint32_t mField39c;    // 0x39c — zeroed on ctor
        uint64_t mField3a0;    // 0x3a0 — zeroed on ctor
        uint64_t mField3a8;    // 0x3a8 — zeroed on ctor
        uint64_t mField3b0;    // 0x3b0 — zeroed on ctor
        uint64_t mField3b8;    // 0x3b8 — zeroed on ctor
        uint32_t mField3c0;    // 0x3c0 — zeroed on ctor
        uint16_t mField3c4;    // 0x3c4 — zeroed on ctor
        char mPad3c6[6];       // 0x3c6
        uint16_t mField3cc;    // 0x3cc
        uint16_t mField3ce;    // 0x3ce
        uint16_t mField3d0;    // 0x3d0
        uint16_t mField3d2;    // 0x3d2
        char mPad3d4[0x24];    // 0x3d4
        uint64_t mField3f8;    // 0x3f8
        char mPad400[0x60];    // 0x400 — to end (0x460)
    };
}
