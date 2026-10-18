#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalEventJob — RTTI-named (typeinfo 0x12e1860, name
// "N2nn3pia5local13LocalEventJobE"; base nn::pia::common::StepSequenceJob).
// 6 slots; GOT cell 0x1313fd8 holds vptr-0x10 (vptr 0x12e1828).
// extent 0x68 - details: doc/_nn/pia/local/LocalEventJob.md
class LocalEventJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e1828 (cell 0x1313fd8 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - zeroed by C1
  void* mPtr60;          // 0x60 - C1 arg (x1), zeroed by D1
};
}  // namespace nn::pia::local
