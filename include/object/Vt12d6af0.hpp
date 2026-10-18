#pragma once

#include <cstdint>

// Vt12d6af0 — PLACEHOLDER name; layout-control family, factory branch 0x8efbe0-0x8efc20
// (key tail 0xf07219, "TouchOff2" region). Primary 44 slots; secondary table at +0x180.
// extent 0xf8 - details: doc/object/Vt12d6af0.md

namespace object {
class Vt12d6af0 {
 public:
  void* mVtable;         // 0x00 — 0x12d6af0 (via GOT cell 0x1311fb0)
  uint8_t mPad8[0x20];   // 0x08 — unproven padding (shared base ctor FUN_7100738d68)
  void* mSubobjPtr;      // 0x28 — pointer to the +0x70 sub-object
  uint8_t mPad30[0x40];  // 0x30 — unproven padding
  void* mVtable2;        // 0x70 — 0x12d6af0+0x180 (13-slot secondary table)
  void* mParent;         // 0x78 — back-pointer to the enclosing object (this)
  uint8_t mPad80[0x78];  // 0x80 — unproven padding
};
}  // namespace object
