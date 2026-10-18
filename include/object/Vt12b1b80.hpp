#pragma once

#include <cstdint>

// Vt12b1b80 — KartParamCache-family object (C1 0x63a558, factory new(0x1888)
// at 0x63cce8). Primary interface vptr 0x12b1b58 at +0x00; this row is the
// secondary interface at +0x08 (offset-to-top -8). extent 0x1888 - details: doc/object/Vt12b1b80.md

namespace object {
class Vt12b1b80 {
 public:
  void* mIface0;          // 0x00 — primary vptr 0x12b1b58 (cell 0x130d818+0x10)
  void* mVtable;          // 0x08 — secondary vptr 0x12b1b80 (cell 0x130d818+0x38)
  void* m10;              // 0x10 — rodata pointer 0xed6af8 (0x631974, shared factory path)
  uint32_t m18;           // 0x18 — 0
  uint32_t m1C;           // 0x1c — 0
  uint32_t m20;           // 0x20 — 0
  uint32_t m24;           // 0x24 — 0 (unproven)
  uint8_t m28[0x48];      // 0x28 — member inited by 0x62875c(this+0x28, 1) (0x63199c)
  uint8_t m70[0x168];     // 0x70 — unproven (C1 continues at 0x63a558)
  uint32_t m1D8;          // 0x1d8 — 0 (0x63a588)
  uint8_t mPad1DC[0x4];   // 0x1dc — unproven
  void* m1E0;             // 0x1e0 — 0 (0x63a594)
  uint32_t m1E8;          // 0x1e8 — 0 (0x63a598)
  uint32_t mPad1EC;       // 0x1ec — unproven
  uint8_t m1F0[0x78];     // 0x1f0 — member inited by 0x645934 (0x63a5ac)
  float m268;             // 0x268 — -4.0f (0x63a5b4)
  float m26C;             // 0x26c — 2.0f (0x63a5c8)
  float m270;             // 0x270 — 3.0f (0x63a5c0)
  float m274;             // 0x274 — -1.0f (0x63a5d0)
  uint8_t m278[0x24];     // 0x278 — unproven
  uint8_t m29C;           // 0x29c — 0 (0x63a5dc)
  uint8_t mPad29D[0x23];  // 0x29d — unproven
  void* m2C0;             // 0x2c0 — 0 (0x63a5e0)
  uint32_t m2C8;          // 0x2c8 — 0 (0x63a5e4)
  uint32_t mPad2CC;       // 0x2cc — unproven
  void* m2D0;             // 0x2d0 — set by C1 (0x63a604)
  uint8_t m2D8[0x30];     // 0x2d8 — unproven
  void* m308;             // 0x308 — set by C1 (0x63a610)
  uint8_t m310[0x1578];   // 0x310 — unproven tail: C1 builds members out to ~0x1594
                          //        (0x63a618-0x63a70c); object read at +0x2b8 by the
                          //        primary-interface method 0x63c0c4
};
}  // namespace object
