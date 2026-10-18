#pragma once

#include <cstdint>

// Vt12c34f0 — PLACEHOLDER name (15-slot member of a 6-vtable factory family
// FUN_7100795178, subtype switch w22=3); vptr 0x12c34f0 at +0x00.
// extent 0x30 (lower bound) - details: doc/object/Vt12c34f0.md

namespace object {
class Vt12c34f0 {
 public:
  void* vtable;      // 0x00 — 0x12c34f0 (factory 0x795238..0x795254; base
                     //        ctor 0x7a4ee0 first installs 0x12c39e0)
  void* mField8;     // 0x08 — base ctor zeroes (0x7a4eec)
  void* mField10;    // 0x10 — base ctor zeroes (0x7a4eec)
  void* mField18;    // 0x18 — base ctor zeroes (0x7a4eec)
  void* mField20;    // 0x20 — base ctor zeroes (0x7a4ef4)
  uint32_t mField28; // 0x28 — base ctor zeroes (0x7a4ee0)
  char mPad2C[0x4];  // 0x2C — unproven (sibling subtypes write -1 here)
};
}  // namespace object
