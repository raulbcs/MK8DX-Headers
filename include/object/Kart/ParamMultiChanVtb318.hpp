#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtb318 — address-anchored name (vptr 0x12bb318). Multi-channel
// class of the 0x647f40 hook-band cluster: channel-pair members
// (ctor 0x7100662f30/0x7100662f70) at 0x260, 0x2d8,
// constructed in place at 0x6fad7c. EXTENT APPROXIMATE: last channel
class ParamMultiChanVtb318 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0x210];   // 0x50 — fields/channel region
  char mTail260[0x98];  // 0x260 — channel array region (to 0x2f8)
                        // (~0x2f8 total, APPROXIMATE)
};
// vtable fact (TU multiChanVtb318NotifyChainSlot14_71006fa874.cpp):
// slot 14 (0x80): (self, void* a, int b, int c, int d) — walks a
// backwards-linked chain seeded from self+0x268 with the signed stride word
// at self+0x274: element pointer starts at head - stride, end marker is
// (self+0x260) - stride, next element is *(elem + stride + 8) - stride.
// For each element with non-null pointer at elem+0x18: sets bit 0x80 of the
// halfword at [* [elem+0x18] +0x10 +0xe28] and invokes that object's
// vtable entry 0xb8 with (a, d).
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
