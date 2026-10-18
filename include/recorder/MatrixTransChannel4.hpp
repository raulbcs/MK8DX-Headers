#pragma once

#include <cstdint>

// recorder::MatrixTransChannel4 - quantized "trans" sub-channel (token size 4) of
// the Matrix33f decomposition path: created only by init 0x710088ab18 (new 0x288,
// shared Binder head 0x71007aae24, vptr override at +0x00) and registered under
// the name "trans" (0xf0a969) via recorderAddChannel_71007ac0cc.
// GOT cell 0x1311298 holds 0x12d17c0 = vptr-0x10; vptr = cell + 0x10.
// extent 0x288 - details: doc/recorder/MatrixTransChannel4.md

namespace recorder {
struct MatrixTransChannel4 {
  void* mVtable;          // 0x00 - 0x12d17d0
  uint8_t mPad8[0x1b8];   // 0x08 - unproven padding (RotChannel4-shaped)
  uint8_t mPad1c8[0x28];  // 0x1c8 - unproven padding
  uint32_t mNumValues;    // 0x1c0 - 12 (factory store of 0xc at 0x88ae94)
  uint32_t mTokenBytes;   // 0x1c4 - 4 (factory store of 4 at 0x88ae60, Comp4 branch)
  uint8_t mPad1fc[0x7c];  // 0x1fc - unproven padding
  float mMin;             // 0x1f0 - 0.2f (0x88aed8: 0x3e4cccd)
  float mStep;            // 0x1f4 - 16.0f (0x88aec8: 0x41800000)
  float mInvStep;         // 0x1f8 - 0.0625f (0x88aecc: 0x3d800000)
  void* mOwner;           // 0x278 - zeroed at 0x88ae8c
  void* mOwner280;        // 0x280 - factory arg (owning object); read by the
                          //        +0x88 accessor 0x710088af1c
  // Slot map (35 slots, row 0x12d17d0; VMAs, absent from functions.csv):
  //  +0x00 slot 0: 0x7b5414 / +0x08 slot 1: 0x7b54e0 (D2/D1 pair, split unverified)
  //  +0x10..+0x40 slots 2-8: 0x88b080 0x88b08c 0x88b098 0x88b0a4 0x88b0b0
  //    0x88b0bc 0x88b0c8 (0xc-byte thunks)
  //  +0x48..+0x58 slots 9-11: 0x7ab904 0x7abca8 0x7ac1d8 (shared Binder set)
  //  +0x60..+0x78 slots 12-15: 0x1ac84 0x1ac8c 0x1ac94 0x1ac98
  //  +0x80 slot 16: 0x88b0d4 / +0x88 slot 17: 0x88af1c (3x u32 copy from
  //    [this+0x280] to [x1 + [this+0x1d4]])
  //  +0x90 slot 18: 0x88b0dc / +0x98 slot 19: 0x88b0e4
  //  +0xa0..+0xb8 slots 20-23: 0x1acd4 0x7b45a4 0x1acf4 0x7b462c
  //  +0xc0 slot 24: 0x7ac728 / +0xc8 slot 25: 0x7b42ec
  //  +0xd0..+0xe0 slots 26-28: 0x7ae84c 0x7ae850 0x7ae858
  //  +0xe8..+0x100 slots 29-32: 0x1addc 0x1ade8 0x1adf4 0x1adf8
  //  +0x108 slot 33: 0x7acd90 / +0x110 slot 34: 0x7ac020
};
}  // namespace recorder
