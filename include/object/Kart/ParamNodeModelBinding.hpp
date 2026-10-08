#pragma once

#include <cstdint>

namespace object {
// ParamNodeModelBinding — named from ctor string evidence: ctor params ModelName + BonePrefix (EN/JP, 0xf06f37-0xf06f59) (was address-anchored ParamNodeVte3d0) (vptr 0x12be3d0, cell 0x130e988, n=27, site 0x732d38, ctor 0x732d0c).
// Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]).
// Vtable slot facts (evidence TU /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 0 (+0x10): complete-object destructor prologue. Re-stamps the
//   primary vptr (+0x0) and secondary vptr (+0x30) from descriptor cell
//   0x710130e988 (+0x10 / +0xf8), re-stamps the sub-object vptrs at
//   +0x1f0/+0x180/+0x110 from [0x710130d918]+0x10, then tail-calls the base
//   complete destructor envObjNameCompleteDtorSlot0_71006472c8.
//   true function size 0x34 bytes (gap-split artifact).
//   [paramNodeModelBindingCompleteDtorSlot0_710073305c.cpp]
class ParamNodeModelBinding {
 public:
  void* vtable;         // 0x00
  uint8_t mPad8[0x28];  // 0x8 — unproven gap
  uint64_t mField30;    // 0x30 — ctor-written
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
