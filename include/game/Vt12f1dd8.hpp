#pragma once

#include <cstdint>

namespace game {
// Unnamed class; base subobject of a 0x298 derived product (in-place init
// loop, 4 iterations, FUN_71007d5a78 @0x7d5b70-0x7d5c58). Ctor FUN_7100a7ee00.
// extent 0x180 (base class ends where the derived type's secondary vptr
// lands at +0x180; derived product is 0x298) - details: doc/game/Vt12f1dd8.md
class Vt12f1dd8 {
 public:
  void* vtable;           // 0x00 - vptr 0x12f1dd8 (GOT cell 0x1314fd8 holds
                          // 0x12f1dc8 = vptr-0x10; off-top 0, no typeinfo)
  uint8_t mPad8[0x130];   // 0x08 - unproven gap (managed by base ctor 0x635b58)
  uint32_t mField138;     // 0x138 - ctor writes 0x11
  uint8_t mPad13c[0x3c];  // 0x13c - unproven padding
  uint32_t mField178;     // 0x178 - ctor arg w2 (element index, 0..3)
  uint8_t mField17c;      // 0x17c - ctor writes 0; read by slot5 0xa7ee60 (and 1)
  uint8_t mField17d;      // 0x17d - ctor writes 5
  uint8_t mPad17e[0x2];   // 0x17e - unproven padding (to 0x180)
};
}  // namespace game
