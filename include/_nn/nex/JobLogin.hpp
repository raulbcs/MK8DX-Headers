#pragma once

#include <cstdint>

namespace nn::nex {
// JobLogin — RTTI-confirmed; vptr 0x12e7a78 (GOT cell 0x1314dc8); base of
// nn::nex::JobNNIDLogin, built inline in factory FUN_7100a43370 (vptr at
// 0xa43624, overridden by the derived vptr at 0xa43674). D1 0xa44078 / D0 0xa440fc.
// extent >= 0x1a0 (lower bound) - details: doc/_nn/nex/JobLogin.md
class JobLogin {
 public:
  void* vtable;           // 0x00 - 0x12e7a78 (cell 0x1314dc8 + 0x10)
  uint8_t mBase08[0xa8];  // 0x08 — nn::nex::ForcedCriticalSection base region
                          // (shared job ctor 0x588b04, extent 0xa0; secondary
                          // vptr at +0x78)
  // 0xb0..0x19f — dtor-managed region: D1 0xa44078 releases [+0x190],
  // reinstalls the +0x198 secondary vptr (cell 0x130b4a8) and destroys it,
  // and runs the +0x1a0 subobject init (0xa2c1e8). Field ownership between
  // this base and the derived class above 0xa0 is unresolved (unverified).
};
}  // namespace nn::nex
