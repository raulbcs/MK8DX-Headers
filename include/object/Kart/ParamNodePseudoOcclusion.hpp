#pragma once

#include <cstdint>

namespace object {
// ParamNodePseudoOcclusion — named from ctor string evidence: ctor params Position/Radius/CoreRadius/VerticesBias/DepthOffset/PseudoOccl (0xeeee93-0xf1ea66) (was address-anchored ParamNodeVt4400) (vptr 0x12f4400, cell 0x13154d0, n=22, site 0xaeeef0, ctor 0xaeeec8).
// Node class of the 0x647f40 hook-band cluster (shared trivial band
// 0x647f40-0x647f6c: return-1/ret/slot-0x78 thunk/ID compare vs
// [this+0x1c]).
class ParamNodePseudoOcclusion {
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
  uint8_t mPad134[0x4];   // 0x134 — unproven gap
  uint64_t mField138;     // 0x138 — ctor-written
  uint8_t mPad140[0x10];  // 0x140 — unproven gap
  uint32_t mField150;     // 0x150 — ctor-written
  uint8_t mPad154[0x4];   // 0x154 — unproven gap
  uint64_t mField158;     // 0x158 — ctor-written
  uint8_t mPad160[0x10];  // 0x160 — unproven gap
  uint32_t mField170;     // 0x170 — ctor-written
  uint8_t mPad174[0x4];   // 0x174 — unproven gap
  uint64_t mField178;     // 0x178 — ctor-written
  uint8_t mPad180[0x10];  // 0x180 — unproven gap
  uint32_t mField190;     // 0x190 — ctor-written
  uint8_t mPad194[0x4];   // 0x194 — unproven gap
  uint64_t mField198;     // 0x198 — ctor-written
  uint8_t mPad1a0[0x10];  // 0x1a0 — unproven gap
  uint32_t mZero1b0;      // 0x1b0 — ctor zero
  uint8_t mPad1b4[0x4];   // 0x1b4 — unproven gap
  uint64_t mField1b8;     // 0x1b8 — ctor-written
  uint8_t mPad1c0[0x10];  // 0x1c0 — unproven gap
  uint64_t mField1d0;     // 0x1d0 — ctor-written
  uint64_t mField1d8;     // 0x1d8 — ctor-written
  uint8_t mPad1e0[0x10];  // 0x1e0 — unproven gap
  uint64_t mZero1f0;      // 0x1f0 — ctor zero
  uint32_t mField1f8;     // 0x1f8 — ctor-written
  uint8_t mPad1fc[0x4];   // 0x1fc — unproven gap
  uint64_t mField200;     // 0x200 — ctor-written
  uint8_t mPad208[0x10];  // 0x208 — unproven gap
  uint8_t mPad218;        // 0x218 — ctor zero
  uint8_t mPad219[0x7];   // 0x219 — unproven gap
  uint64_t mField220;     // 0x220 — ctor-written
  uint8_t mPad228[0x10];  // 0x228 — unproven gap
  uint64_t mField238;     // 0x238 — ctor-written
  uint64_t mField240;     // 0x240 — ctor-written
  uint32_t mField248;     // 0x248 — ctor-written
  uint8_t mPad24c[0x24];  // 0x24c — unproven gap
  uint64_t mField270;     // 0x270 — ctor-written
  uint8_t mPad278[0x10];  // 0x278 — unproven gap
  uint8_t mPad288;        // 0x288 — ctor zero
  uint8_t mPad289[0x7];   // 0x289 — unproven gap
  uint64_t mField290;     // 0x290 — ctor-written
  uint8_t mPad298[0x10];  // 0x298 — unproven gap
  uint8_t mPad2a8;        // 0x2a8 — ctor zero
  uint8_t mPad2a9[0x7];   // 0x2a9 — unproven gap
  uint64_t mField2b0;     // 0x2b0 — ctor-written
  uint8_t mPad2b8[0x10];  // 0x2b8 — unproven gap
  uint8_t mPad2c8;        // 0x2c8 — ctor zero
  uint8_t mPad2c9[0x7];   // 0x2c9 — unproven gap
  uint64_t mZero2d0;      // 0x2d0 — ctor zero
  uint8_t mField2d8;      // 0x2d8 — ctor-written
  uint8_t mPad2d9[0x3];   // 0x2d9 — unproven gap
  uint32_t mField2dc;     // 0x2dc — ctor-written
  uint8_t mPad2e0;        // 0x2e0 — ctor zero
  uint8_t mPad2e1[0x3];   // 0x2e1 — unproven gap
  uint32_t mZero2e4;      // 0x2e4 — ctor zero
};
}  // namespace object

// Naming closure: no ctor strings in a 500-line window (or icon-string only); quoted ctor anchors near the nvn init region need re-verification before any semantic rename. Address-anchored name retained.
