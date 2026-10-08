#pragma once

#include <cstdint>

namespace object {
// ParamContainerVt4aa0 — address-anchored name (vptr 0x12f4aa0, GOT cell
// 0x1315508). Large container of the 0x647f40 hook-band cluster
// (param-cache super-family ring): n=25 slots, allocation
// 0x1680 at site 0xaf527c. Shares the trivial hook band
// 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
// Own fields mapped from the inlined construction at the quoted site
// (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
class ParamContainerVt4aa0 {
 public:
  void* vtable;            // 0x00
  uint8_t mPad8[0x28];     // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];     // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0xe88];   // 0x38 — array/body region — unproven gap
  uint8_t mPadec0[0x20];   // 0xec0 — ctor-zeroed region (0xec0-0xed8 qword-zeroed)
  uint8_t mPadee0[0x798];  // 0xee0 — unproven gap
  uint8_t mPad1678[0x4];   // 0x1678 — ctor-written
  uint8_t mPad167c[0x4];   // 0x167c — tail pad
                           // (0x1680 total, factory alloc)
};
}  // namespace object

// Naming closure: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only). Address-anchored name retained.
