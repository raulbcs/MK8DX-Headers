#pragma once

#include <cstdint>

namespace nn::pia::session {
// OpenParticipationJob — RTTI-named (typeinfo 0x12deb90, name
// "N2nn3pia7session20OpenParticipationJobE"; base
// nn::pia::common::StepSequenceJob). 6 slots; GOT cell 0x1313aa8 holds
// vptr-0x10 (vptr 0x12deb58).
// extent 0x90 - details: doc/_nn/pia/session/OpenParticipationJob.md
class OpenParticipationJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12deb58 (cell 0x1313aa8 + 0x10)
  uint8_t mPad08[0x50];  // 0x08 - base job region (C1 0xb4a5e0)
  void* mPtr58;          // 0x58 - zeroed by C1, set by 0x9a087c
  uint8_t mSub60[0x20];  // 0x60 - member subobject, C1 0x929ec0
  uint32_t mZero80;      // 0x80 - zeroed by C1
  uint32_t mPad84;       // 0x84 - padding (extent 0x90)
  void* mZero88;         // 0x88 - zeroed by C1
};
}  // namespace nn::pia::session
