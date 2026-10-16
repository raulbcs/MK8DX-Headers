#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// RaceListItemGBase — PROVISIONAL vtable-anchored name. Vtable 0x12c8f68
// (GOT cell 0x1310240); PRIMARY BASE of RaceListItemG. Ctor 0x71007ee400;
// extent 0x9b0 of the 0xa10 total. (Out-of-line copy 0x878f94 belongs to
// RaceDirectorVt10's graph.) Details: doc/gear/Race/RaceListItemGBase.md

namespace gear {
class RaceListItemGBase : public RaceDirectorBase38 {
 public:
  uint32_t mField38;       //0x38 — ctor zero
  uint8_t pad3c[4];        //0x3c — unproven padding
  uint64_t mZero40;        //0x40 — ctor zero
  uint64_t mZero48;        //0x48 — ctor zero
  int32_t mFfff50;         //0x50 — ctor sets -1
  uint8_t pad54[4];        //0x54 — unproven padding
  uint64_t mZero58;        //0x58 — ctor zero
  uint64_t mZero60;        //0x60 — ctor zero
  uint64_t mZero68;        //0x68 — ctor zero
  void* mSub70;            //0x70 — embedded member (ctor 0x710061cc48, secondary vptr cell 0x12fada0)
  void* mNode78;           //0x78 — self node head (set to this+0x84)
  uint8_t pad80[4];        //0x80 — unproven padding
  uint8_t mNode84[0x24];   //0x84 — node body reached by the back-ptr
  uint8_t padA8[0x60];     //0xa8 — (to 0x108)
  uint32_t m108;           //0x108 — derived ctor writes 0x80000008 (u64 store covers 0x108..0x10f)
  uint32_t m10c;           //0x10c — derived ctor sets 0xc
  uint32_t m110;           //0x110 — derived ctor sets 4
  uint8_t pad114[4];       //0x114 — unproven padding
  uint8_t mPad118[0x898];  //0x118 — untouched by the ctors (to 0x9b0)
  // (0x9b0 total)
};
}  // namespace gear
