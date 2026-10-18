#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12f60b0: nn::nex::PseudoGlobalVariable<
// NATTraversalDDLDeclarations>). Static .bss singleton of the online
// pseudo-global registry; no standalone C1 - in-place init FUN_7100b17ed4.
// extent 0x58 - details: doc/_nn/nex/PseudoGlobalVariableNATTraversalDDLDeclarations.md
class PseudoGlobalVariableNATTraversalDDLDeclarations {
 public:
  void* mVtable;            // 0x00 - vptr 0x12f6068 (GOT cell 0x13158c0 holds
                            // 0x12f6058 = vptr-0x10; typeinfo slot 0x12f6060)
  char mPad08[0x10];        // 0x08..0x17 - registry tree node; init zeroes 0x10
  void* mFirstVptr;         // 0x18 - first NATTraversalDDLDeclarations
  uint64_t mFirstField20;   // 0x20 - init copies from +0x40
  uint64_t mFirstField28;   // 0x28 - init copies from +0x48
  uint8_t mFirstFlag30;     // 0x30 - init copies u8 at +0x50
  char mPad31[0x7];         // 0x31..0x37 - unproven (end of first value)
  void* mSecondVptr;        // 0x38 - second NATTraversalDDLDeclarations
  uint64_t mSecondField40;  // 0x40 - init writes defaults
  uint64_t mSecondField48;  // 0x48 - init writes defaults
  uint8_t mSecondFlag50;    // 0x50 - init writes default flag
  char mPad51[0x7];         // 0x51..0x57 - unproven (end of second value)
};
}  // namespace nn::nex
