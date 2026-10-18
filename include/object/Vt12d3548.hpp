#pragma once

#include <cstdint>

// Vt12d3548 — PLACEHOLDER name; vptr 0x12d3548 (GOT cell 0x13117c8, holds vt-0x10), 215-slot table.
// Derived from the 0x6155bc base family; constructed inline by C1 FUN_71008a4490 (0x8a4590).
// extent 0x78 - details: doc/object/Vt12d3548.md

namespace object {
class Vt12d3548 {
 public:
  void* mVtable;            // 0x00 — 0x12d3548 (base installs 0x130d388-family vptr first)
  uint8_t mPad8[0x18];      // 0x08 — unproven (0x6155bc base ctor body)
  void* mField20;           // 0x20 — zeroed by C1
  void* mField28;           // 0x28 — zeroed by C1
  void* mSelf30;            // 0x30 — self-pointer to block base
  void* mField38;           // 0x38 — zeroed by C1
  void* mMember40;          // 0x40 — 0x61cc48-init member (vptr 0x12fada0-family, swapped to 0x12fb728-family)
  void* mField48;           // 0x48 — points to +0x54 (member scratch byte)
  uint32_t mField50;        // 0x50 — u32 0x20
  uint8_t mByte54;          // 0x54 — u8 (region-language byte via cell 0x12fada8)
  uint8_t mPad55[0x23];     // 0x55 — unproven
};
}  // namespace object
