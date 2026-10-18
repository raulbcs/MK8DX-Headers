#pragma once

#include <cstdint>

namespace game {
// Derived member of the Vt12c7cc0 family (root 0x6155bc, base init
// 0x7d5164 of Vt12c7de8, then vptr override). Same field layout as the
// base; overrides only the dtor pair and the update slot.
// extent 0xe8 - details: doc/game/Vt12ca7a8.md
class Vt12ca7a8 {
 public:
  void* vtable;  // 0x00 - vptr 0x12ca7a8 (GOT cell 0x13104d8 holds
                 // 0x12ca798 = vptr-0x10)
  uint8_t mBase8[0xe0];  // 0x08 - base Vt12c7de8 body (0x08..0xe7),
                         // see doc/game/Vt12c7de8.md
};
}  // namespace game
