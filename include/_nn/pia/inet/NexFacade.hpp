#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexFacade - RTTI-confirmed (typeinfo slot 0x12d9800 -> record
// 0x12d9880, name exact "N2nn3pia4inet9NexFacadeE"); IFacade at +0x00,
// embedded common::FixedString<8> at +0x10.
// extent 0x160 - details: doc/_nn/pia/inet/NexFacade.md
class NexFacade {
 public:
  void* vtable;       // 0x00 - 0x12d9808 (GOT cell 0x1312870 holds 0x12d97f8 =
                      //   vt-0x8; row 0x12d9800 is the typeinfo slot, installed
                      //   vptr = row+8 = cell+0x10)
  char pad08[0x08];   // 0x08..0x0f - unproven gap (vptr2 lands at +0x10)
  void* vtable2;      // 0x10 - FixedString<8> subobject vptr 0x12d9748 (cell
                      //   0x1312858 holds 0x12d9738 = vt-0x8)
  char pad18[0x9c];   // 0x18..0xb3 - ctor zeroes 0x18/0x24 (0x92d2a0), 0x74..
                      //   0x7f, halfword 0x84, byte 0x86 (0x92d2c8..0x92d2d4)
                      //   and pairs 0x98..0x9f (0x92d324..0x92d34c); unproven
  uint32_t mB4;       // 0xb4 - ctor 5000
  uint32_t mB8;       // 0xb8 - ctor 1500
  char padBC[0x1c];   // 0xbc..0xd7 - unproven gap
  char mD8[0x20];     // 0xd8..0xf7 - 0x20-byte member inited by 0x929ec0 (ctor
                      //   0x92d2a4) / destructed by 0x929ee0 (D1 0x92d3b8 tail)
  char mF8[0x20];     // 0xf8..0x117 - same member type (ctor 0x92d2ac)
  char m118[0x20];    // 0x118..0x137 - same member type (ctor 0x92d254)
  void* m138;         // 0x138 - ctor 0
  char pad140[0x08];  // 0x140 - ctor 0
  void* m148;         // 0x148 - ctor 0
  char pad150[0x08];  // 0x150..0x157 - unproven gap
  uint8_t m158;       // 0x158 - ctor 1
  char pad159[0x03];  // 0x159..0x15b - unproven gap
  uint32_t m15c;      // 0x15c - ctor 0
};
}  // namespace nn::pia::inet
