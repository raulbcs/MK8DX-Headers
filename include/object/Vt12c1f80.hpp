#pragma once

#include <cstdint>

// Vt12c1f80 — placeholder name (theme unproven; stream-parse family, member C1s
// 0x75481c). C1 0x76c534, vptr 0x12c1f80 at +0x00 and secondary vptr vt+0x78 at
// +0x08. Size 0x198 (new 0x198 align 8 at 0x76eb1c).
// extent 0x198 - details: doc/object/Vt12c1f80.md

namespace object {
class Vt12c1f80 {
 public:
  void* mVtable;      // 0x00 — vptr 0x12c1f80 (C1 0x76c608-0x76c610, stp)
  void* m8;           // 0x08 — secondary vptr 0x12c1ff8 = vt+0x78
  void* m10;          // 0x10 — cell 0x12fae28+0x10 (0x76c574-0x76c578)
  void* m18;          // 0x18 — rodata float-table 0xed60af8
  void* m20;          // 0x20 — base vptr cell 0x130f2e0+0x10 (0x76c550-0x76c570);
                      //        re-stamped 0x12fada0+0x10 at 0x76c598
  void* m28;          // 0x28 — self+0x34 (0x76c56c)
  uint32_t m30;       // 0x30 — 0x20 (0x76c59c)
  uint8_t m34[0x24];  // 0x34 — buffer (self+0x34 base); parsed like Vt12c13d8;
                      //        unproven detail
  uint8_t m58[0x10];  // 0x58 — zeroed (0x76c5f0); 0x58 written by helper
                      //        0x76c4c0 (lookup 0x750a0c/0x766944)
  uint16_t m68;       // 0x68 — 0 (0x76c5e8); flag bit helpers at 0x76c4f4
  uint16_t mPad6a;    // 0x6a — unproven
  uint32_t m6c;       // 0x6c — unverified
  uint32_t m70;       // 0x70 — 0 (0x76c5e0); u16 flag set/clear helper 0x76c4f4
  uint32_t mPad74;    // 0x74 — unproven
  void* m78;          // 0x78 — 0 (0x76c5ec); setter 0x76c514
  void* m80;          // 0x80 — self+0x80, self-referential pair (0x76c614-0x76c618)
  void* m88;          // 0x88 — self+0x80
  uint8_t m90[0x8];   // 0x90 — 0 (0x76c5e4)
  uint32_t m98;       // 0x98 — 0 (0x76c5f4); byte @0x98 = 1 (0x76c61c-0x76c620)
  uint32_t mPad9c;    // 0x9c — unproven
  void* ma0;          // 0xa0 — 0 (0x76c5f4-0x76c5fc)
  uint32_t ma8;       // 0xa8 — 0 (0x76c5f8)
  uint32_t mPadac;    // 0xac — unproven
  void* mb0;          // 0xb0 — 0 (0x76c5fc)
  uint32_t mb8;       // 0xb8 — 0 (0x76c600-0x76c604)
  uint32_t mPadbc;    // 0xbc — unproven
  uint8_t mc0[0x10];  // 0xc0 — zeroed (0x76c604)
  uint64_t md0;       // 0xd0 — 0x3f800000 (1.0f bits, 0x76c624-0x76c628)
  uint32_t md8;       // 0xd8 — 0 (0x76c62c)
  uint8_t mdc[0xbc];  // 0xdc — unverified; member C1 0x75481c at +0xf8 and
                      //        the next member (0x76c630-0x76c63c), to extent
};
}  // namespace object
