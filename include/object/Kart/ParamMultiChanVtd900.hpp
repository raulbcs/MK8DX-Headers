#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtd900 — address-anchored name (vptr 0x12bd900). Multi-channel
class ParamMultiChanVtd900 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x278];   // 0x50 — fields/channel region
  char mTail2c8[0xb0];  // 0x2c8 — channel array region (to 0x378)
                        // (~0x378 total, APPROXIMATE)
};
}  // namespace object
