#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt2ea8 — address-anchored name (vptr 0x12b2ea8, cell 0x130d9f0, n=23, site 0x606ad8, ctor 0x606ab0).
// Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]).
// Vtable slot facts (evidence TUs under /Users/raul/projects/mk8dx-400/src/unknown/):
// - Slots 0 (0x10) / 1 (0x18), complete/deleting destructor: free self+0x1f0
//   (operator delete) and clear 0x1f0/0x1e8; install the static vptr from
//   cell 0x710130d9f0 (+0x10) with its +0xd8 secondary into self+0x30; reset
//   the six member sub-vptrs (0x110, 0x138, 0x160, 0x188, 0x1a8, 0x1c8) to
//   [0x710130d918]+0x10; call base cleanup 0x71006472c8. Slot 1 additionally
//   tail-calls operator delete(self). true function sizes 0x6c/0x78 bytes
//   (gap-split artifacts).
//   [paramNodeVt2ea8CompleteDtorSlot0_710064e480.cpp,
//    paramNodeVt2ea8DeletingDtorSlot1_710064e560.cpp]
class ParamNodeVt2ea8 {
 public:
  void* vtable;             // 0x00
  uint8_t mPad8[0x308];     // 0x8 — unproven gap
  uint64_t mField310;       // 0x310 — ctor-written
  uint32_t mZero318;        // 0x318 — ctor zero
  uint8_t mPad31c[0xc];     // 0x31c — unproven gap
  uint64_t mZero328;        // 0x328 — ctor zero
  uint64_t mZero330;        // 0x330 — ctor zero
  uint16_t mPad338;         // 0x338 — ctor zero
  uint8_t mPad33a;          // 0x33a — ctor zero
  uint8_t mPad33b[0x1fe5];  // 0x33b — unproven gap
  uint32_t mField2320;      // 0x2320 — ctor-written
  uint8_t mPad2324[0xc1c];  // 0x2324 — unproven gap
  uint64_t mField2f40;      // 0x2f40 — ctor-written
  uint8_t mPad2f48[0x638];  // 0x2f48 — unproven gap
  uint64_t mZero3580;       // 0x3580 — ctor zero
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
