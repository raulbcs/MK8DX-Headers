#pragma once

#include <cstdint>
#include <gear/Race/RaceKartInfo.hpp>
#include <gear/Player/PlayerInfo.hpp>

#include <prim/seadSafeString.h>

namespace gear {
class SaveDataGhostListBase {
 public:
  struct Data {
    RaceKartInfo mKartInfo;                // 0x00
    RaceTime mTotalTime;                   // 0x1C
    RaceTime mLapTime[7];                  // 0x24
    int32_t mCourseId;                     // 0x5C
    char16_t mPlayerName[11];              // 0x60
    uint8_t mPad76[2];                     // 0x76
    uint8_t mCountryId[4];                 // 0x78
    uint8_t mHandle;                       // 0x7C
    uint8_t mPad7D[3];                     // 0x7D
    sead::FixedSafeString<256> mFileName;  // 0x80
    uint8_t mPad184[4];                    // 0x18C
    // NOTE (2026-10-09): the on-disk trial record block (CTR0) also stores
    // the collected COIN COUNT (runtime-confirmed via the replay UI); the
    // exact field offset inside CTR0 was not isolated statically. Any
    // simulator/imported ghost must carry it. TA coin rules:
    // FUN_710087c9b4 zeroes coins when RaceInfo+8 ∈ {TimeAttack, Battle};
    // start coins from table 0x7100F6F384; live mCoinNum mirror at
    // vehicle+0x184 (checker chain RaceSystem+0x1B0 → +0x218 → +0x68 →
    // idx*8 → +0x50).

    Data() {}
  };
};
}  // namespace gear
