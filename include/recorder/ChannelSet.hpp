#pragma once

#include <cstdint>

// recorder::ChannelSet — recorder channel group; base-subobject ctor
// recorderCreateRotTransChannels_71007ae16c creates two child channels ("rot"/"trans")
// and registers them via recorderAddChannel_71007ac0cc. Single site: vptr cell 0x130f8f8.
// extent 0x288 - details: doc/recorder/ChannelSet.md

namespace recorder {
class ChannelSet {
 public:
  void* mVtable;          // 0x00 — 0x12c3ec8 (GOT cell 0x130f8f8 holds 0x12c3eb8; vptr = cell+0x10)
  uint8_t mPad8[0x1cc];   // 0x08 — unproven padding
  int32_t mWriteIdx;      // 0x1d4 — index added to the out pointer in the +0x110 writer slots
                          //        (recorderWrite3Ints_71007ae328/71007ae350 ldrsw [this+0x1d4])
  uint8_t mPad1d8[0xa0];  // 0x1d8 — unproven padding
  void* mChanRot;         // 0x278 — "rot" channel (Vt12c4240 kind0 / Vt12c4368 kind1), zeroed first
  void* mChanTrans;       // 0x280 — "trans" channel (Vt12c3ff0 kind0 / Vt12c4118 kind1), zeroed first
};
}  // namespace recorder
