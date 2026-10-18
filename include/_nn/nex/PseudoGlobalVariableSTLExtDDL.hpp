#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo record 0x12f8f50, name
// N2nn3nex20PseudoGlobalVariableINS0_21STLExtDDLDeclarationsEEE).
// PseudoGlobalVariable<STLExtDDLDeclarations> under
// PseudoGlobalVariableRoot; no standalone C1 found.
// size >= 0x20 - details: doc/_nn/nex/PseudoGlobalVariableSTLExtDDL.md
class PseudoGlobalVariableSTLExtDDL {
 public:
  void* vtable;         // 0x00 - vptr 0x12f8f08 (typeinfo ptr word at
                        // 0x12f8f00; no GOT cell, D1/D0 use .bss cell
                        // 0x1315fa8 holding vptr-0x10)
  uint8_t mPad08[0x18]; // 0x08..0x1f - unproven (family ctor pattern
                        // 0xb4ae90 writes u32 +0x08, u8 +0x0c, ptr +0x10,
                        // bool +0x18)
};
}  // namespace nn::nex
