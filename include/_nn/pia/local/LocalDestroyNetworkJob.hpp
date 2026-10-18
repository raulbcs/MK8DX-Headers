#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalDestroyNetworkJob — RTTI-named, base
// nn::pia::common::StepSequenceJob. 6 slots; GOT cell 0x1313f18 holds
// vptr-0x10 (vptr 0x12e1648).
// extent 0x90 - details: doc/_nn/pia/local/LocalDestroyNetworkJob.md
class LocalDestroyNetworkJob {
 public:
  void* mVtable;          // 0x00 - vptr 0x12e1648 (cell 0x1313f18 + 0x10)
  uint8_t mPad08[0x50];   // 0x08 - base job region (C1 0xb4a5e0)
  void* mZero58;          // 0x58 - zeroed by C1
  void* mSub60;           // 0x60 - heap subobject (new 0x20, ctor 0x929ec0)
  uint8_t mZero68[0x10];  // 0x68 - zeroed by C1
  void* mZero78;          // 0x78 - zeroed by C1
  uint8_t mZero80;        // 0x80 - zeroed by C1
  uint8_t mPad81[0x7];    // 0x81 - padding
  void* mPtr88;           // 0x88 - arg x1 of C1
};
}  // namespace nn::pia::local
