#pragma once

#include <cstdint>

namespace nn::nex {
// JobNNIDLogin — RTTI-confirmed; vptr 0x12e7af0 (GOT cell 0x1314dd0); derived
// from nn::nex::JobLogin; built by factory FUN_7100a43370 (new 0x1d0 at
// 0xa435f0; derived vptr installed at 0xa43674). D1 folds to base 0xa44078,
// D0 0xa442e0.
// extent 0x1d0 - details: doc/_nn/nex/JobNNIDLogin.md
class JobNNIDLogin {
 public:
  void* vtable;               // 0x00 - 0x12e7af0 (cell 0x1314dd0 + 0x10)
  uint8_t mBase08[0xa8];      // 0x08 — nn::nex::ForcedCriticalSection base region
                              // (shared job ctor 0x588b04, extent 0xa0; secondary
                              // vptr at +0x78)
  uint8_t mUnprovenB0[0xb0];  // 0xb0..0x15f — unproven (base/derived boundary
                              // above 0xa0 unresolved; base D1 manages
                              // +0x190/+0x198)
  uint32_t mField160;         // 0x160 — derived ctor store ([arg+0x18])
  uint32_t mField164;         // 0x164 — derived ctor store (arg w2)
  void* mField168;            // 0x168 — owning factory object (x20)
  uint32_t mField178;         // 0x178 — derived ctor store (stack arg)
  uint8_t mPad170[0x8];       // 0x170..0x177 — unproven gap
  uint8_t mPad17c[0x4];       // 0x17c..0x17f — unproven gap
  void* mField180;            // 0x180 — 0x575b3c result
  uint8_t mPad188[0x38];      // 0x188..0x1bf — unproven gap
  void* mField1c0;            // 0x1c0 — arg pointer (x24); released by dtor path
  void* mField1c8;            // 0x1c8 — arg pointer (x28)
};
}  // namespace nn::nex
