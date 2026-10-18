#pragma once

#include <cstdint>

// Vt12b18f8 — PLACEHOLDER name (no RTTI; typeinfo slot 0x12b18f0 = 0).
// Timer/CS + growable 8-byte-element array holder; 18 fn slots.
// extent 0x178 - details: doc/object/Vt12b18f8.md

namespace object {
class Vt12b18f8 {
 public:
  void* mVtable;           // 0x00 - 0x12b18f8 (GOT cell 0x130d758 = vptr-0x10)
  uint8_t mPad8[0xec];     // 0x08 - base subobject (init 0x7100628a54);
                           //   unproven gap
  uint8_t mZeroF4[0x4c];   // 0xf4 - zeroed by C1 (0xf4..0x138, incl. u32
                           //   stores at 0xf4/0xf8/0x118/0x120/0x128-0x138)
  uint64_t m140;           // 0x140 - os tick (GetSystemTick at C1 0x7100636720)
  uint8_t mCs148[0x8];     // 0x148 - embedded critical section
                           //   (init 0x710062875c w1=1, dtor 0x71006287b4)
  uint8_t mPad150[0x28];   // 0x150 - array new(n*8) via 0x710060b3fc region;
                           //   exact slot unverified
};
}  // namespace object
