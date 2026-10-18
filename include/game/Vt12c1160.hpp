#pragma once

#include <cstdint>

// Vt12c1160 — nn-band object, size 0xb0 EXACT (operator new(0xb0) at
// 0x8b7bc, C1 0x750fcc). Primary row 0x12c1160 (42 slots); secondary row
// 0x12c12c0 (ot -0xa0) reached through the +0x28 member whose vptr is
// rebranded after construction. extent 0xb0 - details:
// doc/game/Vt12c1160.md
namespace game {
class Vt12c1160 {
 public:
  void* mVtable;      // 0x00 - primary vptr 0x12c1160 (GOT cell 0x130ef38
                      //   holds vptr-0x10 0x12c1150)
  uint8_t m08;        // 0x08 - u8 = 0 (C1)
  uint8_t mPad09[0x7];  // 0x09 - pad (alignment), unproven
  void* m10;          // 0x10 - 0 (C1); child ptr released via vt[1] in D1
  void* m18;          // 0x18 - 0 (C1); page-aligned buffer (memalign
                      //   0x1000 by slot 2), size cached at +0x20
  uint32_t m20;       // 0x20 - 0 (C1); aligned byte size (slot 2)
  uint32_t mPad24;    // 0x24 - unproven (no store observed)
  void* m28;          // 0x28 - member vptr, first cell 0x12fada0+0x10 =
                      //   0x11ad0f8, rebranded by C1 to cell
                      //   0x12fb728+0x10 = 0x11ad270
  uint32_t m30;       // 0x30 - ptr to this+0x3c (C1)
  uint32_t m34;       // 0x34 - unproven
  uint8_t m38[0x4];   // 0x38 - 0 (C1)
  uint8_t m3c[0x14];  // 0x3c - zeroed by C1 ([0x40..0x4f] stp pair, [0x50]
                      //   byte) — member state reached via +0x30 ptr
  uint8_t m50[0x8];   // 0x50 - zeroed by C1 (byte + pad to 0x58)
  uint64_t m58;       // 0x58 - 0 (C1)
  uint64_t m60;       // 0x60 - 0 (C1)
  uint32_t m68;       // 0x68 - 2000 (C1)
  uint32_t m6c;       // 0x6c - 160 (C1)
  float m70;          // 0x70 - 0.5f (C1)
  float m74;          // 0x74 - 0.5f (C1)
  float m78;          // 0x78 - 0.4f (C1)
  float m7c;          // 0x7c - 0.8f (C1)
  float m80;          // 0x80 - 0.3f (C1)
  uint8_t m84[0x2c];  // 0x84 - unproven tail to the extent bound (new
                      //   size 0xb0; no stores observed past +0x84)
};
}  // namespace game
