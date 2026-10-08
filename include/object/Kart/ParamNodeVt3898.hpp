#pragma once

#include <cstdint>

namespace object {
// ParamNodeVt3898 — address-anchored name (vptr 0x12f3898, cell 0x1315328, n=23, site 0xa83a60, ctor 0xa83984, alloc 0x48).
// Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]).
class ParamNodeVt3898 {
 public:
  void* vtable;           // 0x00
  uint8_t mPad8[0xf8];    // 0x8 — unproven gap
  uint64_t mField100;     // 0x100 — ctor: call result
  uint8_t mPad108[0x8];   // 0x108 — unproven gap
  uint32_t mField110;     // 0x110 — ctor-written
  uint32_t mField114;     // 0x114 — ctor-written
  uint64_t mZero118;      // 0x118 — ctor zero
  uint8_t mPad120[0x8];   // 0x120 — unproven gap
  uint64_t mField128;     // 0x128 — ctor-written
  uint64_t mField130;     // 0x130 — ctor-written
  uint8_t mPad138[0x10];  // 0x138 — unproven gap
  uint64_t mField148;     // 0x148 — ctor: call result
  uint64_t mField150;     // 0x150 — ctor: call result
  uint64_t mField158;     // 0x158 — ctor: call result
  uint64_t mField160;     // 0x160 — ctor: call result
  uint64_t mField168;     // 0x168 — ctor: call result
  uint64_t mField170;     // 0x170 — ctor: call result
  uint32_t mField178;     // 0x178 — ctor-written
  uint8_t mPad17c[0x4];   // 0x17c — unproven gap
  uint64_t mField180;     // 0x180 — ctor-written
  uint8_t mPad188[0x10];  // 0x188 — unproven gap
  uint64_t mField198;     // 0x198 — ctor: call result
  uint8_t mPad1a0[0x18];  // 0x1a0 — unproven gap
  uint64_t mField1b8;     // 0x1b8 — ctor-written
  uint64_t mField1c0;     // 0x1c0 — ctor: call result
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
