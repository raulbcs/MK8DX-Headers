#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12e7880: nn::nex::PseudoGlobalVariable<nn::nex::
// AccountManagementServiceDDLDeclarations>). Global-settings holder; static
// instance at 0x13671f8, no standalone C1 (re-init in FUN_7100a42d40).
// extent 0x58 (lower bound, unverified) - details: doc/_nn/nex/PseudoGlobalVariableAccountManagementServiceDDLDeclarations.md
class PseudoGlobalVariableAccountManagementServiceDDLDeclarations {
 public:
  void* vtable;            // 0x00 - vptr 0x12e7838 (GOT cell 0x1314b60 holds
                           // 0x12e7828 = vptr-0x10; typeinfo slot 0x12e7830)
  uint8_t mPad08[0x8];     // 0x08..0x0f - unproven
  void* mList10;           // 0x10 - array of 0x20-byte T entries; torn down by
                           // slot +0x18 (0xa42918, free 0x5763ac)
  uint8_t mValue18[0x20];  // 0x18..0x37 - T = AccountManagementServiceDDLDeclarations
                           // (vptr 0x12e73e8); inited by helper 0xb4ae90(x,1);
                           // bytes +0x20..+0x31 copied from +0x40..+0x51
  uint8_t mSaved38[0x20];  // 0x38..0x57 - second T copy (helper 0xb4ae90);
                           // source of the +0x20/+0x28/+0x30 restore
};
}  // namespace nn::nex
