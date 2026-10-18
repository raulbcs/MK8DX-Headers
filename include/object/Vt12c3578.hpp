#pragma once

#include <cstdint>

// Vt12c3578 — PLACEHOLDER name; subtype case 4 of the 6-way factory
// FUN_7100795178; vptr installed at 0x795268 (GOT cell 0x130f710 = vt-0x10).
// extent 0x30 (lower bound) - details: doc/object/Vt12c3578.md

namespace object {
class Vt12c3578 {
 public:
  void* vtable;      // 0x00 — 0x12c3578 (base ctor 0x7a4ee0 first installs 0x12c39e0)
  void* mField8;     // 0x08 — zeroed by base ctor 0x7a4ee0
  void* mField10;    // 0x10 — zeroed by base ctor 0x7a4ee0
  void* mField18;    // 0x18 — zeroed by base ctor 0x7a4ee0
  void* mField20;    // 0x20 — zeroed by base ctor 0x7a4ee0
  uint32_t mField28; // 0x28 — zeroed by base ctor 0x7a4ee0
  int32_t mField2C;  // 0x2C — -1 written by factory 0x795274
};
}  // namespace object
