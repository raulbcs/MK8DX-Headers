#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12e4f00: nn::nex::PseudoGlobalVariable<unsigned
// short>). Growable u16 id-list; no standalone C1 - instances are initialized
// in place inside a global table by FUN_71009f7434.
// size >= 0x20 - details: doc/_nn/nex/PseudoGlobalVariableU16.md
class PseudoGlobalVariableU16 {
 public:
  void* vtable;           // 0x00 - vptr 0x12e4eb8 (GOT cell 0x1314578 holds
                          // 0x12e4ea8 = vptr-0x10; typeinfo slot 0x12e4eb0)
  char mPad08[0x8];       // 0x08..0x0f - unproven (not written by init)
  void* mArray10;         // 0x10 - heap array, grown by slot2 (realloc 0x576368)
  uint32_t mField18;      // 0x18 - init writes halfword 0x23f3
  uint16_t mCount1a;      // 0x1a - init writes 0x23f3; count used by slot2
  char mPad1c[0x4];       // 0x1c..0x1f - unproven
};
}  // namespace nn::nex
