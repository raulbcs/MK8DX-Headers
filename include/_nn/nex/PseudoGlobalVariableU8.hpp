#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12e50e0: nn::nex::PseudoGlobalVariable<unsigned
// char>). Sorted intrusive list keyed by s16 at node+0x28 (erase at 0xa1d260
// unlinks, decrements the +0x10 count, frees the node); no standalone C1.
// size >= 0x18 - details: doc/_nn/nex/PseudoGlobalVariableU8.md
class PseudoGlobalVariableU8 {
 public:
  void* vtable;           // 0x00 - vptr 0x12e5098 (GOT cell 0x1314608 holds
                          // 0x12e5088 = vptr-0x10; typeinfo slot 0x12e5090)
  char mPad08[0x8];       // 0x08..0x0f - unproven
  uint64_t mCount10;      // 0x10 - node count, decremented by erase
  char mPad18[0x8];       // 0x18..0x1f - unproven
};
}  // namespace nn::nex
