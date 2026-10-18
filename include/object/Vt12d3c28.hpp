#pragma once

#include <cstdint>

// Vt12d3c28 — PLACEHOLDER name; vptr 0x12d3c28 (GOT cell 0x1311908, holds vt-0x10), 10-slot table.
// Sibling of Vt12d3548/Vt12d3c78; constructed inline by C1 FUN_71008a4490 at outer+0x3c0.
// extent 0x78 - details: doc/object/Vt12d3c28.md

namespace object {
class Vt12d3c28 {
 public:
  void* mVtable;            // 0x00 — 0x12d3c28 (base installs 0x130d388-family vptr first)
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
};
}  // namespace object
