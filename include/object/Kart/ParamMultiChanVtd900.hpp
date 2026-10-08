#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtd900 — address-anchored name (vptr 0x12bd900). Multi-channel
// class of the 0x647f40 hook-band cluster: channel-pair members
// (ctor 0x7100662f30/0x7100662f70) at 0x2c8, 0x2f0, 0x318, 0x338, 0x358,
// constructed in place at 0x72c384. EXTENT APPROXIMATE: last channel
class ParamMultiChanVtd900 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x278];   // 0x50 — fields/channel region
  char mTail2c8[0xb0];  // 0x2c8 — channel array region (to 0x378)
                        // (~0x378 total, APPROXIMATE)
};
// vtable fact (TU vtd900VtGetterSlot10_710072e15c.cpp): slot 10 (0x60) is a
// guard-initialised static vtable getter — on first call stores descriptor
// cell 0x710130e180 (+0x10) into cache cell 0x710130e188 (guard byte
// 0x710130e178) and returns the cached vtable pointer.
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
