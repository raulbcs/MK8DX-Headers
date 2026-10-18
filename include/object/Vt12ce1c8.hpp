#pragma once

#include <cstdint>

// Vt12ce1c8 — interface row of an nn-network/ldn-style stub family: 8-slot
// abstract table (never installed), singleton stub row 0x12ce218, concrete
// row 0x12ce230 (54 slots) installed by init FUN_71008537b0.
// extent 0x8d0 - details: doc/object/Vt12ce1c8.md

namespace object {
class Vt12ce1c8 {
 public:
  void* vtable;        // 0x00 — concrete vptr 0x12ce230 (init 0x8537b0)
  char mPad8[0x5a8];   // 0x08 — managed by init FUN_71008537b0, unproven
  void* mListHead;     // 0x5b0 — ctor zeroes (0x8537e0)
  void* mListTail;     // 0x5b8 — ctor zeroes (0x8537d4)
  char mPad5c0[0x70];  // 0x5c0 — unproven
  char mNodes[0x150];  // 0x630 — fourteen 0x18-stride intrusive list
                       //        nodes, self-ptrs +0x630/+0x648/../+0x780
                       //        (0x8537f0..0x85385c)
  char mPad780[0x78];  // 0x780 — unproven
  void* mField7f8;     // 0x7f8 — ctor zeroes (0x8537e4)
  char mPad800[0xd0];  // 0x800 — unproven padding to 0x8d0
};
}  // namespace object
