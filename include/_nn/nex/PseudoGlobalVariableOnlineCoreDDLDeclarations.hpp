#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12f8e70: nn::nex::PseudoGlobalVariable<
// OnlineCoreDDLDeclarations>). Static .bss singleton of the online
// pseudo-global registry; no standalone C1 - in-place init FUN_7100b4c4a4.
// extent 0x58 - details: doc/_nn/nex/PseudoGlobalVariableOnlineCoreDDLDeclarations.md
class PseudoGlobalVariableOnlineCoreDDLDeclarations {
 public:
  void* mVtable;            // 0x00 - vptr 0x12f8e28 (GOT cell 0x1315f98 holds
                            // 0x12f8e18 = vptr-0x10; typeinfo slot 0x12f8e20)
  char mPad08[0x10];        // 0x08..0x17 - registry tree node; init zeroes 0x10
  void* mFirstVptr;         // 0x18 - first OnlineCoreDDLDeclarations value
  uint64_t mFirstField20;   // 0x20 - init writes 0
  uint64_t mFirstField28;   // 0x28 - init writes 0
  uint8_t mFirstFlag30;     // 0x30 - init writes 1
  char mPad31[0x7];         // 0x31..0x37 - unproven (end of first value)
  void* mSecondVptr;        // 0x38 - second value subobject (vtable of base
                            // STLExtDDLDeclarations, vptr 0x12f8de8)
  uint32_t mSecondField40;  // 0x40 - init writes 0
  char mPad44[0x4];         // 0x44..0x47 - init writes 0 to 0x44
  uint64_t mSecondField48;  // 0x48 - init writes 0
  uint8_t mSecondFlag50;    // 0x50 - init writes 1
  char mPad51[0x7];         // 0x51..0x57 - unproven (end of second value)
};
}  // namespace nn::nex
