#pragma once

#include <cstdint>

// Vt12d3cc8 — PLACEHOLDER name; vptr 0x12d3cc8 (GOT cell 0x1311948, holds vt-0x10), 25-row table.
// Derived variant of the Vt12d3408 0x2d0 class; slots are ICF clones of the shared D1/D2 bodies.
// extent 0x2d0 - details: doc/object/Vt12d3cc8.md

namespace object {
class Vt12d3cc8 {
 public:
  void* mVtable;            // 0x00 — 0x12d3cc8 (primary, 8 slots; D1/D2/deleting clones)
  uint8_t mPad8[0x18];      // 0x08 — unproven
  uint8_t mPad28[0x18];     // 0x28 — unproven
  void* mVtable20;          // 0x20 — 0x12d3d18 MI secondary (offset-to-top -0x20 @0x12d3d08)
  void* mVtable40;          // 0x40 — 0x12d3d38 embedded member primary (ot row 0)
  uint8_t mPad48[0x20];     // 0x48 — unproven
  void* mMember68;          // 0x68 — 0x61cc48-init member (shared body 0x3d87c8)
  uint8_t mPad70[0xa8];     // 0x70 — unproven
  void* mMember118;         // 0x118 — second 0x61cc48-init member
  void* mField120;          // 0x120 — member back-ptr
  uint8_t mPad128[0x1a0];   // 0x128 — unproven (ctor zeroes 0x230..0x258)
  uint8_t mByte2c8;         // 0x2c8 — u8 zeroed by factories
  uint8_t mPad2c9[0x7];     // 0x2c9 — unproven
};
}  // namespace object
