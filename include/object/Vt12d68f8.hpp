#pragma once

#include <cstdint>

// Vt12d68f8 — PLACEHOLDER name; layout-control family, factory branch 0x8efa7c-0x8efac4
// (ctor FUN_710073b040, sub-object at +0x90). Primary 44 slots; secondary table at +0x180.
// extent 0x118 - details: doc/object/Vt12d68f8.md

namespace object {
class Vt12d68f8 {
 public:
  void* mVtable;         // 0x00 — 0x12d68f8 (via GOT cell 0x1311fa8)
  uint8_t mPad8[0x20];   // 0x08 — unproven padding (ctor FUN_710073b040)
  void* mSubobjPtr;      // 0x28 — pointer to the +0x90 sub-object
  uint8_t mPad30[0x60];  // 0x30 — unproven padding
  void* mVtable2;        // 0x90 — 0x12d68f8+0x180 (13-slot secondary table)
  void* mParent;         // 0x98 — back-pointer to the enclosing object (this)
  uint8_t mPadA0[0x78];  // 0xa0 — unproven padding
};
}  // namespace object
