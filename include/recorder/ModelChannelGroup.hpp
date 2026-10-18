#pragma once

#include <cstdint>

// recorder::ModelChannelGroup - per-model recorder channel group (size 0x298):
// ctor 0x710088b76c copies four channel pointers from its init param to
// +0x278..+0x290 and conditionally spawns sub-channels; created by actor-side
// factories (e.g. new 0x298 + ctor at 0x88e250 / 0x3567dc).
// GOT cell 0x1311398 holds 0x12d1b38 = vptr-0x10; vptr = cell + 0x10.
// extent 0x298 - details: doc/recorder/ModelChannelGroup.md

namespace recorder {
struct ModelChannelGroup {
  void* mVtable;            // 0x00 - 0x12d1b48
  uint8_t mPad8[0x270];     // 0x08 - unproven padding (Binder head + fields)
  void* mChannel0;          // 0x278 - init param [x1+0x00] (ctor 0x710088b76c)
  void* mChannel1;          // 0x280 - init param [x1+0x08]; non-null gates the
                            //        ModelMatrixChannel child
  void* mChannel2;          // 0x288 - init param [x1+0x10]
  uint64_t mParam290;       // 0x290 - init param [x1+0x18]; its bytes +0x291..
                            //        +0x296 double as the per-subchannel enable
                            //        flags read by the ctor (unverified split)
  // Slot map (35 slots, row 0x12d1b48; VMAs, absent from functions.csv):
  //  +0x00 slot 0: 0x3a8a0c / +0x08 slot 1: 0x3a8a7c (D2/D1 pair, split unverified)
  //  +0x10..+0x40 slots 2-8: 0x88bf18 0x88bf24 0x88bf30 0x88bf3c 0x88bf48
  //    0x88bf54 0x88bf60 (0xc-byte thunks)
  //  +0x48..+0x58 slots 9-11: 0x7ab904 0x7abca8 0x7ac1d8 (shared Binder set)
  //  +0x60 slot 12: 0x88ba2c (reads [this+0x278]) / +0x68 slot 13: 0x88bf6c
  //  +0x70 slot 14: 0x88ba3c / +0x78 slot 15: 0x88ba50
  //  +0x80..+0x98 slots 16-19: 0x3afce8 0x3afcf0 0x3afcf4 0x3afcfc
  //    (recorderChannelFlag0 / recorderNoop set, cf. doc/recorder/ChannelSet.md)
  //  +0xa0..+0xb8 slots 20-23: 0x1acd4 0xa13d0 0x1acf4 0xa1404
  //  +0xc0 slot 24: 0x7ac728 / +0xc8 slot 25: 0x3a8b44
  //  +0xd0..+0xe0 slots 26-28: 0x3a8b48 0x3a86fc 0x3a8704
  //  +0xe8 slot 29: 0x1addc / +0xf0 slot 30: 0x88ba64
  //  +0xf8..+0x100 slots 31-32: 0x1adf4 0x1adf8
  //  +0x108 slot 33: 0x7acd90 / +0x110 slot 34: 0x7ac020
};
}  // namespace recorder
