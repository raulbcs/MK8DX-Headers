#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace object
{
    // Kart speed calculation runtime, "mini core" variant. Vtable .data
    // 0x124d0e8 (GOT cell 0x1306390 region), ctor 0x710034d2d8, size 0x300
    // (allocation 0x300 at 0x34d1ac). Slot names carry
    // KartCalcSpeed_mini_core_710034b558 evidence.
    class KartCalcSpeedMiniCore : public gear::Actor
    {
    public:
        char mOwn38[0x2c8];    // 0x38 — own-field region (map pending)
    };
}
