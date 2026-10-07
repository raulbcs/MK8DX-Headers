#pragma once

#include <cstdint>
#include <gear/Race/RaceKartInfo.hpp>
#include <gear/Player/PlayerInfo.hpp>

namespace gear
{
    class Player
    {
    public:
        // Unproven — Switch ctor not identified (no RTTI, stripped binary);
        // extent fixed by mKartInfo at 0x210.
        uint8_t mPad00[0x210]; // unproven - extent fixed by mKartInfo at 0x210
        RaceKartInfo mKartInfo;

        void setPlayerInfoFromOther(gear::PlayerInfo const&,bool,bool);
    };
}