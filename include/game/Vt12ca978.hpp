#pragma once

#include <cstdint>

namespace game {
// Derived member of the Vt12c7cc0 family (root 0x6155bc, base init
// 0x7d3184 of Vt12c7c70, then vptr override). Same field layout as the
// base; overrides the dtor pair and two update wrappers.
// extent 0xf8 - details: doc/game/Vt12ca978.md
class Vt12ca978 {
 public:
  void* vtable;  // 0x00 - vptr 0x12ca978 (GOT cell 0x1310508 holds
                 // 0x12ca968 = vptr-0x10)
  uint8_t mBase8[0xf0];  // 0x08 - base Vt12c7c70 body (0x08..0xf7),
                         // see doc/game/Vt12c7c70.md
};
}  // namespace game
