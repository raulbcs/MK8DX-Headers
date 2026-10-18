#pragma once

#include <cstdint>

// Vt12d80d0 — PLACEHOLDER name; vptr 0x12d80d0 (GOT cell 0x1312560 = vptr-0x10),
// 17 slots, no RTTI; secondary vptr 0x12d83e8 at +0x188; member 0x628628 at +0x1b0.
// extent 0x238 - details: doc/object/Vt12d80d0.md

namespace object {
class Vt12d80d0 {
 public:
  void* mVtable;          // 0x00 — 0x12d80d0
  uint8_t mPad8[0xe8];    // 0x08 — unproven (zeroed/self-ptr region 0x08-0xf0)
  void* mF0;              // 0xf0 — null
  void* mF8;              // 0xf8 — self-ptr {this+0xf8, this+0xf8}
  void* m100;             // 0x100
  uint32_t m108;          // 0x108 — 0
  uint32_t mPad10C;       // 0x10c — unproven padding
  void* m110;             // 0x110 — {0, 0}
  void* m118;             // 0x118
  uint32_t m120;          // 0x120 — 0
  uint32_t mPad124;       // 0x124 — unproven padding
  void* m128;             // 0x128 — self-ptr {this+0x128, this+0x128}
  void* m130;             // 0x130
  uint32_t m138;          // 0x138 — 0
  uint32_t mPad13C;       // 0x13c — unproven padding
  void* m140;             // 0x140 — {0, 0}
  void* m148;             // 0x148
  uint32_t m150;          // 0x150 — 0
  uint32_t mPad154;       // 0x154 — unproven padding
  void* m158;             // 0x158 — self-ptr {this+0x158, this+0x158}
  void* m160;             // 0x160
  uint32_t m168;          // 0x168 — 0
  uint32_t mPad16C;       // 0x16c — unproven padding
  void* m170;             // 0x170 — {0, 0}
  void* m178;             // 0x178
  uint32_t m180;          // 0x180 — 0
  uint32_t mPad184;       // 0x184 — unproven padding
  void* m188;             // 0x188 — secondary vptr 0x12d83e8 (GOT cell 0x13124d0)
  uint8_t mPad190[0x8];   // 0x190 — unproven padding
  uint16_t m198;          // 0x198 — 0
  uint8_t mPad19A[0x6];   // 0x19a — unproven padding
  uint32_t m1A0;          // 0x1a0 — 13
  int32_t m1A4;           // 0x1a4 — -1
  uint16_t m1A8;          // 0x1a8 — 0
  uint8_t mPad1AA[0x6];   // 0x1aa — unproven padding
  uint8_t m1B0[0x40];     // 0x1b0 — embedded member (C0 0x628628)
  uint8_t m1F0[0x20];     // 0x1f0 — zeroed
  uint32_t m210;          // 0x210 — 0xf
  uint8_t m214;           // 0x214 — 0
  uint8_t mPad215[0x23];  // 0x215 — unproven padding (caller stores +0x228)
};
}  // namespace object
