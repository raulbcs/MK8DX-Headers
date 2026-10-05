#pragma once

#include <cstdint>

// RaceListItemF — PROVISIONAL vtable-anchored name ("F"). Manager list item
// of the far race family (same wiring pattern as D/E; base chain 0x7d5450,
// NOT Actor). Vtable 0x11b8ab8 (GOT 0x12fcca8). Ctor 0x7100c9e04; size 0x198,
// proven by the allocation site 0x71003de7c4. Note: its typeinfo cell is
// unreliable (points at unrelated code).
namespace gear
{
    class RaceListItemF
    {
        public:
            void* vtable;        //0x00 — vtable ptr
            uint8_t pad08[0x17c];//0x08 - 0x183
            uint32_t mZero184;   //0x184 — ctor zero
            uint32_t mZero188;   //0x188 — ctor zero
            uint32_t m21c190;    //0x190 — ctor sets 0x21C
            uint32_t mZero194;   //0x194 — ctor zero
            // (0x198 total)
    };
}
