#pragma once

#include <cstdint>

namespace game {
// Unnamed refcounted record with MULTIPLE INHERITANCE: primary base at
// +0x00 (vptr 0x12c9a28) and a sibling-style secondary base at +0x20
// (vptr 0x12c9a78). Both subobjects are stack-constructed by value and
// each passed separately to a scene virtual at vtable offset 0xe8.
// extent 0x38 (stack frame layout in 0x7f66f8) -
// details: doc/game/Vt12c9a28.md
class Vt12c9a28 {
 public:
  void* vtable;      // 0x00 - vptr 0x12c9a28 (GOT cell 0x13103b0 holds
                     // 0x12c9a18 = vptr-0x10); no out-of-line C1
  uint32_t mCount8;  // 0x08 - refcount (shared retain slots 0x7f438c/
                     // 0x7f43a0/0x7f43b4)
  uint8_t mPadC[0x4];  // 0x0c - padding after the u32 refcount
  void* mPtr10;      // 0x10 - retained pointer
  void* mField18;    // 0x18 - zeroed at construction; unproven
  void* vtable2;     // 0x20 - secondary vptr 0x12c9a78 (GOT cell 0x13103b8
                     // holds 0x12c9a68 = vptr-0x10)
  uint32_t mCount28; // 0x28 - secondary refcount (unproven write; zeroed
                     // region)
  uint8_t mPad2c[0x4]; // 0x2c - padding after the u32 refcount
  void* mPtr30;      // 0x30 - secondary retained pointer; zeroed
};
}  // namespace game
