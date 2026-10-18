#pragma once

#include <cstdint>

namespace object {
// Vt12b0bb8 — PLACEHOLDER name (no RTTI; derived from Vt12b0b18). Plain vptr
// row at 0x12b0bb8 (offset-to-top/typeinfo 0), GOT cell 0x130d470 holds
// vt-0x10, 20 slots; override-ctor 0x629270 stores a delegate at +0xf8.
// extent 0x100 (unverified lower bound) - details: doc/object/Vt12b0bb8.md
class Vt12b0bb8 {
 public:
  void* vtable;           // 0x00 - 0x12b0bb8 (cell 0x130d470 + 0x10)
  char pad08[0xf0];       // 0x08..0xf7 - Vt12b0b18 base layout (vptr cell
                          //   0x130d468; name +0x28, state +0xcc); unproven
  void* mF8;              // 0xf8 - delegate target stored by override-ctor
                          //   0x629270 (its slot0 receives (this, arg))
};
}  // namespace object
