#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexNatRelay — RTTI-named (typeinfo 0x12d9ba0, name string
// "N2nn3pia4inet11NexNatRelayE"); 0xcc0-byte heap object new'd by the NAT-relay
// manager factory (0x710092ce00). Primary vptr 0x12d9a08 (GOT cell 0x13128e0
// holds 0x12d99f8 = vt-0x10), secondary vptr 0x12d9af0 at +0x28.
// extent 0xcc0 - details: doc/_nn/pia/inet/NexNatRelay.md
class NexNatRelay {
 public:
  void* vtable;         // 0x00 - 0x12d9a08 (cell 0x13128e0 + 0x10)
  char pad08[0x20];     // 0x08..0x27 - four heap blocks from ctor 0x710092f400
                        //   (new 0x18 -> +0x08, new 0x70 -> +0x10, new 0x90 ->
                        //   +0x18, new 0xc0 -> +0x20); unproven
  char pad28[0x10];     // 0x28..0x37 - NexNatRelayInterface subobject (secondary
                        //   vptr 0x12d9af0 = cell 0x13128e8 + 0x10; base ctor
                        //   0x71009ea9a8, D2 0x71009ea9bc)
  void* mSelf38;        // 0x38 - ctor stores this (stp x19,x8 [x19,#0x38])
  void* m40;            // 0x40 - ctor stores [this+0x20]
  void* m48;            // 0x48 - new 0xc0, init 0x7100a2bf88
  void* m50;            // 0x50 - new 0x48, member with vptr cell 0x130b4a8
  char pad58[0x08];     // 0x58..0x5f - third base subobject (ctor 0x7100929fd4,
                        //   dtor 0x710092a014); unproven
  uint32_t m60;         // 0x60 - ctor zero
  char pad64[0x1c];     // 0x64..0x7f - unproven gap
  char pad80[0x10];     // 0x80..0x8f - ctor zeroes +0x80/+0x88 then inits via
                        //   0x710056810c (sync primitive pair)
  char pad90[0x1c];     // 0x90..0xab - ctor zeroes 0x98..0xab; rest unproven
  uint32_t mAc;         // 0xac - ctor zero; sign-extended and added to entry
                        //   pointers in the ctor/dest loops
  void* mB0;            // 0xb0 - entry-array base == this+0xbc
  uint32_t mB8;         // 0xb8 - ctor sets 0x40
  char mEntries[0xbd0]; // 0xbc..0xc8b - 63 x 0x30 entries, zeroed by ctor loop
                        //   0x710092f4a8..0x710092f4d4
  char padC8c[0x34];    // 0xc8c..0xcbf - tail slack to the 0xcc0 allocation
                        //   (0x710092cdfc); unproven
};
}  // namespace nn::pia::inet
