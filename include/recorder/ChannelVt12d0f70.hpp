#pragma once

#include <cstdint>

// recorder::ChannelVt12d0f70 — Binder-family recorder channel with no dedicated
// ctor: objects from FUN_7100883158 get recorderBinderCtor_71007aae24, then the
// vptr is stored manually from GOT cell 0x1311138 (vptr = cell+0x10).
// extent 0x288 - details: doc/recorder/ChannelVt12d0f70.md

namespace recorder {
class ChannelVt12d0f70 {
 public:
  void* mVtable;          // 0x00 — 0x12d0f70 (cell 0x1311138 holds 0x12d0f60)
  uint8_t mPad8[0x270];   // 0x08 — Binder head fields (see doc/recorder/BinderVt.md)
  void* mDescriptor;      // 0x278 — pointer into caller's descriptor array ([x19+0x48] + 0x18/0x1a/0x28)
  uint8_t mPad280[0x8];   // 0x280 — unproven padding
};
}  // namespace recorder
