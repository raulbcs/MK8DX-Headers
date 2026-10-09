#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVtbb50 — address-anchored name (vptr 0x12bbb50). Multi-channel
// class of the 0x647f40 hook-band cluster: channel-pair members
// (ctor 0x7100662f30/0x7100662f70) at 0x4a8, 0x4c8, 0x4e8, 0x508, 0x528, 0x548,
// constructed in place at 0x705c4c. EXTENT ~0x5f8 (lower bound 0x5f2
// proven): ctor variant 0x890700 writes +0x5b0/+0x5d0, helper 0x890810
// copies bytes +0x5c8 -> +0x5f0 and +0x5e8 -> +0x5f1; no operator-new
// site exists — the class is a guard-protected static singleton (cell
// 0x71012fed60), so 0x5f8 is the 8-byte rounding of the 0x5f2 bound.
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
};
// vtable facts (TUs multiChanBb50InitCtorSlot0_7100706540.cpp,
// paramMultiChanVtbb50StaticInstanceSlot10_7100706c40.cpp):
//   slot 0 (0x10): vtable-init ctor stub — stamps cell 0x130d918 (+0x10)
//     into the 24 member sub-vptrs at +0x278/+0x298/+0x2b8/+0x2d8/+0x2f8/
//     +0x320/+0x348/+0x370/+0x390/+0x3b0/+0x3d0/+0x3f0/+0x410/+0x430/
//     +0x450/+0x478/+0x4a8/+0x4c8/+0x4e8/+0x508/+0x528/+0x548/+0x570/
//     +0x590; sets self+0x0 from cell 0x130e5e0 (+0x10) and self+0x30 from
//     the same cell (+0x108); tail-calls
//     paramNodeModelBindingCompleteDtorSlot0_710073305c.
//   slot 10 (0x60): guard-protected static singleton getter — guard cell
//     0x71012fed58, instance cell 0x71012fed60 initialised to
//     [0x71012fd3d0]+0x10; returns the instance pointer.
// EXTENT RESOLVED (was: ~0x568 vs >= 0x598): the 0x568 claim is wrong.
// Proven writes: ctor stub stamps sub-vptrs up to +0x590; complete-ctor
// variant 0x7100890700 writes +0x5b0/+0x5d0 before tail-calling the
// stub; helper 0x7100890810 writes bytes +0x5f0/+0x5f1. Extent >= 0x5f2;
// header uses 0x5f8 (8-byte rounding). AMBIGUOUS REMAINDER: no operator
// new site exists for this class — the only instance is the guard-
// protected static singleton (instance cell 0x71012fed60, getter slot
// 10), so the exact allocation size cannot be read from a new(size);
// 0x5f8 is the rounded proven bound, not an allocation-size proof.
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
