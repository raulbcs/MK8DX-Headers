#pragma once

#include <cstdint>

// nn::pia::session::ProcessDestroyMeshJob — RTTI-confirmed (typeinfo 0x12de170,
// base nn::pia::common::StepSequenceJob); vptr 0x12de138 = tsv row + 8.
// extent 0x68 - details: doc/_nn/pia/session/ProcessDestroyMeshJob.md
namespace nn::pia::session {
class ProcessDestroyMeshJob {
 public:
  void* mVtable;         // 0x00 — 0x12de138 (GOT cell 0x13138e0 = vptr-0x10)
  char mJobBase8[0x40];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  uint8_t mJobBase48;    // 0x48 — cleared by shared slot-2 fn 0xb4a654 (unproven gap)
  char mPad49[0xf];      // 0x49 — unproven gap
  void* m58;             // 0x58 — 0 (C1 0x98fca0)
  uint32_t m60;          // 0x60 — 1000 (0x3e8, C1 0x98fca0)
  uint8_t m64;           // 0x64 — 0 (C1 0x98fca0)
  char mPad65[0x3];      // 0x65 — unproven gap
};
}  // namespace nn::pia::session
