#pragma once

#include <cstdint>

#include "gear/Race/RaceDirectorBase38.hpp"

// Naming: no consumers beyond the allocation site 0x820ff0 examined; no binary name evidence (see doc).
namespace gear {
// RaceDirectorVtb5d0 — PROVISIONAL vtable-anchored name (vptr from cell
// 0x1310788; .data 0x12cb5d0). Far-family director, 24 slots; ctor 0x81eacc,
// size 0x880 (alloc 0x820ff0). Details: doc/gear/Race/RaceDirectorVtb5d0.md
class RaceDirectorVtb5d0 : public RaceDirectorBase38 {
 public:
  uint32_t mZero38;           // 0x38 — ctor zero
  uint8_t pad3c[4];           // 0x3c — unproven padding
  uint64_t mZero40;           // 0x40 — ctor zero
  uint64_t mZero48;           // 0x48 — ctor zero
  uint8_t mZero50;            // 0x50 — ctor zero
  uint8_t pad51[7];           // 0x51 — unproven padding
  void* mObj58;               // 0x58 — new 0x98 (ctor 0x81e65c from the 0x61a5f0 singleton); null partner at 0x60
  void* mNull60;              // 0x60 — ctor null
  uint8_t mBig68[0x4d8];      // 0x68 — memset 0x4e8 region minus head (sub-ctor 0x81ec70)
  uint32_t mZero540;          // 0x540 — ctor zero
  uint32_t pad544;            // 0x544 — unproven padding
  uint64_t mZero548;          // 0x548 — ctor zero
  uint32_t mZero550;          // 0x550 — ctor zero
  uint32_t pad554;            // 0x554 — unproven padding
  uint64_t mZero558;          // 0x558 — ctor zero
  uint8_t mSub560[0x40];      // 0x560 — sub-object (ctor 0x628628)
  uint32_t mZero5a0;          // 0x5a0 — ctor zero
  uint8_t mPad5A4[0x4];       // 0x5A4 — unproven gap
  void* mVptr5a8;             // 0x5a8 — cell 0x1310790 (+0x10), vptr-shaped
  void* mSelf5b0;             // 0x5b0 — ctor sets this
  void* mVptr5b8;             // 0x5b8 — cell 0x1310798 (+0x10), vptr-shaped
  uint64_t mZero5c0;          // 0x5c0 — ctor zero
  uint8_t mThread5c8[0x100];  // 0x5c8 — embedded thread (create 0x629270)
  void* mNext6c8;             // 0x6c8 — ctor sets this+0x6e0
  uint64_t mOne6d0;           // 0x6d0 — ctor sets 1
  uint32_t mZero6d8;          // 0x6d8 — ctor zero
  uint8_t mPad6DC[0x104];     // 0x6DC — unproven gap (region unmapped by ctor analysis)
  uint8_t mSub7e0[0x40];      // 0x7e0 — sub-object (ctor 0x628628)
  uint8_t mTail820[0x60];     // 0x820 — memset 0x60
  // (0x880 total)
};
}  // namespace gear
