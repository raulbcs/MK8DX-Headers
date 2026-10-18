#pragma once

#include <cstdint>

// recorder::TransChannel6 — quantized "trans" recorder channel, token size 6
// (kind 0 arg of recorderCreateRotTransChannels_71007ae16c; sibling of TransChannel4/Vt12c4118).
// Initialized with recorderBinderCtor_71007aae24 after `new 0x288`; vptr cell 0x130f918.
// extent 0x288 - details: doc/recorder/TransChannel6.md

namespace recorder {
class TransChannel6 {
 public:
  void* mVtable;          // 0x00 — 0x12c3ff0 (GOT cell 0x130f918 holds 0x12c3fe0; vptr = cell+0x10)
  uint8_t mPad8[0x1b8];   // 0x08 — unproven padding
  uint32_t mNumValues;    // 0x1c0 — 12 (matches recorderWrite3Ints_71007ae328: 3x u32)
  uint32_t mTokenBytes;   // 0x1c4 — 6 (cf. "RecorderMatrix33fComp6" @0xf0a986, unverified link)
  uint8_t mPad1c8[0x28];  // 0x1c8 — unproven padding
  float mMin;             // 0x1f0 — 0.2f (0x7ae30c)
  float mStep;            // 0x1f4 — 16.0f (0x7ae2f8)
  float mInvStep;         // 0x1f8 — 0.0625f (0x7ae300)
  uint8_t mPad1fc[0x7c];  // 0x1fc — unproven padding
  uint64_t mZero278;      // 0x278 — zeroed by ctor (0x7ae2c0)
  void* mOwner;           // 0x280 — ctor arg x1 (owning ChannelSet/binder), 0x7ae2d0
};
}  // namespace recorder
