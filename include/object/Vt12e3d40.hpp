#pragma once

#include <cstdint>

// Vt12e3d40 — PLACEHOLDER name (large nn driver-style object); installed vptr 0x12e3d48, 7 slots;
// GOT cell 0x1314680 holds vptr-0x10 (0x12e3d40 is the typeinfo slot, typeinfo 0x12e4800).
// size 0x558 (operator new at 0x9F2604) - details: doc/object/Vt12e3d40.md

namespace object {
class Vt12e3d40 {
 public:
  void* mVtable;           // 0x00 — 0x12e3d48 (via GOT cell 0x1314680)
  uint8_t mPad8[0x2C0];    // 0x08 — unproven (bulk init in FUN_71009FC41C)
  void* m2C8;              // 0x2C8 — list node traded in ctor (old head freed)
  void* m2D0;              // 0x2D0
  void* m2D8;              // 0x2D8
  uint8_t mPad2E0[0x50];   // 0x2E0 — unproven ([0x308]/[0x310]=0, sub-ctor at this+0x2E8)
  void* m330;              // 0x330 — secondary vptr (GOT cell 0x1314690 +0x10)
  uint8_t mPad338[0x100];  // 0x338 — unproven ([0x338]..[0x350]=0)
  void* m438;              // 0x438 — secondary vptr (GOT cell 0x1314698 +0x10)
  uint16_t m440;           // 0x440 — zeroed by ctor
  uint8_t mPad442[0x6];    // 0x442 — unproven
  void* m448;              // 0x448 — owned member, operator new(0x38)
  uint8_t mPad450[0x108];  // 0x450 — unproven padding to 0x558
};
}  // namespace object
