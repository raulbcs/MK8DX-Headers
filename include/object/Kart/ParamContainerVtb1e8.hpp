#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtb1e8 — address-anchored name (vptr 0x12bb1e8, GOT cell
// 0x130e4c8). Large container of the 0x647f40 hook-band cluster
// (param-cache super-family ring): n=28 slots, allocation
// 0x2f0 at site 0x6fc4d4. Shares the trivial hook band
// 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
// Own fields mapped from the inlined construction at the quoted site
// (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
class ParamContainerVtb1e8 {
 public:
  void* vtable;           // 0x00
  uint8_t mPad8[0x28];    // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];    // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0x228];  // 0x38 — array/body region — unproven gap
  uint8_t mPad260[0x8];   // 0x260 — ctor-zeroed pair (0x260/0x268)
  uint8_t mPad268[0x4];   // 0x268 — unproven gap
  uint8_t mPad26c[0x4];   // 0x26c — unproven gap
  uint8_t mPad270[0x4];   // 0x270 — ctor-zero (param)
  uint8_t mPad274[0x4];   // 0x274 — ctor-written (param w22)
  uint8_t mPad278[0x18];  // 0x278 — unproven gap
  uint8_t mPad290[0x4];   // 0x290 — ctor-written (param w22)
  uint8_t mPad294[0x4];   // 0x294 — unproven gap
  uint8_t mPad298[0x8];   // 0x298 — ptr — ctor-written
  uint8_t mPad2a0[0x10];  // 0x2a0 — unproven gap
  uint8_t mPad2b0[0xc];   // 0x2b0 — 3x w32 — ctor-written (0x2b0/0x2b4/0x2b8)
  uint8_t mPad2bc[0x4];   // 0x2bc — unproven gap
  uint8_t mPad2c0[0x8];   // 0x2c0 — ptr — ctor-written
  uint8_t mPad2c8[0x10];  // 0x2c8 — unproven gap
  uint8_t mPad2d8[0xc];   // 0x2d8 — 3x w32 — ctor-written (0x2d8/0x2dc/0x2e0)
  uint8_t mPad2e4[0x4];   // 0x2e4 — unproven gap
  uint8_t mPad2e8[0x8];   // 0x2e8 — ctor-zero
                          // (0x2f0 total, factory alloc)
};
}  // namespace object

// Naming closure: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only). Address-anchored name retained.
