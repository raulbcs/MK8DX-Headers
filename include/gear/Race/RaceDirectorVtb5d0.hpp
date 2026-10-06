#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

namespace gear
{
    // PROVISIONAL vtable-anchored name. Far-family director, 24 slots; mii::Database calls nearby.
    // Vtable .data 0x12cb5d0, ctor 0x81eacc, size 0x880 (alloc 0x880 at 0x820ff0 before ctor call 0x821004).
    // Base: the root ctor 0x4d7d8 chain (own-field map pending).
    class RaceDirectorVtb5d0 : public RaceDirector
    {
    public:
        char mOwn90[0x7f0];    // 0x90 — own-field region (map pending)
    };
}
