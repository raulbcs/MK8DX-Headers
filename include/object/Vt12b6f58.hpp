#pragma once

#include <cstdint>

// Vt12b6f58 — PLACEHOLDER name; vptr 0x12b6f58, 8 slots, no typeinfo (game-side).
// Shared polymorphic base: complete C2 0x6c6128 is reused verbatim by several derived ctors.
// extent 0x248 - details: doc/object/Vt12b6f58.md

namespace object {
class Vt12b6f58 {
 public:
  void* mVtable;             // 0x00 — 0x12b6f58 (via GOT cell 0x130e218, holds vt-0x10)
  void* mZero8;              // 0x08 — C2 stores 0 here (C2 doubles as base-ctor: stp vptr, xzr)
  uint8_t mPad10[0x10];      // 0x10 — member subobject initialized by 0x654990 (own vptr via cell 0x130d830)
  uint8_t mPad20[0x228];     // 0x20 — unproven; derived members start at +0x248
};
}  // namespace object
