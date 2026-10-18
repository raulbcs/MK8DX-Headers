#pragma once

#include <cstdint>

namespace nn::pia::session {
// CloseParticipationJob — RTTI-named (typeinfo 0x12dead0, name
// "N2nn3pia7session21CloseParticipationJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1313a68 holds
// vptr-0x10 (vptr 0x12dea98).
// extent 0x98 - details: doc/_nn/pia/session/CloseParticipationJob.md
class CloseParticipationJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12dea98 (cell 0x1313a68 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - zeroed by C1, set by 0x99ff10
  uint8_t mSub60[0x20];  // 0x60 - member subobject, C1 0x929ec0
  uint32_t mZero80;      // 0x80 - zeroed by C1
  uint32_t mPad84;       // 0x84 - padding (extent 0x98)
  void* mZero88;         // 0x88 - zeroed by C1
  uint8_t mPad90[0x8];   // 0x90 - zeroed by C1 (extent 0x98)
};
}  // namespace nn::pia::session
