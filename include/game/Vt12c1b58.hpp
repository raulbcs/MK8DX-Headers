#pragma once

#include <cstdint>

// Vt12c1b58 — small nn-band node, size 0x38 EXACT (operator new(0x38, 8)
// at 0x74cc30, base C1 0x7614e8). Two sibling rows: construction installs
// 0x12c1ba0; the D1/D0 pair and slots 3/4 (re)install this row at [this].
// extent 0x38 - details: doc/game/Vt12c1b58.md
namespace game {
class Vt12c1b58 {
 public:
  void* mVtable;   // 0x00 - row-swapped vptr: base C1 installs 0x12c1ba0;
                   //   D1 0x76150c / D0 0x7615b4 / slots 3-4 install this
                   //   row 0x12c1b58 (GOT cells 0x130f1c0 / 0x130f1b8,
                   //   both hold vptr-0x10)
  uint32_t m08;    // 0x08 - 0 (C1); child count read by 0x76119c
  uint32_t m0c;    // 0x0c - pad
  void* m10;       // 0x10 - 0 (C1); child/head pointer, released via
                   //   vt[1] by the D1 pair
  void* m18;       // 0x18 - 0 (C1); second pointer, released via vt[1]
  float m20;       // 0x20 - 1.0f (C1)
  uint32_t mPad24; // 0x24 - unproven (no store observed)
  void* m28;       // 0x28 - 0 (C1); owned ptr, D1 frees via 0x77fb08
                   //   when non-null before the vt[1] release
  void* m30;       // 0x30 - 0 (C1); owned ptr, same D1 pattern
};
}  // namespace game
