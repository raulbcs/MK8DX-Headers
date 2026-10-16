#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVt2c40 — address-anchored name (vptr 0x12d2c40). Multi-channel
class ParamMultiChanVt2c40 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x560];   // 0x50 — fields/channel region
  char mTail5b0[0x40];  // 0x5b0 — channel array region (to 0x5f0)
                        // (~0x5f0 total, APPROXIMATE)
};
}  // namespace object
