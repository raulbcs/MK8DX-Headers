#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalDisconnectNetworkJob — RTTI-named, base
// nn::pia::common::StepSequenceJob. 6 slots; GOT cell 0x1313f58 holds
// vptr-0x10 (vptr 0x12e16a8).
// extent 0x70 - details: doc/_nn/pia/local/LocalDisconnectNetworkJob.md
class LocalDisconnectNetworkJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e16a8 (cell 0x1313f58 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mZero58;         // 0x58 - zeroed by C1
  void* mSub60;          // 0x60 - heap subobject (new 0x20, ctor 0x929ec0)
  void* mPtr68;          // 0x68 - arg x1 of C1
};
}  // namespace nn::pia::local
