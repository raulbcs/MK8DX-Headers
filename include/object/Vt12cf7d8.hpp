#pragma once

#include <cstdint>

// Vt12cf7d8 — PLACEHOLDER name; vptr 0x12cf7d8 (GOT cell 0x1310f18 = vptr-0x10),
// 17 slots, no RTTI. In-place member only (installed at outer+0x38 by C1 0x86838c).
// extent 0xf0 (lower bound; deepest store +0xe8) - details: doc/object/Vt12cf7d8.md

namespace object {
class Vt12cf7d8 {
 public:
  void* mVtable;         // 0x00 — 0x12cf7d8
  uint8_t mPad8[0x50];   // 0x08 — memset(this+8, 0, 0x50)
  float m58;             // 0x58 — 1.0f
  uint32_t mPad5c;       // 0x5c — zeroed by C1
  void* m60;             // 0x60 — null
  float m68;             // 0x68 — 1.0f
  uint32_t mPad6c;       // 0x6c — zeroed by C1
  void* m70;             // 0x70 — null
  float m78;             // 0x78 — 1.0f
  uint32_t mPad7c;       // 0x7c — zeroed by C1
  void* m80;             // 0x80 — null
  void* m88;             // 0x88 — span begin = this+0x58
  void* m90;             // 0x90 — span end = this+0x7c
  void* m98;             // 0x98 — [cfg cell 0x12fb058]
  uint32_t mA0;          // 0xa0 — [cfg cell 0x12fb058 + 8]
  uint16_t mPadA4;       // 0xa4 — zeroed (stur xzr 0xa4)
  uint16_t mA6;          // 0xa6 — 7
  uint32_t mPadA8;       // 0xa8 — zeroed (stur xzr 0xa4 covers 0xa4-0xab)
  uint64_t mAc;          // 0xac — zeroed
  uint32_t mB4;          // 0xb4 — 0
  uint8_t mPadB8[0x30];  // 0xb8 — unproven padding
  uint32_t mE8;          // 0xe8 — 0
  uint8_t mPadEC[0x4];   // 0xec — unproven padding to 0xf0
};
}  // namespace object
