#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalAllowParticipatingBackgroundJob — RTTI-named (typeinfo 0x12e2200,
// name "N2nn3pia5local36LocalAllowParticipatingBackgroundJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1314160 holds
// vptr-0x10 (vptr 0x12e21c8).
// extent 0x70 - details:
// doc/_nn/pia/local/LocalAllowParticipatingBackgroundJob.md
class LocalAllowParticipatingBackgroundJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e21c8 (cell 0x1314160 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - zeroed by C1, overwritten by holder C2
  uint32_t mZero60;      // 0x60 - zeroed by C1
  uint32_t mPad64;       // 0x64 - padding
  void* mPtr68;          // 0x68 - C1 arg (x1)
};
}  // namespace nn::pia::local
