#pragma once

#include <cstdint>

namespace object {
// ParamMultiChanVt2da0 — address-anchored name (vptr 0x12b2da0). Multi-channel
// class of the 0x647f40 hook-band cluster: channel-pair members
// (ctor 0x7100662f30/0x7100662f70) at 0x110, 0x138, 0x160, 0x188,
// constructed in place at 0x64d7e4. EXTENT APPROXIMATE: last channel
class ParamMultiChanVt2da0 {
 public:
  void* vtable;         // 0x00
  uint8_t pad08[0x28];  // 0x08 — unproven padding
  char mChan30[0x20];   // 0x30 — first channel-pair member
  char mMid50[0xc0];    // 0x50 — fields/channel region
  char mTail110[0x98];  // 0x110 — channel array region (to 0x1a8)
                        // (~0x1a8 total, APPROXIMATE)
};
// vtable facts (TUs paramMultiChanVt2da0CompleteDtorSlot0_710064dc0c.cpp,
// paramMultiChanVt2da0DeletingDtorSlot1_710064dcec.cpp,
// multiChanVt2da0AllocArraySlot11_710064dddc.cpp,
// multiChanVt2da0WriteRowSlot13_710064df70.cpp,
// multiChanVt2da0ApplySlot14_710064de44.cpp,
// multiChanVt2da0ComputeAnglesSlot15_710064e0bc.cpp):
//   slots 0 (0x10) / 1 (0x18): complete / deleting dtor — free the array at
//     self+0x1f8 and clear 0x1f8/0x1f0, install the static vptr from cell
//     0x710130d9e8 (+0x10), store cell+0xd8 into self+0x30, reset the six
//     member sub-vptrs (0x110, 0x138, 0x160, 0x188, 0x1a8, 0x1d0) to
//     [0x710130d918]+0x10, run base cleanup 0x71006472c8 (slot 1 then
//     operator delete(this)).
//   slot 11 (0x68): (self, int count, void* src) — when count >= 1,
//     allocates count * 12 bytes via heap allocator FUN_710060b3fc (heap
//     handle from cell 0x712fae80); stores count at self+0x1f0 and the
//     array at self+0x1f8.
//   slot 13 (0x78): writes the vec3 at self+0x1c0 into row w3 of the float
//     table at self+0x1f8 when the flag byte at self+0x1e8 is set and w3 is
//     below the self+0x1f0 count (row stride 12 bytes); flag clear takes a
//     cold path that transforms the row by the 3x3 argument (x1) and
//     tail-calls the writer continuation 0x710064e030.
//   slot 14 (0x80): applies the tint colors self+0x128 / self+0x150 /
//     self+0x178 scaled by the intensity at self+0x1a0 (sead
//     Color4f*float) into a stack staging block; optionally folds in an
//     inverse affine transform (flag self+0x1e8; x2 through
//     recorderInvertAffine3x4_71000c9c64, multiplied with the vec3 at
//     self+0x1c0); forwards to renderer entry 0x710064797c.
//   slot 15 (0x88): computes aim angles from the vec3 at self+0x1c0 (NaN
//     guarded); yaw (atan2-style) at self+0x23c, pitch (acos-style of
//     inv*y clamped to [-1,1]) at self+0x240.
// NOTE (extent): the header above claims ~0x1a8 (APPROXIMATE), but the dtor
// resets a sub-vptr at 0x1d0, and slots 13/15 write self+0x1f0/0x1f8/0x23c/
// 0x240 — implying extent >= 0x244. Contradiction unresolved; the higher
// offsets rest on the TU evidence above.
}  // namespace object

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
