#pragma once

#include <cstdint>

// Vt12c3298 — map-container wrapper class, sibling of Vt12c30a0 (C1 0x792744,
// heap factory FUN_7100792448: operator new(0x128) at 0x7924a4). Same sparse
// base vtable 0x12c36e0 (base C1 FUN_710079c4c8). extent 0x128 - details: doc/object/Vt12c3298.md

namespace object {
class Vt12c3298 {
 public:
  void* mVtable;          // 0x00 — vptr 0x12c3298 (cell 0x130f6d0+0x10)
  void* m8;               // 0x08 — std::__tree begin node = this+0x8 (base C1 0x79c4ec)
  void* m10;              // 0x10 — std::__tree __pair1_ (base C1 0x79c4f4)
  uint32_t m18;           // 0x18 — 0: node count (base C1 0x79c4ec)
  uint32_t m1C;           // 0x1c — -1 (base C1 0x79c4ec)
  uint8_t m20[0x10];      // 0x20 — unproven (base C1 body)
  void* m30;              // 0x30 — from C1 arg x3 (base C1 0x79c4f0)
  uint8_t m38[0x98];      // 0x38 — unproven (base C1 0x79c4c8 tail)
  uint8_t mD0;            // 0xd0 — flags byte, bit6 set from arg[0x40]
                          //        (0x792774/0x792784-0x792798)
  uint8_t mD1[0x1F];      // 0xd1 — unproven
  void* mF0;              // 0xf0 — from arg[0x48] (0x79279c-0x7927a0)
  void* mF8;              // 0xf8 — 0 (0x792768)
  uint8_t m100;           // 0x100 — 0 (0x79276c)
  uint8_t m101[0x7];      // 0x101 — unproven
  void* m108;             // 0x108 — 0 (0x792780)
  void* m110;             // 0x110 — 0 (0x792770 pair)
  void* m118;             // 0x118 — 0 (0x792770 pair)
  void* m120;             // 0x120 — 0 (0x792770 stp covers +0x118/+0x120)
  uint8_t m128[0];        // end — size 0x128 (operator new at 0x7924a4)
};
}  // namespace object
