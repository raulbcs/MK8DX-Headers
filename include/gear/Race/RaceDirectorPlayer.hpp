#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorPlayer — PROVISIONAL vtable-anchored name ("P"). Per-player
// director: vtable 0x11b4a40 (GOT 0x12fc060), ctor 0x7100070cb4, size 0x2B0
// (allocation site 0x7100058c60). Constructed in a loop by
// RaceDirectorManager (one per player, w1 = player index), registered in
// the manager's child array and vector. Owns the per-player director-set
// factory (RaceDirectorPlayerSet) at +0x50. The ctor's first call
// (0x7c2a90) is the primary base RaceDirectorPlayerBase (vtable 0x12c5a88,
// size 0x58 — see RaceDirectorPlayerBase.hpp); this ctor overwrites the
// vptr at 0 and starts its own fields at 0x58.
// Baptism audit: one-per-player construction loop in RaceDirectorManager (0x58c60 news 0x2B0); behavior is clear, a binary name is not. MethodTree has no entry.
// the ELF carries no name for this class (strings and the method-tree
// registrations at 0x6327a8 cover only graphics/profiling and the
// MapObjBase::calc*-family entries; custom-RTTI predicates hold no name
// string), so the name stays PROVISIONAL.

namespace gear {
struct RaceDirectorPlayerSet;  // RaceDirectorPlayerSet.hpp

class RaceDirectorPlayer : public Actor {
 public:
  uint8_t pad38[0x18];            //0x38 — child array pattern (count=1)
  RaceDirectorPlayerSet* mSet50;  //0x50 — new(0xD0), ctor 0x6eb5c (0x70eac)
  void* mObj58;                   //0x58 — new(0x38) named object (vptrs 0x11b4bf8 /
  // 0x11ad210; string 0x7100ed6af8, cb 0x70f9c)
  void* mParent60;    //0x60 — ctor arg x2 (the RaceDirectorManager)
  void* mPtr68;       //0x68 — [[set+0xb0]+0x60]
  void* mRaceInfo70;  //0x70 — RaceInfo walk: [0x7f7ac0]->[+0x190+idx*8,
  // clamp<0xa]->[+0x218]->[+0x58]
  void* mRaceCheck78;  //0x78 — if getRaceCheckManager[+8]==3:
  // 0x24e70(playerIdx) race-check object
  uint8_t pad80[8];     //0x80 - 0x87 — unproven padding
  void* mObj88;         //0x88 — alloc(0x60) + ctor 0x14186c(playerIdx)
  void* mObj90;         //0x90 — 0x142498 result
  uint8_t pad98[0x10];  //0x98 — unproven padding
  uint32_t mA8;         //0xA8 — ctor sets 2
  uint8_t padAc[8];     //0xAC - 0xB3 — unproven padding
  int32_t mB4;          //0xB4 — ctor sets -1
  uint8_t padB8[8];     //0xB8 - 0xBF — unproven padding
  int32_t mBC;          //0xBC — ctor sets -1
  uint32_t mC4;         //0xC4 — ctor zero
  int32_t mC8;          //0xC8 — ctor -1; final vcall on parent slot 0xc8 (w1=0xc)
  int32_t mCc;          //0xCC — ctor -1
  int32_t mD0;          //0xD0 — ctor sets 1000
  uint8_t padD4[0x14];  //0xD4 — unproven padding
  uint8_t mE8;          //0xE8 — ctor sets 30
  uint8_t padE9[7];     //0xE9 — unproven padding
  uint8_t padF0[8];     //0xF0 — unproven padding
  // +0xf8/+0x118/+0x12c: self-referencing member heads (ctor 0x70d40/0x70d64)
  uint8_t mF8[0x134];    //0xF8 - 0x22B
  uint32_t mCell22c;     //0x22C — copied from the [0x12fb148] global pair
  uint16_t mFfff230;     //0x230 — ctor 0xFFFF
  uint16_t mFfff232;     //0x232 — ctor 0xFFFF
  uint16_t mZero234;     //0x234
  uint8_t pad236[0x62];  //0x236 — unproven padding
  uint32_t mZero298;     //0x298 — ctor zero
  uint32_t mCell29c;     //0x29C — copied from the [0x12fb148] global pair
  uint8_t pad2a0[0x10];  //0x2A0 — unproven padding
  // (0x2B0 total)
};
}  // namespace gear
