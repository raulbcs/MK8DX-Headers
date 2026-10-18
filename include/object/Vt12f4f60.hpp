#pragma once

#include <cstdint>

// Vt12f4f60 — PLACEHOLDER name; vptr 0x12f4f60, 8 slots, typeinfo NULL; GOT cell 0x13155d0 holds
// vptr-0x10 (single install site: inline stack construction in FUN_7100B03F70 at 0xB04050).
// extent 0xa0 - lower bound (no heap alloc found) - details: doc/object/Vt12f4f60.md

namespace object {
class Vt12f4f60 {
 public:
  void* mVtable;         // 0x00 — 0x12f4f60 (via GOT cell 0x13155d0)
  uint8_t mPad8[0x70];   // 0x08 — unproven
  void* m78;             // 0x78 — sub-object destroyed by D1 (0x6232FC)
  uint8_t mPad80[0x18];  // 0x80 — unproven
  uint8_t m98;           // 0x98 — flag set to 1 by D1 (0xB04978)
  uint8_t mPad99[0x7];   // 0x99 — unproven padding
};
}  // namespace object
