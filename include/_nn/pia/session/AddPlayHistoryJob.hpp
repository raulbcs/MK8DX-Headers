#pragma once

#include <cstdint>

// nn::pia::session::AddPlayHistoryJob — RTTI-confirmed (typeinfo 0x12dea70,
// base nn::pia::common::StepSequenceJob); vptr 0x12dea38 = tsv row + 8.
// extent 0xf8 - details: doc/_nn/pia/session/AddPlayHistoryJob.md
namespace nn::pia::session {
class AddPlayHistoryJob {
 public:
  void* mVtable;         // 0x00 — 0x12dea38 (GOT cell 0x1313a48 = vptr-0x10)
  char mJobBase8[0x40];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  uint8_t mJobBase48;    // 0x48 — cleared by shared slot-2 fn 0xb4a654 (unproven gap)
  char mPad49[0xa3];     // 0x49 — C1 writes nothing (unproven gap)
  uint8_t mEc;           // 0xec — 0 (C1 0x99f71c)
  char mPadEd[0xb];      // 0xed — unproven gap
};
}  // namespace nn::pia::session
