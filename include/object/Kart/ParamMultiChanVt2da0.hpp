#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVt2da0 — address-anchored name (vptr 0x12b2da0). Multi-channel
class ParamMultiChanVt2da0 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0xc0];    // 0x50 — fields/channel region
  char mTail110[0x98];  // 0x110 — channel array region (to 0x1a8)
  char mTail1a8[0xa0];  // 0x1a8 — sub-vptrs 0x1a8/0x1d0, count 0x1f0,
                        // row array ptr 0x1f8, flag 0x1e8, vec3 0x1c0,
                        // aim angles 0x23c/0x240 (slot 15)
  // (0x248 total; proven by allocation size 0x248 at 0x710064f928)
};
}  // namespace object
