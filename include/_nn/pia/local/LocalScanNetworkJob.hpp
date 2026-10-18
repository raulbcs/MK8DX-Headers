#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalScanNetworkJob — RTTI-confirmed (typeinfo 0x12e0df0, name
// "N2nn3pia5local19LocalScanNetworkJobE", base nn::pia::common::StepSequenceJob).
// extent 0x70 - details: doc/_nn/pia/local/LocalScanNetworkJob.md
class LocalScanNetworkJob {
 public:
  void* mVtable;          // 0x00 - vptr 0x12e0db8 (GOT cell 0x1313e10 + 0x10)
  uint8_t mBase08[0x50];  // 0x08 - base job region (C1 0xb4a5e0), unproven gap
  void* mPtr58;           // 0x58 - zeroed by C2
  void* mSub60;           // 0x60 - 0x20-byte heap subobject (ctor 0x929ec0)
  void* mArg68;           // 0x68 - C2 x1 argument, cleared by D1/D0
};
}  // namespace nn::pia::local
