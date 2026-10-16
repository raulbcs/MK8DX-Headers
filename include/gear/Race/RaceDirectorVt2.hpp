#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// gear::RaceDirectorVt2 — PROVISIONAL vtable-anchored name; mid-level
// base of the derived-director set (vtable 0x11b3098, ctor 0x710004e2f4, size 0xA0).
// Details: doc/gear/Race/RaceDirectorVt2.md

namespace gear {
class RaceDirectorVt2 : public RaceDirector {
 public:
  void* mCtxPtr90;      //0x90 — race-context object (helper 0x7100024e70, ctor 0x4e338)
  uint16_t mU98;        //0x98 — ctor zero; reset by slot 0x100 (0x4e354)
  uint8_t mU9a;         //0x9A — ctor zero; same reset
  uint8_t pad_9B[0x5];  //0x9B — unproven gap (tail pad reused by Vt3-Vt7 at 0x9C; alloc 0xA0)
};
}  // namespace gear
