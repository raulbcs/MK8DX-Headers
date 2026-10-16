#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtb318 — address-anchored name (vptr 0x12bb318). Multi-channel
class ParamMultiChanVtb318 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x210];   // 0x50 — fields/channel region
  char mTail260[0x98];  // 0x260 — channel array region (to 0x2f8)
                        // (~0x2f8 total, APPROXIMATE)
};
}  // namespace object
