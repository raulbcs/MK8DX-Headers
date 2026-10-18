#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo record 0x12f9150, name
// N2nn3nex20PseudoGlobalVariableINS0_37NintendoAuthenticationDDLDeclarationsEEE).
// PseudoGlobalVariable<NintendoAuthenticationDDLDeclarations>; no
// standalone C1 found. D0 destroys subobjects at +0x18 and +0x38.
// size >= 0x40 - details: doc/_nn/nex/PseudoGlobalVariableNintendoAuthDDL.md
class PseudoGlobalVariableNintendoAuthDDL {
 public:
  void* vtable;         // 0x00 - vptr 0x12f9108 (typeinfo ptr word at
                        // 0x12f9100; no GOT cell, D1/D0 use .bss cell
                        // 0x1316030 holding vptr-0x10)
  uint8_t mPad08[0x10]; // 0x08..0x17 - unproven
  uint8_t mPad18[0x20]; // 0x18..0x37 - unproven subobject (trivially
                        // destructible; D0 0xb4cd1c runs stub 0xb4ba2c on
                        // this+0x18 and this+0x38)
  uint8_t mPad38[0x8];  // 0x38..0x3f - unproven subobject start (extent
                        // beyond 0x40 unproven)
};
}  // namespace nn::nex
