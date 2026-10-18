#pragma once

#include <cstdint>

// recorder::RotChannel4 — quantized "rot" recorder channel, token size 4
// (kind 0 arg of recorderCreateRotTransChannels_71007ae16c; sibling of RotChannel6/Vt12c4368).
// Initialized with recorderBinderCtor_71007aae24 after `new 0x290`; vptr cell 0x130f900.
// extent 0x290 - details: doc/recorder/RotChannel4.md

namespace recorder {
class RotChannel4 {
 public:
  void* mVtable;          // 0x00 — 0x12c4240 (GOT cell 0x130f900 holds 0x12c4230; vptr = cell+0x10)
  uint8_t mPad8[0x1b8];   // 0x08 — unproven padding
  uint32_t mNumValues;    // 0x1c0 — 36 (matches recorderWrite9Ints_71007ae378: 9x u32)
  uint32_t mTokenBytes;   // 0x1c4 — 4 (cf. "RecorderMatrix33fComp4" @0xf0a96f, unverified link)
  uint8_t mPad1c8[0x28];  // 0x1c8 — unproven padding
  float mMin;             // 0x1f0 — -70.0f (0x7ae230)
  float mStep;            // 0x1f4 — [0xed685c] (kind 0 path)
  float mInvStep;         // 0x1f8 — [0xed6854]
  uint8_t mFlag1fc;       // 0x1fc — zeroed by caller 0x3ad6ec
  uint8_t mPad1fd[0x7b];  // 0x1fd — unproven padding
  uint64_t mZero278;      // 0x278 — zeroed by ctor (0x7ae228)
  uint64_t mZero280;      // 0x280 — zeroed by ctor (0x7ae23c)
  void* mOwner;           // 0x288 — ctor arg x1 (owning ChannelSet/binder), 0x7ae248
};
}  // namespace recorder
