#pragma once

#include <cstdint>

namespace nn::pia::lan {
// LanConnectStationJob — RTTI-named (typeinfo 0x12dcad0, name
// "N2nn3pia3lan20LanConnectStationJobE"; base
// nn::pia::transport::ConnectStationJob). 9 slots; GOT cell 0x1313400 holds
// vptr-0x10 (vptr 0x12dca88).
// extent 0x130 - details: doc/_nn/pia/lan/LanConnectStationJob.md
class LanConnectStationJob {
 public:
  void* mVtable;         // 0x00 - vptr 0x12dca88 (cell 0x1313400 + 0x10)
  uint8_t mPad08[0x48];  // 0x08 - base job region (C1 0x9a2264)
  uint64_t m50;          // 0x50 - 0x0100000000000000 (C1 0x974cd8)
  uint8_t mPad58[0x28];  // 0x58 - unproven gap
  uint8_t mSub80[0x38];  // 0x80 - member subobject, C1 0x9b38b8
  uint8_t mSubB8[0x78];  // 0xb8 - member subobject, C1 0x9b1fe8
};
}  // namespace nn::pia::lan
