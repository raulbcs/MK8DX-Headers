#pragma once

#include <cstdint>

// Vt12d3780 — 12-slot sibling of Vt12d3598; built in place by FUN_710089bad4
// at +0x208 of its object. GOT cell 0x13117f8 holds vt-0x10.
// extent 0x68 - details: doc/object/Vt12d3780.md

namespace object {
class Vt12d3780 {
 public:
  void* mVtable;       // 0x00 — vptr 0x12d3780 (cell 0x13117f8+0x10, 0x89bc8c-0x89bc94)
  uint32_t m8;         // 0x08 — ctor arg w12 (0x89bc50)
  uint32_t mC;         // 0x0c — unproven
  uint32_t m10;        // 0x10 — 0 (0x89bc54)
  uint8_t m14[0x4];    // 0x14 — unproven
  uint8_t m18[0x16];   // 0x18 — 0 (0x89bc64 stp; +0x238/+0x248 stp pairs 0x89bc6c-0x89bc78)
  uint8_t m2E;         // 0x2e — flag w8=1 (0x89bc68)
  uint8_t m2F;         // 0x2f — unproven
  void* m30;           // 0x30 — x9 (0x89bc6c)
  void* m38;           // 0x38 — x20=0xed60af8 (0x89bc70)
  void* m40;           // 0x40 — x9 (0x89bc74)
  void* m48;           // 0x48 — x20 (0x89bc78)
  uint32_t m50;        // 0x50 — 0 (0x89bc7c)
  uint8_t m54;         // 0x54 — flag w8=1 (0x89bc80)
  uint8_t m55[0x3];    // 0x55 — unproven
  void* m58;           // 0x58 — 0 (0x89bc84)
  uint8_t m60;         // 0x60 — 0 (0x89bc88)
  uint8_t m61[0x3];    // 0x61 — unproven
  uint32_t m64;        // 0x64 — 0 (0x89bc9c)
};
}  // namespace object
