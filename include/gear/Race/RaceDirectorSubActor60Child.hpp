#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSubActor60Child — PROVISIONAL vtable-anchored name. The child
// RaceDirectorSubActor60 creates at +0x60: ctor 0x710066ba8 (base 0x7c0b3c
// -> Actor), vtable 0x11b4348 (GOT 0x12fbf10). Size 0xB0 (alloc inside the
// parent ctor 0x66470-0x6647c). No own fields.
namespace gear
{
    class RaceDirectorSubActor60Child : public Actor
    {
        public:
            uint8_t pad38[0x78]; //0x38 - 0xAF
    };
}
