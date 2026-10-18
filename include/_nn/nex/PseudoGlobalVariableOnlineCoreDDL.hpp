#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo record 0x12f8ee0, name
// N2nn3nex20PseudoGlobalVariableINS0_25OnlineCoreDDLDeclarationsEEE).
// PseudoGlobalVariable<OnlineCoreDDLDeclarations> under
// PseudoGlobalVariableRoot (ti base 0x128d6c0); no standalone C1 found.
// size >= 0x20 - details: doc/_nn/nex/PseudoGlobalVariableOnlineCoreDDL.md
class PseudoGlobalVariableOnlineCoreDDL {
 public:
  void* vtable;        // 0x00 - vptr 0x12f8e98 (typeinfo ptr word at
                       // 0x12f8e90; no GOT cell, D1/D0 use .bss cell
                       // 0x1315fa0 holding vptr-0x10)
  uint8_t mPad08[0x18]; // 0x08..0x1f - unproven (family ctor pattern
                        // 0xb4ae90 writes u32 +0x08, u8 +0x0c, ptr +0x10,
                        // bool +0x18)
};
}  // namespace nn::nex
