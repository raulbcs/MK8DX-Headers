#pragma once

#include <cstdint>

// Vt12c7f90 — 9-slot manager-registered node (secondary table 0x12c7fe8 at +0x180),
// allocated 0x298 per element in a factory loop of the Vt12b1480 float-defaults
// family. No RTTI. extent 0x298 - details: doc/object/Vt12c7f90.md

namespace object {
class Vt12c7f90 {
 public:
  void* mVtable;          // 0x00 — primary vptr 0x12c7f90 (GOT cell 0x1310020 holds
                          //        vptr-0x10; factory 0x7d5b60: add #0x10 -> [this])
  uint8_t m8[0x178];      // 0x08 — base sub-object built by 0xa7ee00(this, mgr, i):
                          //        float defaults +0x10.., params +0x100/+0x104, owner
                          //        +0x140, intrusive lists +0x148 (stride +0x15c) and
                          //        +0x160 (stride +0x174), counters +0x158/+0x170
                          //        (factory push at 0x7d5be0-0x7d5bf8, unverified split)
  void* mVtableSecondary; // 0x180 — secondary vptr 0x12c7fe8 (factory 0x7d5b88:
                          //        cell+0x68 -> [this+0x180]); table's offset-to-top
                          //        slot 0x12c7fd8 reads -0x80, mismatch unverified
  uint8_t m188[0x30];     // 0x188 — member, C1 0x8ddd8c(this+0x188) (0x7d5b94),
                          //        destroyed by 0x8ddfdc (slots 2/3 tail)
  uint8_t m1B8[0x44];     // 0x1b8 — unproven; [0x1b8] = 0 (0x7d5ba4)
  uint32_t m1FC;          // 0x1fc — 0 (0x7d5ba8)
  uint32_t m200;          // 0x200 — unproven
  uint32_t m204;          // 0x204 — 0 (0x7d5bac)
  uint8_t m208[0x28];     // 0x208 — unproven
  uint8_t m230[0x5C];     // 0x230 — memset 0, len 0x5c (0x7d5b98-0x7d5bb0)
  uint8_t m28C[0xC];      // 0x28c — unproven tail
};
}  // namespace object
