#pragma once

#include <cstdint>

#include "gear/Actor/Actor.hpp"

namespace gear {
// RaceDirector-family director (slot4 SharedThunk_30vtables_710004cfbc).
// Vtable .data 0x12d0a60, ctor 0x710087d9b8, 0x168 bytes (alloc 0x398964).
// Details: doc/gear/Race/RaceDirectorVt8.md
class RaceDirectorVt8 : public Actor {
 public:
  uint32_t mField38;  // 0x38 — zeroed on ctor
  uint8_t mPad3c[4];  // 0x3c — unproven padding
  char mPad40[0x40];  // 0x40 — zeroed on ctor (to 0x80)
  char mPad80[0x68];  // 0x80 — untouched by ctor (to 0xe8)

  // {u32 id, u8 min, u8 sec, u16 ms} time record (builder 0x888c30); ctor builds (9, 59, 999)
  uint32_t mTimeId_e8;  // 0xe8
  uint8_t mTimeMin_ec;  // 0xec
  uint8_t mTimeSec_ed;  // 0xed
  uint16_t mTimeMs_ee;  // 0xee
  uint64_t mPadF0;      // 0xf0 — untouched by ctor

  // 0xf8..0x168 — three 0x28-byte recorder channel descriptors (cells are GOT
  // addresses): 0xf8 vt 0x1311090 / fn 0x12fae28 / name "" / vt2 0x13110a0 /
  // owner this; 0x120 vt 0x1311098 / 0x128 0 / 0x130 0x1311098; 0x148 vt
  // 0x13110a0 / 0x150 owner this / 0x158 fn / 0x160 0
  void* mChanF8;         // 0xf8
  void* mChan100;        // 0x100 — fn (cell 0x12fae28)
  const char* mChan108;  // 0x108 — ""
  void* mChan110;        // 0x110
  void* mChan118;        // 0x118 — owner back-ptr = this
  void* mChan120;        // 0x120
  void* mChan128;        // 0x128 — 0
  void* mChan130;        // 0x130
  void* mChan138;        // 0x138 — fn
  const char* mChan140;  // 0x140 — ""
  void* mChan148;        // 0x148
  void* mChan150;        // 0x150 — owner back-ptr = this
  void* mChan158;        // 0x158 — fn
  void* mChan160;        // 0x160 — 0
                         // extent 0x168 (ctor 0x710087D9B8 stores reach 0x168)
  uint8_t mGap108[8];    // 0x108 — unproven gap
  uint8_t mGap140[8];    // 0x140 — unproven gap
};
}  // namespace gear
