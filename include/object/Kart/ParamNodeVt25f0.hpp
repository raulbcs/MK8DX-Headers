#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt25f0 — address-anchored name (vptr 0x12b25f0, GOT cell
// 0x130d990). Node class of the 0x647f40 hook-band cluster
// (param-cache super-family ring): vptr, fields to 0x30, recorder
// channel-pair member at 0x30 (ctor pair 0x7100662f30/0x7100662f70),
// tail to 0x50 (array stride 0x50 evidence, site 0x64a88c).
// Shares the trivial hook band 0x647f40-0x647f6c (return-1/ret/slot-0x78
// thunk/ID compare vs [this+0x1c]).
// Vtable slot facts (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 8 (0x50): two-stage keyed lookup. Runs the +0x18 vtable method on
//   self+0x48 twice, then on the global object at *(0x12fc190); byte-compares
//   strings (terminator from *(0x12fada8), cap 0x100001 bytes) between
//   self+0x50 and the global's +0x8; builds a key cell from global
//   0x12fae28 (+0x10) plus fixed name pointer 0xee4d88 (FUN_7100663050 /
//   FUN_7100672b34, index -1 = miss) and resolves a target node; repeats the
//   +0x18 calls on self+0xc8 and a second byte-compare between *(self+0xd0)
//   and the target; returns 1 on match, else 0. true function size 0x1d0 bytes.
//   [paramNodeTwoKeyLookupSlot8_710064b988.cpp]
// - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: install the
//   static vptr from cell 0x710130d990 (+0x10), [0x710130d918]+0x10 into
//   self+0xb0 and [0x710130d938]+0x10 into self+0x30; call
//   FUN_7100661c4c(self). Slot 0 then restores the derived vptr from cell
//   0x710130d920 (+0x10) and returns self; slot 1 tail-calls operator
//   delete(self). true function sizes 0x5c/0x54 bytes.
//   [vt25f0CompleteDtorSlot0_710064bb5c.cpp,
//    vt25f0DeletingDtorSlot1_710064bbbc.cpp]
class ParamNodeVt25f0 {
 public:
  void* vtable;          // 0x00
  uint32_t mField8;      // 0x8 — ctor: call result
  uint8_t mPadc[0x4];    // 0xc — unproven gap
  uint64_t mZero10;      // 0x10 — ctor zero
  uint8_t mPad18[0x18];  // 0x18 — unproven gap
  char mChan30[0x20];    // 0x30 — recorder channel-pair member
                         // (0x50 total)
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
