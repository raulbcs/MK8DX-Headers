#pragma once

#include <cstdint>

namespace nn::pia::inet {
// InetProcessHostMigrationJob — RTTI-named (typeinfo 0x12da930, name
// "N2nn3pia4inet27InetProcessHostMigrationJobE"; base typeinfo
// nn::pia::session::ProcessHostMigrationJob). 19 slots. GOT cell 0x1312ab8
// holds vptr-0x10. extent 0x220 - details:
// doc/_nn/pia/inet/InetProcessHostMigrationJob.md
class InetProcessHostMigrationJob {
 public:
  void* mVtable;          // 0x00 - 0x12da898 (cell 0x1312ab8 + 0x10)
  uint8_t mPad8[0x120];   // 0x08 - base subobject region (base C1 0x710098ffbc;
                          //   flag byte at 0xd4; unproven gap)
  void* m128;             // 0x128 - owned child (new 0xc0, init 0x7100a2bf88)
  uint8_t mPad130[0x20];  // 0x130 - member subobject (init 0x7100929ec0 /
                          //   destroyed by 0x7100929ee0; size unknown, unproven)
  void* mZero150;         // 0x150 - zeroed by C1
  uint8_t mPad158[0x8];   // 0x158 - unproven gap
  void* mZero160;         // 0x160 - zeroed by C1
  uint32_t m168;          // 0x168 - C1 stores 60000 (0xea60)
  uint8_t mPad16c[0x9c];  // 0x16c - unproven gap
  void* mZero208;         // 0x208 - zeroed by C1
  void* mZero210;         // 0x210 - zeroed by C1
  void* mZero218;         // 0x218 - zeroed by C1
};
}  // namespace nn::pia::inet
