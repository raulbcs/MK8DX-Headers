#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalEventCheckBackgroundJob — RTTI-named (typeinfo 0x12e1800, name
// "N2nn3pia5local28LocalEventCheckBackgroundJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1313fb0 holds
// vptr-0x10 (vptr 0x12e17c8).
// extent 0x88 - details: doc/_nn/pia/local/LocalEventCheckBackgroundJob.md
class LocalEventCheckBackgroundJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e17c8 (cell 0x1313fb0 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  uint8_t mSub58[0x18];  // 0x58 - subobject, C1 0x929ec0
  void* mPtr70;          // 0x70 - padding / uninit
  void* mPtr78;          // 0x78 - result of virtual call on C1 arg
  void* mPtr80;          // 0x80 - C1 arg (x1)
};
}  // namespace nn::pia::local
