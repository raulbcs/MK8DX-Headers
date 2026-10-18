#pragma once

#include <cstdint>

// Vt12d6700 — PLACEHOLDER name; layout-control family, factory branch 0x8ef8d4-0x8ef91c
// (key "TouchOn2" @0xf0720a). Primary 44 slots; secondary 13-slot table at +0x180.
// extent 0xf8 - details: doc/object/Vt12d6700.md

namespace object {
class Vt12d6700 {
 public:
  void* mVtable;         // 0x00 — 0x12d6700 (via GOT cell 0x1311f98)
  uint8_t mPad8[0x20];   // 0x08 — unproven padding (shared base ctor FUN_7100738d68)
  void* mSubobjPtr;      // 0x28 — pointer to the +0x70 sub-object
  uint8_t mPad30[0x12];  // 0x30 — unproven padding
  uint16_t mFlags42;     // 0x42 — state halfword, OR'd with 0x20 by the factory
  uint8_t mPad44[0x2C];  // 0x44 — unproven padding
  void* mVtable2;        // 0x70 — 0x12d6700+0x180 (13-slot secondary table)
  void* mParent;         // 0x78 — back-pointer to the enclosing object (this)
  uint8_t mPad80[0x78];  // 0x80 — unproven padding
};
}  // namespace object
