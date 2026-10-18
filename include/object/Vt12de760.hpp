#pragma once

#include <cstdint>

// Vt12de760 — PLACEHOLDER name; 5-slot row (installed vptr 0x12de768, typeinfo-
// slot row 0x12de760); ctor 0x99d294 sets vptr + tag 0x1400000000.
// extent 0x30 - details: doc/object/Vt12de760.md

namespace object {
class Vt12de760 {
 public:
  void* mVtable;      // 0x00 — 0x12de768 (GOT cell 0x13139f8 holds 0x12de758 = row-0x8)
  uint64_t mTag8;     // 0x08 — ctor stores constant 0x1400000000
  uint32_t mField10;  // 0x10 — ctor stores 0
  uint8_t mPad14[0x1C];  // 0x14 — pad to alloc size 0x30 (unverified contents)
};
}  // namespace object
