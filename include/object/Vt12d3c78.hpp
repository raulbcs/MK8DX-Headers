#pragma once

#include <cstdint>

// Vt12d3c78 — PLACEHOLDER name; vptr 0x12d3c78 (GOT cell 0x1311920, holds vt-0x10), 10-slot table.
// Last sibling block; slot7 is the factory for Vt12d3cc8 objects (new 0x2d0 @0x8a5848).
// extent 0x88 - details: doc/object/Vt12d3c78.md

namespace object {
class Vt12d3c78 {
 public:
  void* mVtable;            // 0x00 — 0x12d3c78 (base installs 0x130d388-family vptr first)
  uint8_t mPad8[0x18];      // 0x08 — unproven (0x6155bc base ctor body)
  void* mField20;           // 0x20 — zeroed by C1
  void* mField28;           // 0x28 — zeroed by C1
  void* mSelf30;            // 0x30 — self-pointer to block base
  void* mField38;           // 0x38 — zeroed by C1
  void* mMember40;          // 0x40 — 0x61cc48-init member (vptr swapped to 0x12fb728-family)
  void* mField48;           // 0x48 — points to +0x54 (member scratch byte)
  uint32_t mField50;        // 0x50 — u32 0x20
  uint8_t mByte54;          // 0x54 — u8 (region-language byte via cell 0x12fada8)
  uint8_t mPad55[0x23];     // 0x55 — unproven
  void* mBuffer78;          // 0x78 — 0x80000-byte allocation (0x8a48c8), set late in C1
  uint32_t mField80;        // 0x80 — u32 zeroed by C1
  uint8_t mPad84[0x4];      // 0x84 — unproven
};
}  // namespace object
