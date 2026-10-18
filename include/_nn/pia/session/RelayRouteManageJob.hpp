#pragma once

#include <cstdint>

// nn::pia::session::RelayRouteManageJob — RTTI-confirmed (typeinfo 0x12de400,
// base nn::pia::common::StepSequenceJob); vptr 0x12de3c8 = tsv row + 8.
// extent 0x90 - details: doc/_nn/pia/session/RelayRouteManageJob.md
namespace nn::pia::session {
class RelayRouteManageJob {
 public:
  void* mVtable;         // 0x00 — 0x12de3c8 (GOT cell 0x13139c8 = vptr-0x10)
  char mJobBase8[0x40];  // 0x08 — shared pia job-base C1 0xb4a5e0 region (unproven gap)
  uint8_t mJobBase48;    // 0x48 — cleared by shared slot-2 fn 0xb4a654 (unproven gap)
  char mPad49[0xf];      // 0x49 — unproven gap
  uint16_t m58;          // 0x58 — grid dimension, from global config cell 0x13125e0+0x48 (C1 0x996be4)
  char mPad5a[0x2];      // 0x5a — unproven gap
  uint32_t m5c;          // 0x5c — 0 (C1 0x996be4)
  uint32_t m60;          // 0x60 — 0 (C1 0x996be4)
  uint8_t mPad64[4];     // 0x64 - unproven gap
  void* m68;             // 0x68 — 0 (C1 0x996be4)
  uint32_t m70;          // 0x70 — 10000 (0x2710, C1 0x996be4)
  char mPad74[0x4];      // 0x74 — unproven gap
  void* m78;             // 0x78 — 0 (C1 0x996be4)
  uint8_t* m80;          // 0x80 — dim*dim byte array, alloc 0x568aa0 + zero-fill (C1 0x996be4)
  void* m88;             // 0x88 — 0 (C1 0x996be4)
};
}  // namespace nn::pia::session
