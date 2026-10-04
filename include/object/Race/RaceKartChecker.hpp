#pragma once

#include "RaceCheckerBase.hpp"

namespace object
{
    // One instance per kart (init 0x710087ffd0). Recorder channel
    // "RaceKartChecker" (rodata 0xf0cccc), channel data names
    // mRank/mLap/mCoinNum. Vtable .data 0x12d0c48:
    //   0x20 0x710007a26c  0x28 0x71008814fc  0x30 0x7100881508
    //   0x70 0x71008802f4 (enter body)  0xb8 0x7100881514 (calc body)
    class RaceKartChecker : public RaceCheckerBase
    {
    public:
        // enter tail-jumps slot 0x70 (0x71008802f4): resets 0x3c-0x50 and
        // stamps time records at 0x48 and 0x54-0x74.
        // calc tail-jumps slot 0xb8 (0x7100881514): walks the race-info
        // singleton ([+0x190]->[+0x58]: count@0x40, base@0x48, stride 0x78,
        // lapTotal byte@0x64) by kart index; mLap is compared to lapTotal.

        uint8_t mFlags3c;      // 0x3c — bit 2 checked by calc
        uint32_t mField40;     // 0x40 — reset on enter, gets kart index
        uint32_t mLap;         // 0x44 — compared against lapTotal

        // Time record {u32 id, u8 minutes, u8 seconds, u16 millis}, built
        // by 0x7100888c30 (explicit) / 0x7100888c70 (from millis).
        uint32_t mTimeId48;    // 0x48
        uint8_t mTimeMin4c;    // 0x4c
        uint8_t mTimeSec4d;    // 0x4d
        uint16_t mTimeMs4e;    // 0x4e
        uint32_t mField50;     // 0x50 — reset on enter
        uint8_t mPad51[3];     // 0x51
        uint64_t mTime[7];     // 0x54 — seven time records (0x54..0x84)
        uint16_t mField8c;     // 0x8c — zeroed on enter
        uint8_t mPad8e[0xe];   // 0x8e
        uint64_t mField9c;     // 0x9c — zeroed on enter
        uint64_t mFieldA4;     // 0xa4 — zeroed on enter
        uint64_t mFieldAc;     // 0xac — zeroed on enter
        void* mRecorderChannel; // 0x90
        uint8_t mFlag98;       // 0x98
        uint8_t mFlag99;       // 0x99 — zero skips the calc walk
        char mPad9a[0x126];    // 0x9a
        uint32_t mRecorderId1c0; // 0x1c0
        uint32_t mRecorderId1c4; // 0x1c4
        char mPad1c8[0x40];    // 0x1c8
        const char* mName;     // 0x208 — "RaceKartChecker"
        char mPad210[0x20];    // 0x210
        void* mField230;       // 0x230
        char mPad238[0x40];    // 0x238
        void* mField278;       // 0x278
    };
}
