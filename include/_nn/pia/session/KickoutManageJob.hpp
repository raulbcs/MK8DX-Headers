#pragma once

#include <cstdint>

// nn::pia::session::KickoutManageJob — RTTI-confirmed (typeinfo 0x12dde30,
// base pia::common::StepSequenceJob); vptr 0x12ddde8 = tsv row + 8.
// extent 0x190 - details: doc/_nn/pia/session/KickoutManageJob.md
namespace nn::pia::session {
class KickoutManageJob {
 public:
  void* mVtable;         // 0x00 — 0x12ddde8 (GOT cell 0x13137a0 = vptr-0x10)
  char mJobBase8[0x50];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  char mPad58[0x100];    // 0x58 — unproven gap
  uint32_t m158;         // 0x158 — 0 (C1 0x984384)
  char mPad15c[0x4];     // 0x15c — unproven gap
  void* mVtable160;      // 0x160 — sub-object vptr, sub-ctor 0x929ec0 (region to 0x180)
  char mPad168[0x18];    // 0x168 — unproven gap
  void* m180;            // 0x180 — 0 (C1 0x984388)
  uint8_t m188;          // 0x188 — 0 (C1 0x98438c)
  char mPad189[0x3];     // 0x189 — unproven gap
  uint32_t m18c;         // 0x18c — 0 (C1 0x984380)
};
}  // namespace nn::pia::session
