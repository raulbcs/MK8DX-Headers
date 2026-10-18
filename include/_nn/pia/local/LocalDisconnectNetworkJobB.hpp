#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalDisconnectNetworkJobB — (ICF duplicate; second copy, vptr 0x12e1708, size 0x110) — RTTI-named (typeinfo 0x12e1740, name
// "N2nn3pia5local25LocalDisconnectNetworkJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1313f78 holds
// vptr-0x10 (vptr 0x12e1708).
// extent 0x110 - details: doc/_nn/pia/local/LocalDisconnectNetworkJobB.md
class LocalDisconnectNetworkJobB {
 public:
  void* mVtable;           // 0x00 - vptr 0x12e1708 (cell 0x1313f78 + 0x10)
  uint8_t mPad08[0x50];    // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;            // 0x58 - 0x78-byte job alloc, C1 0x9d4850
  uint8_t mUnits60[0x70];  // 0x60 - 7 subobjects, stride 0x10, C1 0x92a1e0
  uint64_t mD0;            // 0xd0 - list head (this+0x60)
  uint64_t mD8;            // 0xd8 - zeroed by C1
  uint32_t mE0;            // 0xe0 - count = 7
  uint32_t mPadE4;         // 0xe4 - padding
  uint8_t mSubE8[0x18];    // 0xe8 - subobject, C1 0x929ec0
  uint8_t mPad100[0x8];    // 0x100 - padding
  void* mPtr108;           // 0x108 - session/handle arg (C1 x1)
};
}  // namespace nn::pia::local
