#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtda50 — address-anchored name (vptr 0x12bda50). Multi-channel
class ParamMultiChanVtda50 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x278];   // 0x50 — fields/channel region
  char mTail2c8[0xb8];  // 0x2c8 — channel array region (to 0x380)
                        // (~0x380 total, APPROXIMATE)
};
}  // namespace object
