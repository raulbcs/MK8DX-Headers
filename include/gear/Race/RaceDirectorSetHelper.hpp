#pragma once

#include <cstdint>

// RaceDirectorSetHelper — PROVISIONAL vtable-anchored name. 0x40-byte
// helper bound to RaceDirectorPlayerSet: ctor 0x7100689c8 (minimal base
// 0x7c2920), vtable 0x11b4408 (GOT 0x12fbf40). Stored at set+0x50.
namespace gear
{
    class RaceDirectorSetHelper
    {
        public:
            uint8_t pad00[0x10]; //0x00 — vtable ptr at +0x00; ctor zeroes 0x10/0x18
            uint8_t pad18[8];    //0x18
            void* mOwner20;      //0x20 — ctor arg x1 (the PlayerSet); +0x28 zero
            uint32_t mZero30;    //0x30
            uint32_t mZero38;    //0x38
    };
}
