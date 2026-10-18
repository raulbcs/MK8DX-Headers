#pragma once

#include <cstdint>

// Vt12ce888 — PLACEHOLDER name; 44-slot base class of Vt12ce718 (shared ctor
// FUN_710085664c). vptr 0x12ce888 at +0x00.
// extent 0x918 - details: doc/object/Vt12ce888.md

namespace object {
class Vt12ce888 {
 public:
  void* vtable;         // 0x00 — 0x12ce888 (base-ctor phase 0x7100856674)
  char mPad8[0x50];     // 0x08 — unproven
  char mArray58[0xe0];  // 0x58 — {ptr,u16,...} elements, ctor-zeroed stride 0x18
  char mPad138[0x7e0];  // 0x138 — unproven (allocated 0x918 with derived Vt12ce718)
};
}  // namespace object
