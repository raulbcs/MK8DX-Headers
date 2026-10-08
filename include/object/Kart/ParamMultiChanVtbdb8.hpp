#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtbdb8 — address-anchored name (vptr 0x12bbdb8). Multi-channel
// class of the 0x647f40 hook-band cluster: channel-pair members
// (ctor 0x7100662f30/0x7100662f70) at 0x260, 0x278, 0x298, 0x2b8, 0x2d8, 0x2f8,
// constructed in place at 0x705f4c. EXTENT APPROXIMATE: last channel
class ParamMultiChanVtbdb8 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x210];   // 0x50 — fields/channel region
  char mTail260[0xb8];  // 0x260 — channel array region (to 0x318)
                        // (~0x318 total, APPROXIMATE)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
