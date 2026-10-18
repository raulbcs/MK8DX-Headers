#pragma once

#include <cstdint>

// Vt12bf520 — PLACEHOLDER name (42-slot class, sibling family sharing base
// ctor 0x738d68); vptr 0x12bf520 at +0x00, ctor FUN_710073cb90.
// extent 0x98 - details: doc/object/Vt12bf520.md

namespace object {
class Vt12bf520 {
 public:
  void* vtable;         // 0x00 — 0x12bf520 (ctor 0x73cbb4)
  char mPad8[0x68];     // 0x08 — unproven (base-ctor-managed)
  char mPad70[0x10];    // 0x70 — unproven (+0x70/+0x78 pointers zeroed, 0x73cbc4)
  void* mField80;       // 0x80 — ctor zeroes (0x73cbb0)
  void* mField88;       // 0x88 — ctor zeroes (0x73cbb0)
  uint32_t mField90;    // 0x90 — ctor 0x04010100 (0x73cbb8)
  char mPad94[0x4];     // 0x94 — unproven
};
}  // namespace object
