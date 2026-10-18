#pragma once

#include <cstdint>

// Vt12d5630 — 12-slot container interface; only its own D1/D0 thunks reference
// the vptr (no C1 found). GOT cell 0x1311cf8 holds vt-0x10.
// extent 0x28 (lower bound; dtor path touches +0x20) - details:
// doc/object/Vt12d5630.md

namespace object {
class Vt12d5630 {
 public:
  void* mVtable;       // 0x00 — vptr 0x12d5630 (cell 0x1311cf8+0x10, thunks 0x8d52c4/0x8d64f8)
  uint32_t m8;         // 0x08 — unproven (elem stride 0xC base used by slot2)
  uint32_t mC;         // 0x0c — u32 written by slot8/slot9 (0x8d5358)
  uint32_t m10;        // 0x10 — count (slots 0x8d63f0/0x8d6410); container head
  uint8_t m14[0x4];    // 0x14 — unproven
  void* m18;           // 0x18 — elem array ptr (0x8d63fc; freed by D0 helper 0x60b994)
  uint8_t m20;         // 0x20 — flag byte (slot8/slot9 store, 0x8d5348)
  uint8_t m21[0x7];    // 0x21 — unproven
};
}  // namespace object
