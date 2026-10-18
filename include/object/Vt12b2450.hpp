#pragma once

#include <cstdint>

// Vt12b2450 — KartParamCache-family object (variant C1 0x6489bc, in-place;
// outer aggregates 0x16a0/0xa40 bytes deep build it). Triple interface:
// primary 0x12b23a0 at +0x00, 0x12b2408 at +0x38, this row at +0x90
// (offset-to-top -0x90). extent 0x490 (lower bound) - details: doc/object/Vt12b2450.md

namespace object {
class Vt12b2450 {
 public:
  void* mVtable;           // 0x00 — primary vptr 0x12b23a0 (variant C1 0x648a38);
                           //        base variant C1 0x64897c stores 0x12b2380 instead
  uint8_t m8[0x30];        // 0x08 — unproven
  void* m38;               // 0x38 — secondary vptr 0x12b2408 (cell 0x130d958+0x78)
  uint8_t m40[0x50];       // 0x40 — unproven
  void* m90;               // 0x90 — this row: secondary vptr 0x12b2450
                           //        (cell 0x130d958+0xc0, ot -0x90)
  uint8_t m98[0x1c8];      // 0x98 — unproven (variant C1 body 0x6489bc-0x648a48)
  uint32_t m260;           // 0x260 — 0 (0x648a08)
  uint8_t mPad264[0x4];    // 0x264 — unproven
  void* m268;              // 0x268 — 0 (0x648a40)
  uint32_t m270;           // 0x270 — 0 (0x648a34)
  uint32_t mPad274;        // 0x274 — unproven
  void* m278;              // 0x278 — 0 (0x648a18)
  uint32_t m280;           // 0x280 — 0 (0x648a14)
  uint32_t mPad284;        // 0x284 — unproven
  uint32_t m288;           // 0x288 — 0x3f800000 (1.0f, 0x648a2c)
  uint8_t m28C[0x4];       // 0x28c — unproven
  uint8_t m290[0x40];      // 0x290 — member inited by 0x628628 (0x648a48)
  uint32_t m2D0;           // 0x2d0 — 0 (0x648a34 region, second store)
  uint8_t mPad2D4[0x184];  // 0x2d4 — unproven; 0x64a708(this+0x2d0) at 0x648a50;
                           //        zero run +0x458..+0x480 (0x648a58-0x648a6c)
  uint8_t m458[0x30];      // 0x458 — zeroed by variant C1 (0x648a58-0x648a6c)
  uint8_t m488[0x8];       // 0x488 — zeroed tail of the run (to extent bound)
};
}  // namespace object
