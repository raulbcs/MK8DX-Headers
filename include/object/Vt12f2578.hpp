#pragma once

#include <cstdint>

// Vt12f2578 — PLACEHOLDER name (singleton-ish manager, multi-inheritance); vptr 0x12f2578, 8 slots,
// typeinfo NULL; GOT cell 0x13150a8 holds vptr-0x10 (str-published by 0xB07F5C/0xB21B7C/0xB41C80).
// size 0x470 (aligned operator new at 0xA84374) - details: doc/object/Vt12f2578.md

namespace object {
class Vt12f2578 {
 public:
  void* mVtable;           // 0x00 — 0x12f2578 (via GOT cell 0x13150a8)
  uint8_t mPad8[0x40];     // 0x08 — unproven (member ctors at 0x60BF28 etc.)
  void* mVtable2;          // 0x48 — secondary vptr (GOT cell 0x1307110 +0x10)
  uint8_t mPad50[0x18];    // 0x50 — unproven
  void* m68;               // 0x68 — sub-object ctor'd at 0x60BF28
  uint8_t mPad70[0x18];    // 0x70 — unproven
  void* m88;               // 0x88 — self ptr (stores this)
  void* mVtable3;          // 0x90 — secondary vptr (GOT cell 0x12FAE28 +0x10)
  uint8_t mPad98[0x60];    // 0x98 — unproven (caller stores tick at [0xF8])
  void* mF8;               // 0xF8 — os tick stored by caller 0xA8434C
  uint8_t mPad100[0x370];  // 0x100 — unproven padding to 0x470
};
}  // namespace object
