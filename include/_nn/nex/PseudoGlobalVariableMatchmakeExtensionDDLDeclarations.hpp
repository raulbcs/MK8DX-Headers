#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed: typeinfo slot 0x12f5510 -> record 0x12f5560 {0x10, name
// 0xf887b0 = N2nn3nex20PseudoGlobalVariableINS0_33MatchmakeExtensionDDLDec-
// larationsEEE, base 0x128d6c0 PseudoGlobalVariableRoot}. Instantiation of
// nn::nex::PseudoGlobalVariable<MatchmakeExtensionDDLDeclarations>.
// extent 0x58 (lower bound; upper unproven) - details:
// doc/_nn/nex/PseudoGlobalVariableMatchmakeExtensionDDLDeclarations.md
class PseudoGlobalVariableMatchmakeExtensionDDLDeclarations {
 public:
  void* vtable;          // 0x00 - vptr 0x12f5518 (GOT cell 0x1315750 holds
                         // 0x12f5508 = vptr-0x10; off-top 0)
  uint8_t mPad8[0x8];    // 0x08 - unproven
  void* mField10;        // 0x10 - element array (stride 0x20; slot 0xb124c4
                         // walks it and virtually calls each element)
  uint8_t mPad18[0x40];  // 0x18 - unproven; two members spaced 0x18 apart
                         // destroyed by D1 0xb12340 via 0xb4ba2c
};
}  // namespace nn::nex
