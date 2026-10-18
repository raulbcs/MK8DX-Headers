#pragma once

#include <cstdint>

// Vtable of the read-side decoded QuantChannel - ctor FUN_71007ad494 runs the
// Binder head (0x71007aae24), overrides the primary vptr at +0x000, then sets
// numValues*width+4 into +0x1c0/+0x1c4 and installs a _Znam payload at
// +0x280 before tail-calling FUN_71007ab1b8. GOT cell 0x130f8c0 holds
// 0x12c3d90 = vt-0x10. Extends to +0x288 in its (in-place derived) users.
// extent 0x288 (lower bound) - details: doc/recorder/QuantChannelReadVt.md

namespace recorder {
struct QuantChannelReadVt {
  // Slot map (row 0x12c3da0; vptr = row, slots start here):
  //  +0x00 slot 0: 0x71003a8564 (dtor candidate, unverified)
  //  +0x08 slot 1: 0x71003a8630 (92 B dtor candidate)
  //  +0x10..+0x38 slots 2-8: 0x71007adb30..0x71007adb78 (12 B accessors;
  //    slot 8 = getRecorderKeyStr_71007adb78)
  //  +0x40 slot 9: 0x71007ab904 (shared Binder interface)
  //  +0x48 slot 10: 0x71007ad508; +0x50 slot 11: 0x71007ad978 (216 B)
  //  +0x58 slot 12: 0x710001ac84 (shared thunk)
  //  +0x60..+0x78: 0x71003a86e0, 0x71007ad67c, 0x710001ac98, 0x71003a86e8,
  //    0x71007ad688 (64 B), 0x71007adb84
  //  +0x80..+0x98: 0x71007ad6c8 (684 B), 0x710001acd4, 0x71007ada68,
  //    0x710001acf4, 0x71007adaa8 (116 B)
  //  +0xa0..+0xb8: recorderWriteZero4_71007adb1c, 0x71007ad6cc, 0x71003a86f8,
  //    0x71003a86fc, 0x71003a8704, recorderWriteZero_71007adb28
  //  +0xc0..+0xd8: 0x710001ade8, 0x710001adf4, 0x710001adf8, 0x71007ad770,
  //    0x71007ac020
  //  +0x128..: 0x71007aee48..0x71007aef94 accessor run
};
}  // namespace recorder
