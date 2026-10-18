#pragma once

#include <cstdint>

namespace nn::pia::lan {
// LanMatchBrowseMatchmakeJob — RTTI-named (typeinfo 0x12dcc50, name
// "N2nn3pia3lan26LanMatchBrowseMatchmakeJobE"; base
// nn::pia::session::BrowseMatchmakeJob). 9 slots; GOT cell 0x1313420 holds
// vptr-0x10 (vptr 0x12dcc08).
// extent 0x88 - details: doc/_nn/pia/lan/LanMatchBrowseMatchmakeJob.md
class LanMatchBrowseMatchmakeJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12dcc08 (cell 0x1313420 + 0x10)
  uint8_t mPad08[0x58];  // 0x08 - base job region (C1 0x97dc58)
  uint8_t mSub60[0x20];  // 0x60 - member subobject, C1 0x929ec0
  void* mZero80;         // 0x80 - zeroed by C1
};
}  // namespace nn::pia::lan
