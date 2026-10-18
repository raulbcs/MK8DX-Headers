#pragma once

#include <cstdint>

// nn::pia::lan::LanMatchUpdateSessionSettingJob — RTTI-confirmed (typeinfo
// 0x12dd1d0, "N2nn3pia3lan31LanMatchUpdateSessionSettingJobE"); base
// nn::pia::session::UpdateSessionSettingJob (vptr 0x12de9b8). 10 slots.
// extent 0x98 - details: doc/_nn/pia/lan/LanMatchUpdateSessionSettingJob.md

namespace nn::pia::lan {
class LanMatchUpdateSessionSettingJob {
 public:
  void* mVtable;        // 0x00 — 0x12dd178 (GOT cell 0x1313620 = vptr-0x10)
  char mJobBase8[0x50]; // 0x08 — job-base C1 0xb4a5e0 region (unproven)
  void* mField58;       // 0x58 — 0 (base C1 0x99f4e4)
  char mSub60[0x20];    // 0x60 — 0x20-byte sub-object ctor 0x929ec0 (0x99f518)
  char mPad80[0x8];     // 0x80 — unproven (ctor writes nothing)
  void* mField88;       // 0x88 — 0 (derived C1 FUN_7100979448, 0x979464)
  char mPad90[0x8];     // 0x90 — unproven
};
}  // namespace nn::pia::lan
