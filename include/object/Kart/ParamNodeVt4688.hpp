#pragma once

#include <cstdint>

namespace object
{
    // ParamNodeVt4688 — PROVISIONAL vtable-anchored name (vptr 0x12f4688, cell 0x13154e0, n=25, site 0x9343f0, ctor 0x93426c).
    // Node class of the 0x647f40 hook-band cluster (shared trivial band
    // 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
    // [this+0x1c]).
    class ParamNodeVt4688
    {
    public:
        void* vtable;            // 0x00
        uint8_t mPad8[0xc];      // 0x8 — unproven gap
        uint32_t mField14;       // 0x14 — ctor-written
        uint32_t mField18;       // 0x18 — ctor-written
        uint8_t mPad1c[0x9ae];   // 0x1c — unproven gap
        uint8_t mField9ca;       // 0x9ca — ctor-written
        uint8_t mField9cb;       // 0x9cb — ctor-written
        uint32_t mField9cc;      // 0x9cc — ctor-written
        uint32_t mField9d0;      // 0x9d0 — ctor-written
        uint32_t mField9d4;      // 0x9d4 — ctor-written
        uint32_t mField9d8;      // 0x9d8 — ctor-written
        uint32_t mField9dc;      // 0x9dc — ctor-written
        uint8_t mPad9e0[0x28];   // 0x9e0 — unproven gap
        uint8_t mFielda08;       // 0xa08 — ctor-written
        uint8_t mPada09[0xb];    // 0xa09 — unproven gap
        uint32_t mFielda14;      // 0xa14 — ctor-written
        uint16_t mFielda18;      // 0xa18 — ctor-written
        uint16_t mFielda1a;      // 0xa1a — ctor-written
        uint16_t mFielda1c;      // 0xa1c — ctor-written
        uint16_t mFielda1e;      // 0xa1e — ctor-written
        uint8_t mFielda20;       // 0xa20 — ctor-written
        uint8_t mFielda21;       // 0xa21 — ctor-written
        uint8_t mPada22[0xc6];   // 0xa22 — unproven gap
        uint64_t mFieldae8;      // 0xae8 — ctor-written
        uint32_t mFieldaf0;      // 0xaf0 — ctor-written
        uint8_t mPadaf4[0x4];    // 0xaf4 — unproven gap
        uint64_t mFieldaf8;      // 0xaf8 — ctor-written
        uint32_t mFieldb00;      // 0xb00 — ctor-written
        uint8_t mPadb04[0x4];    // 0xb04 — unproven gap
        uint64_t mFieldb08;      // 0xb08 — ctor-written
        uint32_t mFieldb10;      // 0xb10 — ctor-written
        uint8_t mPadb14[0x204];  // 0xb14 — unproven gap
        uint32_t mFieldd18;      // 0xd18 — ctor-written
    };
}
