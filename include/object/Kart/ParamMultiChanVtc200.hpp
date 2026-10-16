#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtc200 — address-anchored name (vptr 0x12bc200). Multi-channel
class ParamMultiChanVtc200 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x458];   // 0x50 — fields/channel region
  char mTail4a8[0xa8];  // 0x4a8 — channel array region (to 0x550)
                        // (~0x550 total, APPROXIMATE)
};
}  // namespace object
