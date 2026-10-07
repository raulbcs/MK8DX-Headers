#pragma once

#include <cstdint>

#include <gear/Ghost/RaceTime.hpp>
#include <prim/seadSafeString.h>

namespace gear
{
    class PlayerInfo
    {
    public:
        // Unproven — Switch ctor not identified (no RTTI, stripped binary);
        // extent fixed by mCountry at 0x70.
        uint8_t mPad00[0x70]; // unproven - extent fixed by mCountry at 0x70
        uint8_t mCountry[2]; // 0x70
        uint8_t mPad72[0x5E]; // 0x72 — unproven padding
        char16_t mPlayerName[21]; // 0xD0
        uint8_t mPadFA[0x06]; // 0xFA — unproven padding

    };
}