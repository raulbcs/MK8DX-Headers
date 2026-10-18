#pragma once

#include <cstdint>

// nn::pia::local::LocalMatchUpdateSessionSettingJob — RTTI-confirmed
// (typeinfo 0x12e1e10, "N2nn3pia5local33LocalMatchUpdateSessionSettingJobE");
// base nn::pia::session::UpdateSessionSettingJob (vptr 0x12de9b8). 10 slots.
// extent 0x98 - details: doc/_nn/pia/local/LocalMatchUpdateSessionSettingJob.md

namespace nn::pia::local {
class LocalMatchUpdateSessionSettingJob {
 public:
  void* mVtable;        // 0x00 — 0x12e1db8 (GOT cell 0x1314110 = vptr-0x10)
  char mJobBase8[0x50]; // 0x08 — job-base C1 0xb4a5e0 region (unproven)
  void* mField58;       // 0x58 — 0 (base C1 0x99f4e4)
  char mSub60[0x20];    // 0x60 — 0x20-byte sub-object ctor 0x929ec0 (0x99f518)
  char mPad80[0x14];    // 0x80 — unproven (ctor writes nothing)
  uint32_t mField94;    // 0x94 — 0 (derived C1 FUN_71009d2de0, 0x9d2dfc)
};
}  // namespace nn::pia::local
