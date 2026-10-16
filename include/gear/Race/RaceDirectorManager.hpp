#pragma once

#include <cstdint>

// gear::RaceDirectorManager — PROVISIONAL vtable-anchored name.
// Vtable 0x11b3808, ctor 0x710005876c, size 0x1A0 (alloc 0x710013d994).
// Details: doc/gear/Race/RaceDirectorManager.md

namespace gear {
class RaceDirectorManager {
 public:
  void* vtable;             //0x00 — vtable ptr (ctor 0x5879c)
  void* mObj8;              //0x08 — object built by 0x62ee28
  uint8_t pad10[0x40];      //0x10 — unproven padding
  void* mTable50;           //0x50 — new(0x59C0) via ctor 0x66940 (0x58bd4)
  uint32_t mVec58lo;        //0x58 — per-player director vector (loop 0x58c44-0x58cd8)
  uint32_t mVec5c;          //0x5C — vector bound (loaded from [this+0x5C])
  void* mVec60;             //0x60 — vector end/cap
  uint8_t pad68[0x28];      //0x68 — unproven padding
  void* mObj90;             //0x90 — ctor writes (0x588c0 region)
  uint8_t pad98[0x14];      //0x98 — unproven padding (slot-0x98 dispatch region)
  uint32_t mFieldAc;        //0xAC — ctor writes
  uint8_t padB0[0x10];      //0xB0 — unproven padding
  uint8_t mTablesC0[0xd8];  //0xC0 - 0x197 — unproven gap (~14 arrays, ctor 0x58d7c-0x59244)
  uint8_t pad198[8];        //0x198 — unproven padding (0x1A0 total)
};
}  // namespace gear
