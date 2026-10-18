#pragma once

#include <cstdint>

// recorder::ModelMatrixChannel - 0x2e0 child of recorder::ModelChannelGroup:
// built by the folded ctor 0x71007b100c (Binder head + four channel ptrs from
// param + zeroed +0x298..+0x2c8 + counter from 0x12fb148) with the primary
// vptr overridden afterwards to this row; parent group stored at +0x2d8.
// GOT cell 0x13113c8 holds 0x12d1c60 = vptr-0x10; vptr = cell + 0x10.
// extent 0x2e0 - details: doc/recorder/ModelMatrixChannel.md

namespace recorder {
struct ModelMatrixChannel {
  void* mVtable;          // 0x00 - 0x12d1c70 (overrides the folded ctor's row)
  uint8_t mPad8[0x270];   // 0x08 - unproven padding (Binder head + fields)
  void* mOwner;           // 0x278 - from init param [x1+0x00] (ctor 0x7b100c)
  void* mPad280[2];       // 0x280..0x288 - from init param [x1+0x08/0x10]
  void* mPad290;          // 0x290 - from init param [x1+0x18]
  uint8_t mPad298[0x40];  // 0x298..0x2d0 - zeroed by the folded ctor (0x7b107c..
                          //              0x7b1080), counter words at +0x2a0..
                          //              +0x2ac from 0x12fb148
  void* mParentGroup;     // 0x2d8 - owning ModelChannelGroup (0x88b9fc)
  // Slot map (35 slots, row 0x12d1c70; VMAs, absent from functions.csv):
  //  +0x00 slot 0: 0x7b2824 / +0x08 slot 1: 0x7b28f0 (D2/D1 pair, split unverified)
  //  +0x10..+0x40 slots 2-8: 0x88bf74 0x88bf80 0x88bf8c 0x88bf98 0x88bfa4
  //    0x88bfb0 0x88bfbc (0xc-byte thunks)
  //  +0x48..+0x58 slots 9-11: 0x7ab904 0x7b1438 0x7ac1d8 (shared Binder set;
  //    middle slot differs from the sibling rows)
  //  +0x60..+0x78 slots 12-15: 0x1ac84 0x1ac8c 0x1ac94 0x1ac98
  //  +0x80 slot 16: 0x88bfc8 / +0x88 slot 17: 0x88ba74
  //  +0x90 slot 18: 0x88bfd0 / +0x98 slot 19: 0x88ba78
  //  +0xa0..+0xb8 slots 20-23: 0x1acd4 0xa13d0 0x1acf4 0xa1404
  //  +0xc0 slot 24: 0x7ac728 / +0xc8 slot 25: 0x3a8b44
  //  +0xd0..+0xe0 slots 26-28: 0x3a8b48 0x3a86fc 0x3a8704
  //  +0xe8..+0x100 slots 29-32: 0x1addc 0x1ade8 0x1adf4 0x1adf8
  //  +0x108 slot 33: 0x7acd90 / +0x110 slot 34: 0x7ac020
};
}  // namespace recorder
