#pragma once

#include <cstdint>

#include "RaceDirectorSetChainMid.hpp"

// RaceDirectorSetChainB — PROVISIONAL vtable-anchored name. Chain variant
// (ctor 0x7100620a0, vtable 0x11b3e48 / GOT 0x12fbe38). Size 0x110 (factory
// alloc 0x6ee28). Seeds a limit of 30 at +0xFC.
namespace gear
{
    class RaceDirectorSetChainB : public RaceDirectorSetChainMid
    {
        public:
            uint32_t mZeroF8;    //0xF8 — ctor zero
            uint32_t mLimit30FC; //0xFC — ctor sets 30 (0x1E)
            uint8_t mZero100[9]; //0x100 - 0x108 — ctor zeroes (+0x104 skipped)
            uint8_t pad109[7];   //0x109
            // (0x110 total)
    };
}
