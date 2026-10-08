#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtd7b0 — address-anchored name (vptr 0x12bd7b0). Multi-channel
// class of the 0x647f40 hook-band cluster: channel-pair members
// (ctor 0x7100662f30/0x7100662f70) at 0x128, 0x148, 0x168, 0x188, 0x1b0, 0x1d0,
// constructed in place at 0x72b9a8. EXTENT APPROXIMATE: last channel
class ParamMultiChanVtd7b0 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0xd8];    // 0x50 — fields/channel region
  char mTail128[0xc8];  // 0x128 — channel array region (to 0x1f0)
                        // (~0x1f0 total, APPROXIMATE)
};
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
