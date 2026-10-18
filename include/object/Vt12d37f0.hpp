#pragma once

#include <cstdint>

// Vt12d37f0 — 12-slot sibling of Vt12d3598; built in place by FUN_710089bad4
// at +0x47a8 of its object. GOT cell 0x1311808 holds vt-0x10.
// extent 0xa8 (lower bound; ctor stores to +0xa7) - details:
// doc/object/Vt12d37f0.md

namespace object {
class Vt12d37f0 {
 public:
  void* mVtable;       // 0x00 — vptr 0x12d37f0 (cell 0x1311808+0x10, 0x89bdcc-0x89bdd4)
  uint32_t m8;         // 0x08 — -1 (0x89bd50-0x89bd54)
  uint32_t mC;         // 0x0c — unproven
  uint32_t m10;        // 0x10 — 0 (0x89bd68)
  uint8_t m14[0x4];    // 0x14 — unproven
  void* m18;           // 0x18 — 0 (0x89bd7c)
  void* m20;           // 0x20 — 0 (0x89bd80)
  uint8_t m28[0x6];    // 0x28 — unproven
  uint8_t m2E;         // 0x2e — 1 (0x89bd84, w9=1)
  uint8_t m2F;         // 0x2f — unproven
  void* m30;           // 0x30 — ptr (cell 0x12fa000+0xe28, 0x89bd88-0x89bd94)
  void* m38;           // 0x38 — x20=0xed60af8 (0x89bda0)
  void* m40;           // 0x40 — same ptr as +0x30 (0x89bd98)
  void* m48;           // 0x48 — x20 (0x89bda4)
  uint32_t m50;        // 0x50 — 0 (0x89bda8)
  uint8_t m54;         // 0x54 — 1 (0x89bdb0-0x89bdb4)
  uint8_t m55[0x3];    // 0x55 — unproven
  void* m58;           // 0x58 — 0 (0x89bdb8)
  uint8_t m60;         // 0x60 — 0 (0x89bdbc-0x89bdfc)
  uint8_t m61[0x3];    // 0x61 — unproven
  uint32_t m64;        // 0x64 — 0 (0x89bdc0-0x89bdc4)
  uint8_t m68[0x40];   // 0x68 — zero window +0x4810..+0x484f (0x89bdf4-0x89be04)
};
}  // namespace object
