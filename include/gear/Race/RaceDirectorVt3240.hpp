#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

namespace gear
{
    // PROVISIONAL vtable-anchored name. Far-family director, 24 slots.
    // Vtable .data 0x1283240, ctor 0x501c54, size 0x138 (alloc 0x138 at 0x398e24 before ctor call 0x398e38).
    // Base: the root ctor 0x4d7d8 chain (own-field map pending).
    class RaceDirectorVt3240 : public RaceDirector
    {
    public:
        char mOwn90[0xa8];    // 0x90 — own-field region (map pending)
    };
}
