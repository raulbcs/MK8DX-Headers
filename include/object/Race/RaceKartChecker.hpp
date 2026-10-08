#pragma once

#include "RaceCheckerBase.hpp"

namespace object {
// One instance per kart. Vtable .data 0x12d0c48 (GOT cell 0x13110d0);
// ctor 0x710087ffd0 (allocation 0xb8 at 0x3a2008/0x87e2e0/0x87e354:
// operator new[](0xb8, nothrow)). Recorder channel "RaceKartChecker"
// (rodata 0xf0cccc) — the ctor builds the 0x280 recorder::Binder
// channel object and stores it at +0x90.
//
// Vtable: 0x20 0x710007a26c  0x28 0x71008814fc (enter fwd)
//   0x30 0x7100881508 (calc fwd)  0x70 0x71008802f4 (enter body)
//   0xb8 0x7100881514 (calc body)
class RaceKartChecker : public RaceCheckerBase {
 public:
  // enter tail-jumps slot 0x70 (0x71008802f4): resets 0x3c-0x50 and
  // stamps time records at 0x48 and 0x54-0x74.
  // calc tail-jumps slot 0xb8 (0x7100881514): walks the race-info
  // singleton ([+0x190]->[+0x58]: count@0x40, base@0x48, stride 0x78,
  // lapTotal byte@0x64) by kart index; mLap is compared to lapTotal.

  uint16_t mFlags3c;  // 0x3c — zeroed on ctor/enter; bit 2 checked by calc
  uint16_t mPad3e;    // 0x3e — unproven padding
  uint32_t mField40;  // 0x40 — ctor stores 1; reset on enter, gets kart index
  uint32_t mLap;      // 0x44 — compared against lapTotal

  // Time record {u32 id, u8 minutes, u8 seconds, u16 millis}, built
  // by 0x7100888c30 (explicit) / 0x7100888c70 (from millis; writes
  // the {min, sec, ms} tail at +4). The ctor stamps record 0 at 0x48
  // and the seven records of mTime with (9, 59, 999); the id word is
  // left to enter. NOTE: records start at 0x54 (4 mod 8) — 4-byte
  // aligned, NOT uint64_t.
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
};
}  // namespace object
