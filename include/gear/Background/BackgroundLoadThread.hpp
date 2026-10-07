#pragma once

#include <cstdint>
#include <gear/Resource/Race/ResourceRaceCommon.hpp>
#include <gear/Race/RaceInfo.hpp>

namespace gear
{
    class BackgroundLoadThread
    {
    public:
        // Unproven — Switch ctor not identified (no RTTI, stripped binary);
        // extent fixed by mResourceRaceCommon at 0x4B58. Consistent with the
        // 0x4B58 in-place constructor offsets seen in the v400 loader loop.
        uint8_t mPad00[0x4B58];
        ResourceRaceCommon mResourceRaceCommon; // 0x4B58
        uint8_t mPad4CA8[0x44]; // 0x4CA8
        RaceInfo mRaceInfo; // 0x4CEC
    };
}