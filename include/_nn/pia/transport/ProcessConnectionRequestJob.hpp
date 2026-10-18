#pragma once

#include <cstdint>

namespace nn::pia::transport {
// ProcessConnectionRequestJob — RTTI-named (typeinfo 0x12def00, name
// "N2nn3pia9transport27ProcessConnectionRequestJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1313b68 holds
// vptr-0x10 (vptr 0x12deed0).
// extent 0x88 - details: doc/_nn/pia/transport/ProcessConnectionRequestJob.md
class ProcessConnectionRequestJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12deed0 (cell 0x1313b68 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - zeroed by C1
  uint32_t mTimeout60;   // 0x60 - 10000 (C1 0x9a6f9c)
  uint64_t mZero64;      // 0x64 - zeroed by C1 (stur xzr)
  uint32_t mPad6c;       // 0x6c - padding (zeroed region extends to 0x70)
  void* mPtr70;          // 0x70 - set by member fn 0x9a70d8
  void* mSub78;          // 0x78 - ptr to 0x20-byte heap subobject (C1 0x929ec0)
  uint8_t mPad80[0x8];   // 0x80 - padding (extent 0x88)
};
}  // namespace nn::pia::transport
