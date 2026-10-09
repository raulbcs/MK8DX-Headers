#pragma once

#include <cstdint>

namespace object {
// ParamContainerVtb1e8 — address-anchored name (vptr 0x12bb1e8, GOT cell
// 0x130e4c8). Large container of the 0x647f40 hook-band cluster
// (param-cache super-family ring): n=28 slots, allocation
// 0x2f0 at site 0x6fc4d4. Shares the trivial hook band
// 0x647f40-0x647f6c (return-1/ret/slot-0x78 thunk/ID compare; compare 0x7100647f6c (paramNodeSharedTypeIdEquals) is slot 0x50 shared by 61 ParamNode vtables).
// Own fields mapped from the inlined construction at the quoted site
// (vptr stores at +0x0/+0x30, tail count block); interior array region unproven.
// Vtable slot facts (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 10 (0x60): one-time-guarded static singleton getter. Guard cell
//   0x7101305880; instance cell 0x7101305888 initialised to
//   [0x71012fd3d0]+0x10. true function size 0x5c bytes.
//   [paramContainerVtb1e8StaticInstanceSlot10_71006fb2c8.cpp]
// - Slot 14 (0x80): notifies every registered object. Registry list: head =
//   *(self+0x268) - stride, anchor = (self+0x260) - stride, stride =
//   *(int*)(self+0x274); entry +0x8 next, +0x18 holder. Per entry with
//   non-null holder: obj = [holder+0x10]; sets obj+0xe28 halfword |= 0x80;
//   then calls the object's vtable method at 0xb8 (slot 23) with (x1, w4).
//   true function size 0x94 bytes. [containerB1e8NotifySlot14_71006fb500.cpp]
// - Slot 24 (0xd0): pooled object spawn. Pool cell at *(*(x1+0xf0))+0x3fc8:
//   pop a free object from the stack (count +0x8, array +0x10; null when
//   empty) and push it into the active ring (head +0x18, cap +0x1c, array
//   +0x20) if room. Reinitializes the object: +0x48 = 0xffff, +0x4a = 0,
//   +0x40 = owner (x1 arg), +0x18 = 0, +0x20 = x19 (x1 arg), +0x28 = *x2.
//   Registers via FUN_710060b618(self+0x260, *(self+0x274)+obj) and bumps
//   *(self+0x270); tail-calls FUN_71006a24e8(x1arg, (short)*x2, obj).
//   true function size 0xb8 bytes. [containerB1e8SpawnSlot24_71006fab64.cpp]
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
