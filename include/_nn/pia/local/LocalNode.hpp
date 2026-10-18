#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalNode — RTTI-named (typeinfo 0x12e21a0, name
// "N2nn3pia5local9LocalNodeE"; base nn::pia::common::ISerializable,
// typeinfo 0x12dd558). 6 slots; GOT cell 0x1314158 holds vptr-0x10
// (vptr 0x12e2168).
// extent 0x28 - details: doc/_nn/pia/local/LocalNode.md
class LocalNode {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e2168 (cell 0x1314158 + 0x10)
  uint8_t mSub08[0x18];  // 0x08 - member subobject, C1 0x9c2648 (vptr cell
                         // 0x1313d58 -> vptr 0x12e0478); has D1 pair 0x9d448c
  uint32_t mZero20;      // 0x20 - zeroed by C1
  uint8_t mZero24;       // 0x24 - zeroed by C1
  uint8_t mFF25;         // 0x25 - 0xff by C1
  uint16_t mPad26;       // 0x26 - padding (size 0x28)
};
}  // namespace nn::pia::local
