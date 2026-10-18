#pragma once

#include <cstdint>

// object::Vt12d8ee0 — PLACEHOLDER name. C1 0x90f514 (allocates 0x1068, runs base
// ctor 0x91636c, installs vptr, allocates a 0x20 tick companion); vptr 0x12d8ee0,
// GOT cell 0x1312310 holds vt-0x10. extent 0x1068 - details: doc/object/Vt12d8ee0.md

namespace object {
class Vt12d8ee0 {
 public:
  void* vtable;         // 0x00 — 0x12d8ee0, installed by C1 0x90f544 after base ctor 0x91636c
  char mPad8[0x28];     // 0x08 — base-ctor-managed (flags 0x8/0x9, zeroed 0x10..0x38), unproven
  void* mTick;          // 0x30 — 0x20 tick companion (vptr 0x12d8e70), C1 stores 0x90f578
  char mPad38[0x1030];  // 0x38 — unproven padding to 0x1068
};
}  // namespace object
