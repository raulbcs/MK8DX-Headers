#pragma once

#include <cstdint>

// Vt12d36a0 — 12-slot sibling of Vt12d3598; built in place by FUN_710089bad4
// at +0x70 and +0x108 of its object. GOT cell 0x13117e8 holds vt-0x10.
// extent 0x68 - details: doc/object/Vt12d36a0.md

namespace object {
class Vt12d36a0 {
 public:
  void* mVtable;       // 0x00 — vptr 0x12d36a0 (cell 0x13117e8+0x10, 0x89bb98-0x89bba0)
  uint32_t m8;         // 0x08 — ctor arg w12 (0x89bb68)
  uint32_t mC;         // 0x0c — unproven
  uint32_t m10;        // 0x10 — 0 (0x89bb6c)
  uint8_t m14[0x4];    // 0x14 — unproven
  uint8_t m18[0x16];   // 0x18 — 0 (0x89bb8c stp; 0x89bb70 stur overlaps)
  uint8_t m2E;         // 0x2e — flag w8=1 (0x89bb74)
  uint8_t m2F;         // 0x2f — unproven
  void* m30;           // 0x30 — x9 (0x89bb90 stp)
  void* m38;           // 0x38 — x20=0xed60af8 (0x89bb90 stp)
  void* m40;           // 0x40 — x9 (0x89bb94 stp)
  void* m48;           // 0x48 — x20 (0x89bb94 stp)
  uint32_t m50;        // 0x50 — 0 (0x89bb44)
  uint8_t m54;         // 0x54 — flag w8=1 (0x89bb48)
  uint8_t m55[0x3];    // 0x55 — unproven
  void* m58;           // 0x58 — 0 (0x89bb1c)
  uint8_t m60;         // 0x60 — 0 (0x89bb4c)
  uint8_t m61[0x3];    // 0x61 — unproven
  uint32_t m64;        // 0x64 — 0 (0x89bb50)
};
}  // namespace object
