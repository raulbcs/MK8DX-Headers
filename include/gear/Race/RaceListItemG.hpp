#pragma once

#include <cstdint>

// RaceListItemG — PROVISIONAL vtable-anchored name ("G"). Manager list item
// of the far race family (base chain 0x7ee400, NOT Actor). Vtable
// 0x11b9650 (GOT 0x12fcfe8). Ctor 0x710010adec; size 0xA10, proven by the
// allocation site 0x71003989cc. Registers into manager+0x218.
namespace gear
{
    class RaceListItemG
    {
        public:
            uint8_t pad00[8];    //0x00 — vtable ptr
            uint8_t pad08[0xf8]; //0x08
            uint32_t m108;       //0x108 — ctor sets 8
            uint32_t m10c;       //0x10C — ctor sets 0xC
            uint32_t m110;       //0x110 — ctor sets 4
            uint8_t pad114[0x89c];//0x114
            uint8_t zero9b0[0x48]; //0x9B0 — ctor memset 0x48
            uint8_t pad9f8[0x8]; //0x9F8
            int32_t m9c8;        //0x9C8 — ctor -1
            uint8_t pad9cc[0xc]; //0x9CC
            int32_t m9d8;        //0x9D8 — ctor -1
            uint8_t pad9dc[0xc]; //0x9DC
            int32_t m9e8;        //0x9E8 — ctor -1
            uint8_t pad9ec[0xc]; //0x9EC
            int32_t m9f8;        //0x9F8 — ctor -1
            uint8_t pad9fc[8];   //0x9FC
            uint32_t mA00;       //0xA00 — ctor zero
            uint8_t mA04[4];     //0xA04
            uint8_t bA08;        //0xA08 — ctor zero
            uint8_t padA09[7];   //0xA09
            // (0xA10 total)
    };
}
