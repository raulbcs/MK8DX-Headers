#pragma once

#include <cstdint>

// recorder::ChannelVt12d1208 — Binder-derived recorder channel; ctor
// FUN_7100889814 runs recorderBinderCtor_71007aae24 then overrides the vptr
// (GOT cell 0x13111d0, vptr = cell+0x10). Factories allocate 0x288.
// extent 0x288 - details: doc/recorder/ChannelVt12d1208.md

namespace recorder {
class ChannelVt12d1208 {
 public:
  void* mVtable;          // 0x00 — 0x12d1208
  uint8_t mPad8[0x270];   // 0x08 — Binder head fields (see doc/recorder/BinderVt.md)
  void* mTarget278;       // 0x278 — ctor arg x1 (object with +0x120 member, unverified)
  uint8_t mFlag280;       // 0x280 — busy/done flag, set to 1 by slot10 helper
  uint8_t mFlag281;       // 0x281 — ctor arg w2 & 1
  uint8_t mPad282[0x6];   // 0x282 — unproven padding
};
}  // namespace recorder
