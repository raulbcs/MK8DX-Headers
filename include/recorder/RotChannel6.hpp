#pragma once

#include <cstdint>

// recorder::RotChannel6 — quantized "rot" recorder channel, token size 6
// (kind 1 arg of recorderCreateRotTransChannels_71007ae16c; sibling of RotChannel4/Vt12c4240).
// Initialized with recorderBinderCtor_71007aae24 after `new 0x290`; vptr cell 0x130f908.
// extent 0x290 - details: doc/recorder/RotChannel6.md

namespace recorder {
class RotChannel6 {
 public:
  void* mVtable;          // 0x00 — 0x12c4368 (GOT cell 0x130f908 holds 0x12c4358; vptr = cell+0x10)
  uint8_t mPad8[0x1b8];   // 0x08 — unproven padding
  uint32_t mNumValues;    // 0x1c0 — 36
  uint32_t mTokenBytes;   // 0x1c4 — 6 (cf. "RecorderMatrix33fComp6" @0xf0a986, unverified link)
  uint8_t mPad1c8[0x28];  // 0x1c8 — unproven padding
  float mMin;             // 0x1f0 — -70.0f (0x7ae230)
  float mStep;            // 0x1f4 — [0xed6858] (kind 1 path)
  float mInvStep;         // 0x1f8 — [0xed6854]
  uint8_t mPad1fc[0x7c];  // 0x1fc — unproven padding
  uint64_t mZero278;      // 0x278 — zeroed by ctor (0x7ae228)
  uint64_t mZero280;      // 0x280 — zeroed by ctor (0x7ae23c)
  void* mOwner;           // 0x288 — ctor arg x1 (owning ChannelSet/binder), 0x7ae248
};
}  // namespace recorder
