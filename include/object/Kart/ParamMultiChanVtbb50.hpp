#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtbb50 — address-anchored name (vptr 0x12bbb50). Multi-channel
class ParamMultiChanVtbb50 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x458];   // 0x50 — fields/channel region
  char mTail4a8[0xc0];  // 0x4a8 — channel array region (to 0x568)
  char mTail568[0x90];  // 0x568 — chan-pair vptrs 0x570/0x590 (ctor stub),
                        // 0x5b0/0x5d0 (ctor 0x890700); byte mirror
                        // +0x5c8 -> +0x5f0, +0x5e8 -> +0x5f1 (0x890810)
  // (0x5f8 total; proven lower bound 0x5f2, no allocation site —
  // static singleton)
  // extent 0x5f8 (prior-survey total 0x5f8)
};
}  // namespace object
