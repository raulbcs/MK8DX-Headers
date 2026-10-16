#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtc0f0 — address-anchored name (vptr 0x12bc0f0). Multi-channel
class ParamMultiChanVtc0f0 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x220];   // 0x50 — fields/channel region
  char mTail270[0xc0];  // 0x270 — channel array region (to 0x330)
                        // (~0x330 total, APPROXIMATE)
};
}  // namespace object
