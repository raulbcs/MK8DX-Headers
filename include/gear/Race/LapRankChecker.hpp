#pragma once

#include <cstdint>

namespace gear {
// Global per-race lap state. RaceKartChecker::calc compares the kart lap
// counter against mLapTotal (byte at +0x64).
//
// A recorder channel named "LapRankChecker" (rodata 0xf0ccf0) is created
// by the race-checker init 0x710087ffd0 for it (channel subclass vtable
// .data 0x12d0f60, base slots 0x71007ab904/0x71007abca8/0x71007ac1d8 in
// the recorder region).
class LapRankChecker {
 public:
  // Unproven (0x00..0x63) — the enclosing RaceKartChecker ctor is not
  // yet located (no RTTI, stripped binary); extent fixed by the proven
  // mLapTotal byte at 0x64 (compared by RaceKartChecker::calc).
  uint8_t mPad00[0x64];  // unproven 0x00..0x63 - extent fixed by proven mLapTotal at 0x64
  uint8_t mLapTotal;
};
}  // namespace gear
