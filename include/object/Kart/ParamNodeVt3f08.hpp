#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt3f08 — address-anchored name (vptr 0x12f3f08, GOT cell
// 0x1315430). Node class of the 0x647f40 hook-band cluster
// (param-cache super-family ring): vptr, fields to 0x30, recorder
// channel-pair member at 0x30 (ctor pair 0x7100662f30/0x7100662f70),
// tail to 0x50 (array stride 0x50 evidence, site 0xa8fd08).
// Shares the trivial hook band 0x647f40-0x647f6c (return-1/ret/slot-0x78
// thunk/ID compare vs [this+0x1c]).
// Vtable slot facts (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slot 0 (0x10): destructor (returns self, no operator delete). Installs
//   the static vptr from cell 0x7101315430 (+0x10), calls member cleanup
//   0x7100ae1308 on self+0xa8, self+0x90 and self+0x78, sets self+0x50 to
//   [0x710130d918]+0x10, then installs the outer vptr from cell
//   0x710130d920 (+0x10). true function size 0x74 bytes.
//   [paramNodeVt3f08DtorSlot0_7100adb5d0.cpp]
// - Slot 1 (0x18): deleting destructor. Installs cell 0x710151430 (+0x10)
//   into self+0x0 and self+0x90, calls 0x7100ae1308 on self+0xa8,
//   self+0x120 and self+0x78, then tail-calls operator delete(self).
//   true function size 0x58 bytes. [vt3f08DeletingDtorSlot1_7100adb644.cpp]
class ParamNodeVt3f08 {
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
