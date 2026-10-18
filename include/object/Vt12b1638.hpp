#pragma once

#include <cstdint>

// Vt12b1638 — PLACEHOLDER name; vptr 0x12b1638, n=32, primary table.
// Base class of Vt12b1510; complete ctor FUN_71006336a8, string buffer + marker ptrs at +0x80/+0x88.
// extent 0x90 - details: doc/object/Vt12b1638.md

namespace object {
class Vt12b1638 {
 public:
  void* mVtable;           // 0x00 — 0x12b1638 (via GOT cell 0x130d6c8, holds vt-0x10)
  uint8_t mPad8[0x38];     // 0x08 — unproven padding
  void* m40;               // 0x40 — 0x11ad0f8 (GOT cell 0x12fada0 addend+0x10; unverified role)
  void* m48;               // 0x48 — self-pointer this+0x54 (ctor 0x6336f4)
  uint32_t m50;            // 0x50 — ctor stores 0x20 (0x63370c)
  uint8_t mPad54[4];       // 0x54 — unproven padding
  uint8_t m58[0x24];       // 0x58 — sub-object region initialized via 0x61cc48
  uint32_t m7C;            // 0x7C — zeroed by ctor
  void* m80;               // 0x80 — 0x11ad210 (GOT cell 0x12fae28, addend+0x10; unverified role)
  void* m88;               // 0x88 — copy of ctor caller's [x19+8]
};

}  // namespace object
