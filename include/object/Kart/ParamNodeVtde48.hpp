#pragma once

#include <cstdint>

namespace object {
// ParamNodeVtde48 — address-anchored name (vptr 0x12bde48, cell 0x130e920, n=27, site 0x6e66a4, ctor 0x6e6644).
// Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]).
class ParamNodeVtde48 {
 public:
  void* vtable;          // 0x00
  uint8_t mPad8[0x54c];  // 0x8 — unproven gap
  uint32_t mField554;    // 0x554 — ctor-written
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
