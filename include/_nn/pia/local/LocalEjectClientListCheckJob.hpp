#pragma once

#include <cstdint>

namespace nn::pia::local {
// LocalEjectClientListCheckJob — RTTI-named (typeinfo 0x12e17a0, name
// "N2nn3pia5local28LocalEjectClientListCheckJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1313fa0 holds
// vptr-0x10 (vptr 0x12e1768).
// extent 0x68 - details: doc/_nn/pia/local/LocalEjectClientListCheckJob.md
class LocalEjectClientListCheckJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12e1768 (cell 0x1313fa0 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - zeroed by C1, set by run helper 0x9cf45c
  void* mPtr60;          // 0x60 - C1 arg (x1), zeroed by D1
};
}  // namespace nn::pia::local
