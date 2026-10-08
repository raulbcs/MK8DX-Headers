#pragma once

#include <cstdint>

namespace object {
// ParamNodeDirectionalLight — named from ctor string evidence: ctor params SkyColor/GroundColor/Intensity/Direction (EN/JP, 0xef9183-0xef92cd) (was address-anchored ParamNodeVt2c98) (vptr 0x12b2c98, cell 0x130d9e0, n=23, site 0x64d254, ctor 0x64d22c, alloc 0x28).
// Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]).
// Vtable slot facts (evidence TUs /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slots 0 (0x10) / 1 (0x18), deleting/complete destructor: install the
//   static vptr from cell 0x710130d9e0 (+0x10) with its +0xd8 secondary into
//   self+0x30; free self+0x1b0 via operator delete (zeroing it and word
//   self+0x1a8); reset the member sub-vptrs (0x110, 0x138, 0x160, 0x180) to
//   [0x710130d918]+0x10; base complete destructor is
//   envObjNameCompleteDtorSlot0_71006472c8. true function sizes 0x68/0x6c bytes.
//   [dirLightDeletingDtorSlot0_710064d488.cpp,
//    dirLightCompleteDtorSlot1_710064d558.cpp]
// - Slot 11 (0x68): (self, count, src) reserves a matrix array; when
//   count >= 1 allocates count*12 bytes (3 floats per entry) via
//   heapAlloc_710060b3fc on the heap from cell 0x712fae80; on success stores
//   count at word self+0x1a8 and the array pointer at self+0x1b0.
//   true function size 0x68 bytes. [dirLightAllocMatrixArraySlot11_710064d638.cpp]
// - Slot 13 (0x78): (self, src, idx) projects points. Uses the basis floats
//   self+0x198/0x19c/0x1a0 to take dot products with three 2-float pairs
//   from src and stores the three results into a 3-float row of the matrix
//   array at [self+0x1b0] (row = base + idx*12 when count word self+0x1a8 >
//   idx, else base); then re-reads that row as a 3-float vector, computes
//   its length (NaN guard FUN_7100b52790) and normalises it in place when
//   > 0. true function size 0x10c bytes.
//   [dirLightProjectPointsSlot13_710064d6a0.cpp]
class ParamNodeDirectionalLight {
 public:
  void* vtable;           // 0x00
  uint8_t mPad8[0x28];    // 0x8 — unproven gap
  uint64_t mField30;      // 0x30 — ctor-written
  uint8_t mPad38[0xd8];   // 0x38 — unproven gap
  uint64_t mField110;     // 0x110 — ctor-written
  uint8_t mPad118[0x10];  // 0x118 — unproven gap
  uint32_t mField128;     // 0x128 — ctor-written
  uint32_t mField12c;     // 0x12c — ctor-written
  uint32_t mField130;     // 0x130 — ctor-written
  uint32_t mField134;     // 0x134 — ctor-written
  uint64_t mField138;     // 0x138 — ctor-written
  uint8_t mPad140[0x10];  // 0x140 — unproven gap
  uint32_t mField150;     // 0x150 — ctor-written
  uint32_t mField154;     // 0x154 — ctor-written
  uint32_t mField158;     // 0x158 — ctor-written
  uint32_t mField15c;     // 0x15c — ctor-written
  uint64_t mField160;     // 0x160 — ctor-written
  uint8_t mPad168[0x10];  // 0x168 — unproven gap
  uint32_t mField178;     // 0x178 — ctor-written
  uint8_t mPad17c[0x4];   // 0x17c — unproven gap
  uint64_t mField180;     // 0x180 — ctor-written
  uint8_t mPad188[0x10];  // 0x188 — unproven gap
  uint32_t mField198;     // 0x198 — ctor-written
  uint32_t mField19c;     // 0x19c — ctor-written
  uint32_t mField1a0;     // 0x1a0 — ctor-written
  uint8_t mPad1a4[0x4];   // 0x1a4 — unproven gap
  uint32_t mZero1a8;      // 0x1a8 — ctor zero
  uint8_t mPad1ac[0x4];   // 0x1ac — unproven gap
  uint64_t mZero1b0;      // 0x1b0 — ctor zero
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
