#pragma once

#include <cstdint>

namespace nn::pia::session {
// DestroyMeshJob — RTTI-named (typeinfo 0x12deb30, name
// "N2nn3pia7session14DestroyMeshJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1313a88 holds
// vptr-0x10 (vptr 0x12deaf8).
// extent 0x90 - details: doc/_nn/pia/session/DestroyMeshJob.md
class DestroyMeshJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12deaf8 (cell 0x1313a88 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - zeroed by C1, set by 0x9a0530
  void* mPtr60;          // 0x60 - zeroed by C1
  uint32_t mTimeout68;   // 0x68 - 5000 (C1 0x9a047c)
  uint8_t mZero6c[0x20]; // 0x6c - memset 0 by C1
  uint16_t mZero8c;      // 0x8c - zeroed by C1
  uint8_t mZero8e[2];    // 0x8e - zeroed by C1 (incl. pad to 0x90)
};
}  // namespace nn::pia::session
