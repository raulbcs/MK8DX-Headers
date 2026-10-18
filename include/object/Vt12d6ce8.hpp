#pragma once

#include <cstdint>

// Vt12d6ce8 — PLACEHOLDER name; layout-control family, factory branch 0x8efc24-0x8efc8c
// (key tail 0xf07226, "TouchDecide2" region). Primary 44 slots; secondary at +0x180.
// extent 0x108 - details: doc/object/Vt12d6ce8.md

namespace object {
class Vt12d6ce8 {
 public:
  void* mVtable;         // 0x00 — 0x12d6ce8 (via GOT cell 0x1311fb8)
  uint8_t mPad8[0x20];   // 0x08 — unproven padding (shared base ctor FUN_7100738d68)
  void* mSubobjPtr;      // 0x28 — pointer to the +0x80 sub-object
  uint8_t mPad30[0x40];  // 0x30 — unproven padding
  uint8_t mByte70;       // 0x70 — zeroed by the factory
  uint8_t mByte71;       // 0x71 — set to 1 by the factory
  uint8_t mPad72[0x6];   // 0x72 — unproven padding
  void* mField78;        // 0x78 — zeroed by the factory
  void* mVtable2;        // 0x80 — 0x12d6ce8+0x180 (13-slot secondary table)
  void* mParent;         // 0x88 — back-pointer to the enclosing object (this)
  uint8_t mPad90[0x78];  // 0x90 — unproven padding
};
}  // namespace object
