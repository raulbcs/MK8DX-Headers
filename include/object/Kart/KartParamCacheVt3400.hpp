#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheMid2.hpp"

namespace object {
// KartParamCacheVt3400 — address-anchored name (vptr 0x12b3400,
// GOT cell 0x130dae8; cell holds vt-0x10). Large Mid2-derived cache variant;
// size 0xb80 (operator new at 0x71003d0a4c). Ctor 0x710065df30.
// extent 0xb80 - details: doc/object/Kart/KartParamCacheVt3400.md
class KartParamCacheVt3400 : public KartParamCacheMid2 {
 public:
  void* vptr;                // 0x00 — cell 0x130dae8 + 0x10 (0x65df8c)
  uint8_t mOwn8[0x1c8];      // 0x08 — own-field region (Mid2 covers to 0x1d0)
  void* mList1d0[2];         // 0x1d0 — self-referential pair (stp at 0x65df74)
  uint32_t mZero1e0;         // 0x1e0 — ctor zero
  uint8_t mPad1e4[4];        // 0x1e4 — unproven padding
  void* mList1e8[2];         // 0x1e8 — self-referential pair (0x65df84)
  uint32_t mZero1f8;         // 0x1f8 — ctor zero
  uint8_t mPad1fc[4];        // 0x1fc — unproven padding
  uint8_t mNodes200[0x90];   // 0x200 — 6 intrusive-list heads, stride 0x18
                             // (pairs @0x200/0x218/0x230/0x248/0x260/0x278,
                             // u32 counts @0x210..0x288, all zeroed 0x65df98-0x65dff4)
  uint8_t mSubs290[0x2d8];   // 0x290 — 7 sub-objects ctor 0x7100669954
                             // (vptr cell 0x130d980) @0x290/0x2d8/0x320/0x368/
                             // 0x3b0/0x3f8/0x440, then 0x7100645410 @0x580,
                             // 0x710063ecbc @0x748, 0x710063f778 @0x7b0,
                             // 0x7100692a90 @0x988 (0x65dffc-0x65e078)
  uint8_t mPad568[0x10];     // 0x568 — unproven padding
  uint32_t mField578;        // 0x578 — 29 (0x65e134)
  uint8_t mPad57c[0x43c];    // 0x57c — unproven padding (ctor epilogue zeros
                             // at 0x568/0x570/0x980/0x984)
  uint32_t mField9b8;        // 0x9b8 — 29 (0x65e138)
  uint8_t mPad9bc[0x10];     // 0x9bc — unproven padding
  uint32_t mZero9cc;         // 0x9cc — ctor zero
  uint8_t mFlags9d0;         // 0x9d0 — 1 (0x65e084)
  uint8_t mFlags9d1[2];      // 0x9d1 — zeroed
  uint8_t mPad9d3[5];        // 0x9d3 — unproven padding
  void* mZero9d8;            // 0x9d8 — ctor zero
  char mMember9e0[0x30];     // 0x9e0 — member ctor 0x710066a2a4, vptr cell
                             // 0x130d988 (0x65e09c-0x65e0ac)
  char mChan_a10[0x18];      // 0xa10 — channel-pair member (ctor pair
                             // 0x7100662f30/0x7100662f70, cell 0x130d908)
  uint8_t mFlaga28;          // 0xa28 — 1 (0x65e110)
  uint8_t mTaila29[0x157];   // 0xa29 — tail region (ctor 0x71006611bc @0xa30
                             // with -1; name-table call 0x7100689f00 w/
                             // string 0xef9ab9; unverified)
};
}  // namespace object
