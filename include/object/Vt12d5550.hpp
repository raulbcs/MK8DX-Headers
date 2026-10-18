#pragma once

#include <cstdint>

// object::Vt12d5550 - PLACEHOLDER name. Large zero-initialized subsystem
// object lazily created with new 0x888 by the manager-init helper at
// 0x8c1814; in-place ctor 0x8cd08c (vptr + memset). Trivial D2 (slot 0).
// extent 0x888 - details: doc/object/Vt12d5550.md

namespace object {
class Vt12d5550 {
 public:
  void* vtable;           // 0x00 - 0x12d5550 (C1 0x8cd08c at 0x8cd0a0; GOT
                          //        cell 0x1311c70 holds vt-0x10)
  uint8_t pad_08[0x880];  // 0x08 - 0x887 - zeroed by C1 memset(x0+8, 0,
                          //        0x880) (0x8cd0a4..0x8cd0ac) - unproven
};
}  // namespace object
