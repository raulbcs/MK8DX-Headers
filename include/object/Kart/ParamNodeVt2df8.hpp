#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt2df8 — address-anchored name (vptr 0x12f2df8, GOT cell
// 0x1315230). Node class of the 0x647f40 hook-band cluster
// (param-cache super-family ring): vptr, fields to 0x30, recorder
// channel-pair member at 0x30 (ctor pair 0x7100662f30/0x7100662f70),
// tail to 0x50 (array stride 0x50 evidence, site 0xaa2ba4).
// Shares the trivial hook band 0x647f40-0x647f6c (return-1/ret/slot-0x78
// thunk/ID compare vs [this+0x1c]).
class ParamNodeVt2df8 {
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
