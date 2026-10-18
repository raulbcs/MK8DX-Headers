#pragma once

#include <cstdint>

// object::Vt12d8fb0 — PLACEHOLDER name. C1 0x90f590 (allocates 0x428, runs base
// ctor 0x9104bc, installs vptr, allocates a 0x20 tick companion); vptr 0x12d8fb0,
// GOT cell 0x1312320 holds vt-0x10. extent 0x428 - details: doc/object/Vt12d8fb0.md

namespace object {
class Vt12d8fb0 {
 public:
  void* vtable;        // 0x00 — 0x12d8fb0, installed by C1 0x90f5c0 after base ctor 0x9104bc
  char mPad8[0x8];     // 0x08 — base-ctor-managed (twin of Vt12d8ee0 layout), unproven
  void* mTick;         // 0x10 — 0x20 tick companion (vptr 0x12d8ea8), C1 stores 0x90f5f4
  char mPad18[0x410];  // 0x18 — unproven padding to 0x428
};
}  // namespace object
