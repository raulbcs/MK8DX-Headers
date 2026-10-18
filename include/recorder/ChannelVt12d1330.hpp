#pragma once

#include <cstdint>

// recorder::ChannelVt12d1330 — Binder-derived recorder channel; ctor
// FUN_7100889910 runs recorderBinderCtor_71007aae24 then overrides the vptr
// (GOT cell 0x13111d8, vptr = cell+0x10). Factory allocates 0x290.
// extent 0x290 - details: doc/recorder/ChannelVt12d1330.md

namespace recorder {
class ChannelVt12d1330 {
 public:
  void* mVtable;          // 0x00 — 0x12d1330
  uint8_t mPad8[0x1b8];   // 0x08 — Binder head fields (see doc/recorder/BinderVt.md)
  uint32_t mNumValues;    // 0x1c0 — 4 (ctor 0x889954)
  uint32_t mTokenBytes;   // 0x1c4 — 8 (ctor 0x889954)
  uint8_t mPad1c8[0xb0];  // 0x1c8 — unproven padding
  void* mSource278;       // 0x278 — ctor copies [arg+0]
  void* mBuffer280;       // 0x280 — ctor copies [arg+8]; indexed by slot17 reader
  uint64_t mCursor288;    // 0x288 — zeroed by ctor, -1 by slot10 helper
};
}  // namespace recorder
