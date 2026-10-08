#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtb0b8 — address-anchored name (vptr 0x12bb0b8, GOT cell
// 0x130e4c0). Large container of the 0x647f40 hook-band cluster
// (param-cache super-family ring): n=28 slots, allocation
// 0x2f0 at site 0x6fc2dc. Shares the trivial hook band
// 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare).
// Own fields mapped from the inlined construction at the quoted site
// (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
// Vtable slot facts (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 10 (0x60): one-time-guarded static singleton getter. Guard cell
//   0x710130e2c0; instance cell 0x710130e2c8 initialised to
//   [0x71012fd3d0]+0x10. true function size 0x5c bytes.
//   [paramContainerVtb0b8StaticInstanceSlot10_71006fae8c.cpp]
// - Slot 14 (0x80): walks the member array backwards from self+0x268 down
//   to self+0x260 (element size *(int*)(self+0x274)). For each member with a
//   non-null pointer at +0x18: obj = [member+0x18]+0x10; ORs 0x80 into the
//   halfword at obj+0xe28; calls the object's vtable slot 23 (0xb8) with
//   (arg1, arg2). true function size 0x98 bytes.
//   [paramContainerVtb0b8NotifyMembersSlot14_71006fa7dc.cpp]
// - Slot 24 (0xd0): pooled object spawn, same shape as
//   ParamContainerVtb1e8 slot 24 but with the pool cell at
//   *(*(x1+0xf0))+0x3fc0: pop from the stack (count +0x8, array +0x10),
//   push into the active ring (head +0x18, cap +0x1c, array +0x20);
//   reinitializes +0x48 = 0xffff, +0x4a = 0, +0x40 = owner (x1), +0x18 = 0,
//   +0x20 = x19 (x1), +0x28 = *x2; registers via FUN_710060b618(self+0x260,
//   *(self+0x274)+obj), bumps *(self+0x270); tail-calls
//   FUN_71006a24e8(x1arg, (short)*x2, obj). true function size 0xb8 bytes.
//   [containerB0b8SpawnSlot24_71006fa934.cpp]
class ParamContainerVtb0b8 {
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
  uint8_t mPad278[0x78];  // 0x278 — unproven gap
                          // (0x2f0 total, factory alloc)
};
}  // namespace object

// Naming closure: container shell of the 0x647f40 hook-band cluster; no ctor strings and no per-class static identity (runtime param id only). Address-anchored name retained.
