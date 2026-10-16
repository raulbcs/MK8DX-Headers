#pragma once

#include <cstdint>

#include "RaceDirector.hpp"

// RaceDirectorSetLanePool — PROVISIONAL vtable-anchored name. Per-lane
// entry-pool manager of RaceDirectorPlayerSet; ctor 0x71000702e0, vtables
// 0x11b4980 / 0x11b4a00 (+0x38), size 0xA8 (factory alloc 0x6f380).
// Details: doc/gear/Race/RaceDirectorSetLanePool.md

namespace gear {
class RaceDirectorSetLanePool : public Actor {
 public:
  uint8_t pad38[8];     //0x38 - 0x3F — unproven padding
  uint8_t b40;          //0x40 — ctor sets 3 (pool count base)
  uint8_t b41;          //0x41 — ctor zero
  uint8_t b42;          //0x42 — ctor zero
  uint8_t pad43;        //0x43 — unproven padding
  uint32_t m44;         //0x44 — ctor zero
  void* mSelf48;        //0x48 — self pointer
  void* mPool50;        //0x50 — alloc(0x30) entry pool
  void* mPool58;        //0x58 — alloc(0x30)
  void* mPool60;        //0x60 — alloc(0x30)
  uint64_t mZero68;     //0x68 — ctor zero
  void* mOwner70;       //0x70 — ctor arg x1
  uint8_t pad78[0x10];  //0x78 — unproven padding
  uint64_t mCfg88;      //0x88 — *(u64*)[0xf57b7c]
  uint32_t mCfg90;      //0x90 — *(u32*)([0xf57b7c]+8)
  int32_t mMinus1_94;   //0x94 — ctor -1
  uint32_t mZero98;     //0x98
  uint8_t mZer9c[4];    //0x9C — ctor zero
  uint8_t pad_a0[8];    //0xA0 - 0xA7 — unproven padding
  // (0xA8 total)
};
}  // namespace gear
