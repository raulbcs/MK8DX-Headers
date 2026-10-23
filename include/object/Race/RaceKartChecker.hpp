#pragma once

#include "RaceStateChecker.hpp"

// RaceKartChecker — one instance per kart; vtable .data 0x12d0c48 (GOT
// 0x13110d0); ctor 0x710087ffd0 (new[](0xb8) at 0x3a2008/0x87e2e0/0x87e354).
// extent 0xb8 (operator new[](0xb8) at 0x3a2008/0x87e2e0/0x87e354)

namespace object {
class RaceKartChecker : public RaceStateChecker {
 public:
  // enter body 0x71008802f4 (slot 0x70); calc body 0x7100881514 (slot 0xb8).

  // Shadows RaceStateChecker::mRaceState — per-kart instances store the kart
  // index here (0..11), not the race state.
  uint32_t mKartIndex;  // 0x38
  uint16_t mFlags3c;  // 0x3c — zeroed on ctor/enter; bit 2 checked by calc
  uint16_t mPad3e;    // 0x3e — unproven padding
  uint32_t mField40;  // 0x40 — ctor stores 1; reset on enter, gets kart index
  uint32_t mLap;      // 0x44 — compared against lapTotal

  // TimeRecord {u32 id, u8 min, u8 sec, u16 ms}; built by 0x7100888c30 /
  // 0x7100888c70. Records start at 0x54 (4-byte aligned, NOT uint64_t).
  struct TimeRecord {
    uint32_t id;      // +0
    uint8_t minutes;  // +4
    uint8_t seconds;  // +5
    uint16_t millis;  // +6
  };

  uint32_t mTimeId48;   // 0x48 — record 0 id
  uint8_t mTimeMin4c;   // 0x4c
  uint8_t mTimeSec4d;   // 0x4d
  uint16_t mTimeMs4e;   // 0x4e
  uint32_t mPad50;      // 0x50 — zeroed on ctor (pre-index store)
  TimeRecord mTime[7];  // 0x54 — records 1..7 (0x54..0x8c)
  uint16_t mField8c;    // 0x8c — zeroed on ctor/enter
  uint16_t mPad8e;      // 0x8e — unproven padding

  void* mRecorderChannel;  // 0x90 — recorder::Binder built by the ctor
  uint16_t mFlags98;       // 0x98 — zeroed on ctor/enter; byte 0x99 zero
                           // skips the calc walk (read at 0x881c44)

  char mPad9a[0x1e];  // 0x9a — to end of object (0xb8)

  // Calc body 0x7100881514 (slot 0xB8) and TA calc slot 0xC0: doc/
  // object/Race/RaceKartChecker.md.
};
}  // namespace object
