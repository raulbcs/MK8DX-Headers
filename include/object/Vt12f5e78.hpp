#pragma once

#include <cstdint>

// Vt12f5e78 — PLACEHOLDER name; vptr 0x12f5e78 (assigned row 0x12f5e70 = typeinfo slot, vt-8).
// n=32; ctor FUN_7100b16948, new(0x130); secondary vptr 0x12f5d90 at +0x98; 0x90-byte member at +0x90.
// extent 0x130 - details: doc/object/Vt12f5e78.md

namespace object {
class Vt12f5e78 {
 public:
  void* mVtable;           // 0x00 — 0x12f5e78 (via GOT cell 0x13158b8, holds vt-8; vptr = cell+0x10)
  uint8_t mPad8[0x88];     // 0x08 — unproven padding
  void* m90;               // 0x90 — new(0x90) member, ctor 0xb16a50 (vt 0x12f5bb0)
  void* mVtable2;          // 0x98 — 0x12f5d90 (GOT cell 0x1315880, addend+0x10; secondary base)
  uint8_t mPadA0[0x90];    // 0xA0 — unproven padding
};


}  // namespace object
