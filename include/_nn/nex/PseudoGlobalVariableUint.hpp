#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo record 0x12f9030, name
// N2nn3nex20PseudoGlobalVariableIjEE =
// PseudoGlobalVariable<unsigned int>). Under
// PseudoGlobalVariableRoot; the only instantiation of the batch with a
// resolved family ctor pattern nearby (0xb4ae90, sibling vptr
// 0x12f8d58). No C1 for this vptr itself.
// size >= 0x20 - details: doc/_nn/nex/PseudoGlobalVariableUint.md
class PseudoGlobalVariableUint {
 public:
  void* vtable;         // 0x00 - vptr 0x12f8fe8 (typeinfo ptr word at
                        // 0x12f8fe0; no GOT cell, D1/D0 use .bss cell
                        // 0x1315fb8 holding vptr-0x10)
  uint8_t mPad08[0x18]; // 0x08..0x1f - unproven (family ctor pattern
                        // 0xb4ae90 writes u32 +0x08, u8 +0x0c, ptr +0x10,
                        // bool +0x18)
};
}  // namespace nn::nex
