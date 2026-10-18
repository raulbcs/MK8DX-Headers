#pragma once

#include <cstdint>

// Vtable of recorder::Binder (layout authority: include/recorder/Recorder.hpp,
// shared head ctor 0x71007aae24). Primary row installed at +0x000; GOT cell
// 0x130f7d0 holds 0x12c3ae8 = vt-0x10. 25+ slots; slot 0/1 dtor pair is
// unrecovered (candidates 0x3a8a0c/0x3a8a7c, unverified).
// extent 0x288 - details: doc/recorder/BinderVt.md

namespace recorder {
struct BinderVt {
  // Slot map (row 0x12c3af8; vptr = row, slots start here):
  //  +0x00 slot 0: 0x71003a8a0c (dtor candidate, unverified)
  //  +0x08 slot 1: 0x71003a8a7c (dtor candidate, unverified)
  //  +0x10..+0x38 slots 2-5: 0x71007ad0ec (600 B) + small FUNs
  //    0x71007ad0f8..0x71007ad134
  //  +0x40..+0x50 slots 6-8: 0x71007ab904, 0x71007abca8, 0x71007ac1d8
  //    (shared with the QuantChannel rows below)
  //  +0x58 slot 9: 0x710001ac84 (= sead::ExpHeap::isResizable thunk cluster)
  //  +0x60..+0x78: 0x710001ac8c, recorderChannelFlag0_71003afce8, ...
  //  +0x80..+0xb0: 0x710001acd4, 0x71000a13d0, 0x710001acf4, 0x71000a1404
  //  +0xb8 slot 22: 0x71007ac728; tail: 0x71003a8b44, 0x71003a86fc, 0x710001addc,
  //    0x71007acd90, 0x71007ac020 (read-side accessors shared by the family)
};
}  // namespace recorder
