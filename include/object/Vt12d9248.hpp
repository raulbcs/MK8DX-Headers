#pragma once

#include <cstdint>

// Vt12d9248 — PLACEHOLDER name (no RTTI; typeinfo slot 0x12d9240 = 0). Base
// class of Vt12d9310 (derived C1 0x924d10 only overrides the vptr). 20 slots.
// extent 0xe8 - details: doc/object/Vt12d9248.md

namespace object {
class Vt12d9248 {
 public:
  void* mVtable;          // 0x00 - 0x12d9248 (GOT cell 0x1312740 = vptr-0x10)
  uint8_t mPad8[0x8];     // 0x08 - unproven gap
  uint8_t m10;            // 0x10 - zeroed by C1
  uint8_t mPad11[0x7];    // 0x11 - unproven gap
  uint8_t mSub18[0x40];   // 0x18 - subobject initialized by 0x7100628628
                          //   (size unknown, unproven gap)
  uint16_t m58;           // 0x58 - zeroed by C1
  uint8_t mPad5a[0x2];    // 0x5a - unproven padding
  uint32_t m5c;           // 0x5c - set to 1 by C1
  void* m60;              // 0x60 - zeroed by C1
  void* m68;              // 0x68 - zeroed by C1
  void* m70[2];           // 0x70 - ptr pair (both = same sentinel by C1)
  void* m80[5];           // 0x80 - C1 links: +0x80 pair {+0x88,+0x90},
                          //   +0x90 pair {+0x98,+0xa0}; then 0x710060b918
  uint8_t mPadA8[0x28];   // 0xa8 - unproven gap
  uint8_t mZeroD0[0x18];  // 0xd0 - zeroed by derived C1 0x7100924d10
};
}  // namespace object
