#pragma once

#include <cstdint>

// nn::pia::session::ProcessJoinRequestJob — RTTI-confirmed (typeinfo 0x12de280,
// base nn::pia::common::StepSequenceJob); vptr 0x12de248 = tsv row + 8.
// extent 0xa8 - details: doc/_nn/pia/session/ProcessJoinRequestJob.md
namespace nn::pia::session {
class ProcessJoinRequestJob {
 public:
  void* mVtable;         // 0x00 — 0x12de248 (GOT cell 0x1313910 = vptr-0x10)
  char mJobBase8[0x40];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  uint8_t mJobBase48;    // 0x48 — cleared by shared slot-2 fn 0xb4a654 (unproven gap)
  char mPad49[0xf];      // 0x49 — unproven gap
  void* m58;             // 0x58 — 0 (C1 0x991d5c)
  uint32_t m60;          // 0x60 — 10000 (0x2710, C1 0x991d5c)
  uint8_t mPad64[4];     // 0x64 - unproven gap
  void* m68;             // 0x68 — 0 (C1 0x991d5c)
  uint32_t m70;          // 0x70 — 0 (C1 0x991d5c)
  uint8_t mPad74[4];     // 0x74 - unproven gap
  void* m78;             // 0x78 — 0 (C1 0x991d5c)
  void* m80;             // 0x80 — 0 (C1 0x991d5c)
  void* m88;             // 0x88 — config-derived (C1 0x991d5c)
  char mSub90[0x10];     // 0x90 — sub-object, builder 0x92a1e0 (vtable-proven region)
  uint32_t mA0;          // 0xa0 — 0xfd (C1 0x991d5c)
  uint16_t mA4;          // 0xa4 — 0x300 (C1 0x991d5c)
  uint8_t mA6;           // 0xa6 — 0 (C1 0x991d5c)
  char mPadA7;           // 0xa7 — unproven gap
};
}  // namespace nn::pia::session
