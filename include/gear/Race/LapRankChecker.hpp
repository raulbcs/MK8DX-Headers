#pragma once

#include <cstdint>

namespace gear {
// LapRankChecker — global per-race lap state; RaceKartChecker::calc compares
// the kart lap counter against mLapTotal (byte at +0x64). Recorder channel
// "LapRankChecker" created by race-checker init 0x710087ffd0.
// Details: doc/gear/Race/LapRankChecker.md
class LapRankChecker {
 public:
  // Unproven (0x00..0x63) — the enclosing RaceKartChecker ctor is not
  // yet located (no RTTI, stripped binary); extent fixed by the proven
  // mLapTotal byte at 0x64 (compared by RaceKartChecker::calc).
  uint8_t mPad00[0x64];  // unproven 0x00..0x63 - extent fixed by proven
                         // mLapTotal at 0x64
  uint8_t mLapTotal;

  void adaptCurrentSector(int, bool);
};
}  // namespace gear
