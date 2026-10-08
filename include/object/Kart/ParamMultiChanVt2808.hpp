#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVt2808 — address-anchored name (vptr 0x12b2808). Multi-channel
// class of the 0x647f40 hook-band cluster: channel-pair members
// (ctor 0x7100662f30/0x7100662f70) at 0x110, 0x130, 0x150, 0x170, 0x198,
// constructed in place at 0x64c994. EXTENT APPROXIMATE: last channel
class ParamMultiChanVt2808 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0xc0];    // 0x50 — fields/channel region
  char mTail110[0xa8];  // 0x110 — channel array region (to 0x1b8)
                        // (~0x1b8 total, APPROXIMATE)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
