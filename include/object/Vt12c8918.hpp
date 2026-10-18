#pragma once

#include <cstdint>

// Vt12c8918 — PLACEHOLDER name; 14 slots, no RTTI; base C1 0x7e0848 (not gear::Actor).
// C1 0x7e5748 owns two 0x18 heap sub-objects at +0x70/+0x78; D0s at slots 11/12 delete them.
// extent 0x94 (lower bound from field stores; derived allocation is 0x98, unverified) -
// details: doc/object/Vt12c8918.md

namespace object {
class Vt12c8918 {
 public:
  void* mVtable;         // 0x00 — 0x12c8918 (via GOT cell 0x1310188, cell holds vptr-0x10)
  uint8_t mPad8[0x68];   // 0x08 — unproven padding (base C1 0x7e0848 not analyzed)
  void* mSub70;          // 0x70 — new 0x18, ctor'd by 0x8e0004
  void* mSub78;          // 0x78 — new 0x18, ctor'd by 0x8e0004
  uint8_t mPad80[0x10];  // 0x80 — ctor: 0
  uint32_t m90;          // 0x90 — ctor: 0
  uint8_t mPad94[0x4];   // 0x94 — unproven padding (derived Vt12cdcd8 allocated 0x98)
};
}  // namespace object
