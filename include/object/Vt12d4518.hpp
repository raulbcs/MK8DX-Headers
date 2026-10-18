#pragma once

#include <cstdint>

// Vt12d4518 — PLACEHOLDER name; vptr 0x12d4518 (GOT cell 0x1311a10 = vptr-0x10),
// 17 slots, no RTTI. Four 0x10-byte embedded members at +0x68..+0x98 (C1 0x8c1524).
// extent 0xd0 - details: doc/object/Vt12d4518.md

namespace object {
class Vt12d4518 {
 public:
  void* mVtable;         // 0x00 — 0x12d4518
  uint8_t mPad8[0x60];   // 0x08 — memset(this+8, 0, 0xa0)
  uint8_t m68[0x10];     // 0x68 — embedded member (C0 0x62ee28), stride 0x10
  uint8_t m78[0x10];     // 0x78 — embedded member (C0 0x62ee28)
  uint8_t m88[0x10];     // 0x88 — embedded member (C0 0x62ee28)
  uint8_t m98[0x10];     // 0x98 — embedded member (C0 0x62ee28)
  uint8_t mA8;           // 0xa8 — bool flag (tested by slot8 0x8c1588)
  uint8_t mPadA9[0x27];  // 0xa9 — caller-filled tail (strh at +0xc8 by 0x3fea5c), unproven
};
}  // namespace object
