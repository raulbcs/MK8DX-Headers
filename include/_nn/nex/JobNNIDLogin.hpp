#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo mangled name: N2nn3nex12JobNNIDLoginE).
// vptr 0x12e7af0 (GOT cell 0x1314dd0, n=13).
// Member of the nn::nex job vtable family: shared slots 0x5917a0 (vt+0x18
// secondary dispatch), 0x5917b0, ret-0 stubs 0x5917cc/0x5917d4/0x5917d8;
// base nn::nex::ForcedCriticalSection (primary vptr cell family at 0x130b618).
// NEVER CONSTRUCTED: no code site stores the derived vptr (only the generic
// .data RELATIVE init at 0xe485d8 references the vtable). The dtors
// 0xa44078/0xa442e0 touch only the base region. The previously cited
// "ctor 0xa205c0" is a method of a different class (it reads [x19,#0x190]
// and [x19,#0x1b8] on a foreign object); the old field map to 0x200 was
// taken from it and has been removed.
class JobNNIDLogin {
 public:
  void* vtable;           // 0x00
  uint8_t mBase08[0x98];  // 0x08 — nn::nex::ForcedCriticalSection base region (shared job ctor 0x588b04, extent 0xa0; secondary vptr at 0x78)
  // extent unknown (>= 0xa0): no factory/ allocation proof exists for this class.
};
}  // namespace nn::nex
