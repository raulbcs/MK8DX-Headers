#pragma once

#include <cstdint>

#include "RaceDirectorSetChain.hpp"

// RaceDirectorSetChainMid — PROVISIONAL vtable-anchored name. Mid layer
// (ctor 0x7100628bc, vtable 0x11b3fd8 / GOT 0x12fbe50). Size 0xF8 (factory
// alloc 0x6f1d8). Adds zeros at 0xE0-0xEF.
namespace gear
{
    class RaceDirectorSetChainMid : public RaceDirectorSetChain
    {
        public:
            uint8_t padC0[0x20]; //0xC0
            uint32_t mZeroE0;    //0xE0 — ctor zero
            uint32_t mZeroE4;    //0xE4
            uint32_t mZeroE8;    //0xE8
            uint16_t mZeroEc;    //0xEC
            uint8_t mZeroEf;     //0xEF
            uint8_t padF0[8];    //0xF0
            // (0xF8 total)
    };
}
