#pragma once

#include "_nn/pia/session/KickoutManageJob.hpp"

namespace nn::pia::local {
// nn::pia::local::LocalKickoutManageJob — RTTI-confirmed (typeinfo 0x12e1960,
// base pia::session::KickoutManageJob); vptr 0x12e1918 = tsv row + 8.
// extent 0x198 - details: doc/_nn/pia/local/LocalKickoutManageJob.md
class LocalKickoutManageJob : public nn::pia::session::KickoutManageJob {
 public:
  void* m190;  // 0x190 — C1 arg x1 (target object; [x+0x18] used by slots 6/7)
};
}  // namespace nn::pia::local
