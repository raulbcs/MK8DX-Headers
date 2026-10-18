#pragma once

#include <cstdint>

// nn::pia::session::SessionStatusCheckJob — RTTI-confirmed (typeinfo 0x12de820,
// base nn::pia::common::StepSequenceJob); vptr 0x12de7e8 = tsv row + 8.
// extent 0x80 - details: doc/_nn/pia/session/SessionStatusCheckJob.md
namespace nn::pia::session {
class SessionStatusCheckJob {
 public:
  void* mVtable;         // 0x00 — 0x12de7e8 (GOT cell 0x1313a08 = vptr-0x10)
  char mJobBase8[0x40];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  uint8_t mJobBase48;    // 0x48 — cleared by shared slot-2 fn 0xb4a654 (unproven gap)
  char mPad49[0xf];      // 0x49 — unproven gap
  char mSub58[0x20];     // 0x58 — sub-object, builder 0x929ec0 (vtable-proven region)
  uint16_t m78;          // 0x78 — 0 (C1 0x99d348)
  char mPad7a[0x6];      // 0x7a — unproven gap
};
}  // namespace nn::pia::session
