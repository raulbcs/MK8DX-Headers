#pragma once

#include <cstdint>

// Vt12bf3c0 — PLACEHOLDER name (42-slot class, sibling family sharing base
// ctor 0x738d68); vptr 0x12bf3c0 at +0x00, ctor FUN_710073c66c.
// extent 0x98 - details: doc/object/Vt12bf3c0.md

namespace object {
class Vt12bf3c0 {
 public:
  void* vtable;         // 0x00 — 0x12bf3c0 (ctor 0x73c6a4)
  char mPad8[0x68];     // 0x08 — unproven (base-ctor-managed)
  uint8_t mField70;     // 0x70 — ctor zeroes (0x73c6a0)
  uint8_t mField71;     // 0x71 — ctor 1 (0x73c690)
  char mPad72[0x6];     // 0x72 — unproven
  void* mField78;       // 0x78 — ctor zeroes (0x73c694)
  void* mField80;       // 0x80 — ctor zeroes (0x73c698)
  void* mField88;       // 0x88 — ctor zeroes (0x73c698)
  char mPad90[0x8];     // 0x90 — unproven (+0x90 u8 zeroed, 0x73c68c)
};
}  // namespace object
