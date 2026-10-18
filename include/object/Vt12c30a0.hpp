#pragma once

#include <cstdint>

// Vt12c30a0 — map-container wrapper class (C1 FUN_71007905e0, heap factory
// FUN_710078ff80: operator new(0x108) at 0x78ffdc). Derived from the sparse
// base vtable 0x12c36e0 (base C1 FUN_710079c4c8). extent 0x108 - details: doc/object/Vt12c30a0.md

namespace object {
class Vt12c30a0 {
 public:
  void* mVtable;          // 0x00 — vptr 0x12c30a0 (cell 0x130f690+0x10)
  void* m8;               // 0x08 — std::__tree begin node = this+0x8 (base C1 0x79c4ec)
  void* m10;              // 0x10 — std::__tree __pair1_ (base C1 0x79c4f4)
  uint32_t m18;           // 0x18 — 0: node count (base C1 0x79c4ec)
  uint32_t m1C;           // 0x1c — -1 (base C1 0x79c4ec)
  uint8_t m20[0x10];      // 0x20 — unproven (base C1 body)
  void* m30;              // 0x30 — from C1 arg x3 (base C1 0x79c4f0)
  uint8_t m38[0xB8];      // 0x38 — unproven (base C1 0x79c4c8 tail)
  uint8_t mF0[0x8];       // 0xf0 — 0 (0x7905f4)
  uint16_t mF8;           // 0xf8 — 0xffff (0x790610)
  uint8_t mFA;            // 0xfa — 0 (0x790600)
  uint8_t mFB[0x5];       // 0xfb — unproven
  void* m100;             // 0x100 — 0 (0x790604)
  uint8_t m108[0];        // end — size 0x108 (operator new at 0x78ffdc)
};
}  // namespace object
