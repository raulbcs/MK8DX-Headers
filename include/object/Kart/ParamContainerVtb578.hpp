#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtb578 — address-anchored name (vptr 0x12bb578, GOT cell
// 0x130e498). Large container of the 0x647f40 hook-band cluster
// (param-cache super-family ring): n=25 slots, allocation
// 0x1678 at site 0x6fbdfc. Shares the trivial hook band
// 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare; compare 0x7100647f6c (paramNodeSharedTypeIdEquals) is slot 0x50 shared by 61 ParamNode vtables).
// Own fields mapped from the inlined construction at the quoted site
// (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
// Vtable slot facts (evidence TU under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 10 (0x60): guard-protected static singleton getter. Guard cell
//   0x710130e4a0; instance cell 0x710130e4a8 initialised to
//   [0x7101305868]+0x10. true function size 0x60 bytes (gap-split artifact).
//   [paramContainerVtb578StaticInstanceSlot10_71006fbf64.cpp]
class ParamContainerVtb578 {
 public:
  void* vtable;            // 0x00
  uint8_t mPad8[0x28];     // 0x8 — unproven gap (pre-secondary-base)
  uint8_t mPad30[0x8];     // 0x30 — secondary hook-band vptr (ctor-written)
  uint8_t mPad38[0x1640];  // 0x38 — array/body region — unproven gap
                           // (0x1678 total, factory alloc)
};
}  // namespace object

// Naming closure: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only). Address-anchored name retained.
