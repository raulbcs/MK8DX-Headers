#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

namespace gear
{
    // PROVISIONAL vtable-anchored name. Far-family director, 30 slots; ctor also called from the 0x8bcxxx race region.
    // Vtable .data 0x12c7e38, ctor 0x7d5450, size 0x180 (alloc 0x180 at 0x8bc7a8 before ctor call 0x8bc7bc).
    // Base: the root ctor 0x4d7d8 chain (own-field map pending).
    class RaceDirectorVt7e38 : public RaceDirector
    {
    public:
        char mOwn90[0xf0];    // 0x90 — own-field region (map pending)
    };
}
