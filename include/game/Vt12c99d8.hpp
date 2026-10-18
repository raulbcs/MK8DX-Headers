#pragma once

#include <cstdint>

namespace game {
// Unnamed refcounted record, stack-constructed by value and passed to a
// scene-family virtual at vtable offset 0xe8 (sibling of Vt12c9988 with
// identical layout, different slot bodies). No RTTI.
// extent 0x20 (stack frame layout in 0x7f66b4) -
// details: doc/game/Vt12c99d8.md
class Vt12c99d8 {
 public:
  void* vtable;      // 0x00 - vptr 0x12c99d8 (GOT cell 0x13103a8 holds
                     // 0x12c99c8 = vptr-0x10); constructed inline on the
                     // caller stack, no out-of-line C1
  uint32_t mCount8;  // 0x08 - refcount; ++ by slot 0x7f438c, -- by 0x7f43a0,
                     // cleared by 0x7f43b4
  uint8_t mPadC[0x4];  // 0x0c - padding after the u32 refcount
  void* mPtr10;      // 0x10 - retained pointer; slot 0x7f438c stores x1,
                     // 0x7f43a0 stores x2, 0x7f43b4 zeroes
  void* mField18;    // 0x18 - zeroed at construction; unproven
};
}  // namespace game
