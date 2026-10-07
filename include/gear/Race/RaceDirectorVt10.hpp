#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace gear
{
    // RaceDirector-family director that overrides prepare/enter (slots
    // 0x20-0x30 range) while keeping the shared calc/render/exit/isDirector/
    // accept hooks. Vtable .data 0x12d08a8 (GOT cell 0x1311070), ctor
    // 0x7100878ecc, 0x238 bytes (allocation 0x8bc884: operator
    // new[](0x238, nothrow); back-ptr at +0x18 stored by the creator in the
    // 0x8bcxxx race region).
    //
    // Ctor field writes: 0x38 = 0 (u32); 0x40/0x48/0x50/0x58 = 0; block
    // inits via 0x60b918(x0, 0x10, x0+0x10) at 0x50 and 0xe8; 0x90 = 0;
    // -1 words at 0x9c/0xa4/0xac; bytes 0x114 = 0 / 0x115 = 1; zeros
    // 0x118-0x120. The 0x60..0x124 interior is structured (two 0x10-stride
    // init blocks) but only the scalar writes below are ctor-proven.
    class RaceDirectorVt10 : public Actor
    {
    public:
        uint32_t mField38;     // 0x38 — zeroed on ctor
        uint8_t mPad3c[4];     // 0x3c — unproven padding
        uint64_t mField40;     // 0x40 — zeroed on ctor
        uint64_t mField48;     // 0x48 — zeroed on ctor
        uint64_t mField50;     // 0x50 — zeroed on ctor
        uint64_t mField58;     // 0x58 — zeroed on ctor
        char mPad60[0x30];     // 0x60 — 0x10-stride init block (0x60b918)
        uint32_t mField90;     // 0x90 — zeroed on ctor
        char mPad94[8];        // 0x94 — unproven padding
        int32_t mField9c;      // 0x9c — -1 on ctor
        char mPadA0[4];        // 0xa0 — unproven padding
        int32_t mFieldA4;      // 0xa4 — -1 on ctor
        char mPadA8[4];        // 0xa8 — unproven padding
        int32_t mFieldAc;      // 0xac — -1 on ctor
        char mPadB0[0x64];     // 0xb0 — unproven padding
        uint8_t mFlag114;      // 0x114 — 0 on ctor
        uint8_t mFlag115;      // 0x115 — 1 on ctor
        char mPad116[2];       // 0x116 — unproven padding
        uint32_t mField118;    // 0x118 — zeroed on ctor
        uint32_t mField11c;    // 0x11c — zeroed on ctor
        uint32_t mField120;    // 0x120 — zeroed on ctor
        char mPad124[0x114];   // 0x124 — to end (0x238)
    };
}
