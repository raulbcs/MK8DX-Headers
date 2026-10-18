#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalAllowParticipatingJob — RTTI-named, base
// nn::pia::common::StepSequenceJob. 6 slots; GOT cell 0x1313eb8 holds
// vptr-0x10 (vptr 0x12e1488).
// extent 0x98 - details: doc/_nn/pia/local/LocalAllowParticipatingJob.md
class LocalAllowParticipatingJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e1488 (cell 0x1313eb8 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - heap object (new 0x70, C1 0x9d4620)
  void* mZero60;         // 0x60 - zeroed by C1
  uint8_t mSub68[0x20];  // 0x68 - member subobject, ctor 0x929ec0
  void* mZero88;         // 0x88 - zeroed by C1
  void* mParent90;       // 0x90 - arg x1 of C1
};
}  // namespace nn::pia::local
