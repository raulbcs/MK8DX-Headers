#pragma once

#include <cstdint>

namespace gear
{
    // Global per-race lap state. RaceKartChecker::calc compares the kart lap
    // counter against mLapTotal (byte at +0x64).
    //
    // A recorder channel named "LapRankChecker" (rodata 0xf0ccf0) is created
    // by the race-checker init 0x710087ffd0 for it (channel subclass vtable
    // .data 0x12d0f60, base slots 0x71007ab904/0x71007abca8/0x71007ac1d8 in
    // the recorder region).
    class LapRankChecker
    {
    public:
        uint8_t mPad00[0x64];
        uint8_t mLapTotal;
    };
}
