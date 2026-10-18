#pragma once

#include <cstdint>

// recorder::MatrixRotChannel6 - quantized "rot" sub-channel (token size 6) of the
// Matrix33f decomposition path: created only by init 0x710088ab18 (new 0x290,
// shared Binder head 0x71007aae24, vptr override at +0x00) and registered under
// the name "rot" (0xf0a965) via recorderAddChannel_71007ac0cc.
// GOT cell 0x1311288 holds 0x12d1a10 = vptr-0x10; vptr = cell + 0x10.
// extent 0x290 - details: doc/recorder/MatrixRotChannel6.md

namespace recorder {
struct MatrixRotChannel6 {
  void* mVtable;          // 0x00 - 0x12d1a20
  uint8_t mPad8[0x1b8];   // 0x08 - unproven padding (RotChannel4-shaped)
  uint8_t mPad1c8[0x28];  // 0x1c8 - unproven padding
  uint32_t mNumValues;    // 0x1c0 - 36 (factory store of 0x24 at 0x88adbc)
  uint32_t mTokenBytes;   // 0x1c4 - 6 (factory store of 6 at 0x88adb0, Comp6 branch)
  uint8_t mPad1fc[0x7c];  // 0x1fc - unproven padding
  float mMin;             // 0x1f0 - factory store 0x88ae0c: 0xc28f3cf5 (~-70.97)
  float mStep;            // 0x1f4 - literal 0xed6858 (0x88adac)
  float mInvStep;         // 0x1f8 - literal 0xed6854 (0x88ada4)
  void* mOwner;           // 0x278 - zeroed at 0x88adfc
  uint8_t mPad280[8];     // 0x280 - zeroed at 0x88ae08
  void* mOwner288;        // 0x288 - factory arg (owning object); read by the
                          //        +0x88 accessor 0x710088af9c
  // Slot map (35 slots, row 0x12d1a20; VMAs, absent from functions.csv):
  //  +0x00 slot 0: 0x7ae584 / +0x08 slot 1: 0x7ae608 (D2/D1 pair, split unverified)
  //  +0x10..+0x40 slots 2-8: 0x88b1bc 0x88b1c8 0x88b1d4 0x88b1e0 0x88b1ec
  //    0x88b1f8 0x88b204 (0xc-byte thunks)
  //  +0x48..+0x58 slots 9-11: 0x7ab904 0x7abca8 0x7ac1d8 (shared Binder set)
  //  +0x60..+0x78 slots 12-15: 0x1ac84 0x1ac8c 0x1ac94 0x1ac98
  //  +0x80 slot 16: 0x88b210 / +0x88 slot 17: 0x88af9c (6x u32 copy from
  //    [this+0x288] to [x1 + [this+0x1d4]])
  //  +0x90 slot 18: 0x88b218 / +0x98 slot 19: 0x88b220
  //  +0xa0..+0xb8 slots 20-23: 0x1acd4 0x7b46a4 0x1acf4 0x7b4714
  //  +0xc0 slot 24: 0x7ac728 / +0xc8 slot 25: 0x7adeac
  //  +0xd0..+0xe8 slots 26-29: 0x7adf64 0x7ae664 0x7ae66c 0x7ae74c
  //  +0xf0..+0x100 slots 30-32: 0x1ade8 0x1adf4 0x1adf8
  //  +0x108 slot 33: 0x7acd90 / +0x110 slot 34: 0x7ac020
};
}  // namespace recorder
