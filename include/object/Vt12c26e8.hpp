#pragma once

#include <cstdint>

// Vt12c26e8 — placeholder name (theme unproven; stream-parse family, slot2
// 0x756940 shared with Vt12c13d8/Vt12c17a0/Vt12c2a40). C1 0x779ce4, vptr
// 0x12c26e8 at +0x00. Size 0xf0 (new 0xf0 at 0x7662d4).
// extent 0xf0 - details: doc/object/Vt12c26e8.md

namespace object {
class Vt12c26e8 {
 public:
  void* mVtable;         // 0x00 — vptr 0x12c26e8 (C1 0x779e64-0x779e68)
  uint8_t m8[0x58];      // 0x08 — parse base: member 0x61c9bc(this+0x08, this+0x18),
                         //         0x28 buffer self-ptr, count u32 @0x2c;
                         //         delimiter scan against byte cell 0x12fada8
  uint8_t m60[0x20];     // 0x60 — self-referential pair (both = this+0x60,
                         //         0x779e54-0x779e58); zeroed 0x70/0x78
  float m80;             // 0x80 — 1.0f (0x779e98)
  float m84;             // 0x84 — 0.0f
  float m88;             // 0x88 — 1.0f (0x779e9c)
  float m8c;             // 0x8c — 1.0f
  uint16_t m90;          // 0x90 — u16 0 (0x779e60)
  uint8_t mPad92[0x2];   // 0x92 — unproven
  float m94;             // 0x94 — 200.0f (0x43480000, 0x779e70)
  float m98;             // 0x98 — 300.0f (0x43960000)
  float m9c;             // 0x9c — 100.0f (0x42c80000)
  float ma0;             // 0xa0 — 800.0f (0x44480000)
  float ma4;             // 0xa4 — 10.0f (0x41200000)
  float ma8;             // 0xa8 — 0.1f (0x3dcccccd, 0x779ea8)
  uint8_t mPadAc[0x44];  // 0xac — tail: double 200.0 built at 0x779ea4 (target
                         //         unverified); to extent 0xf0
};
}  // namespace object
