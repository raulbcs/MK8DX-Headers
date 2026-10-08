#pragma once

#include <cstdint>

namespace object {
// ParamContainerVt4920 — address-anchored name (vptr 0x12f4920, GOT cell
// 0x1315500). Large container of the 0x647f40 hook-band cluster
// (param-cache super-family ring): n=38 slots, allocation
// 0x1680 at site 0xaf51f8. Shares the trivial hook band
// 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
// Own fields mapped from the inlined construction at the quoted site
// (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
// Vtable slot facts (evidence TU under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 10 (0x60): guard-initialised static vtable getter. On first call
//   stores descriptor cell 0x710130e518 (+0x10) into cache cell
//   0x710130e520 (guard byte 0x710130e510) and returns the cached pointer.
//   true function size 0x60 bytes. [vt4920VtGetterSlot10_7100af4a90.cpp]
class ParamContainerVt4920 {
 public:
  void* vtable;            // 0x00
  uint8_t mPad8[0x28];     // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];     // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0xe88];   // 0x38 — array/body region — unproven gap
  uint8_t mPadec0[0x20];   // 0xec0 — ctor-zeroed region (0xec0-0xed8 qword-zeroed)
  uint8_t mPadee0[0x798];  // 0xee0 — unproven gap
  uint8_t mPad1678[0x4];   // 0x1678 — ctor-written (param pass-through)
  uint8_t mPad167c[0x4];   // 0x167c — tail pad
                           // (0x1680 total, factory alloc)
};
}  // namespace object

// Naming closure: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only). Address-anchored name retained.
