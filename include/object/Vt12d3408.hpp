#pragma once

#include <cstdint>

// Vt12d3408 — PLACEHOLDER name; vptr 0x12d3408 (GOT cell 0x13117a0, holds vt-0x10), typeinfo NULL.
// C1 0x896ba4, D2 0x896cd4; heap object proven: operator new(0x2d0) at 0x3d8e0c.
// extent 0x2d0 - details: doc/object/Vt12d3408.md

namespace object {
class Vt12d3408 {
 public:
  void* mVtable;            // 0x00 — 0x12d3408 (primary, 8 slots)
  uint8_t mPad8[0x18];      // 0x08 — unproven
  uint8_t mPad28[0x18];     // 0x28 — unproven
  void* mVtable20;          // 0x20 — 0x12d3458 MI secondary (offset-to-top -0x20 @0x12d3448)
  void* mVtable40;          // 0x40 — 0x12d34b8 embedded member primary (ot row 0)
  uint8_t mPad48[0x20];     // 0x48 — unproven
  void* mMember68;          // 0x68 — 0x61cc48-init member (vptr 0x12fada0-family, u32 0x100 @+0x10)
  uint8_t mPad70[0xa8];     // 0x70 — unproven (member spans to +0x118)
  void* mMember118;         // 0x118 — second 0x61cc48-init member
  void* mField120;          // 0x120 — member back-ptr
  uint8_t mPad128[0x1a0];   // 0x128 — unproven (ctor zeroes 0x230..0x258, cell read 0x1308248)
  uint8_t mByte2c8;         // 0x2c8 — u8 zeroed by factories (0x8a5860 and callers)
  uint8_t mPad2c9[0x7];     // 0x2c9 — unproven
};
}  // namespace object
