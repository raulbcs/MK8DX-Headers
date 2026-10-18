#pragma once

#include <cstdint>

namespace nn::pia::local {
// RTTI-named (typeinfo 0x12e1c00, "N2nn3pia5local24LocalMatchJoinSessionJobE",
// base nn::pia::session::JoinSessionJob ti 0x12ddc70). Typeinfo-slot row:
// vptr 0x12e1b68 (GOT cell 0x13140d8 holds vptr-0x10), 18 slots.
// extent 0x128 - details: doc/_nn/pia/local/LocalMatchJoinSessionJob.md
class LocalMatchJoinSessionJob {
 public:
  void* vtable;           // 0x00 - 0x12e1b68 (cell 0x13140d8 + 0x10)
  char pad08[0x110];      // 0x08..0x117 - base nn::pia::session::JoinSessionJob
                          //   region (base C1 0x9d23d8-equiv 0x9823d8: zeroes
                          //   +0x58, +0x60 subobject via 0x929ec0, +0x80 via
                          //   0x9b1fe8, +0xf8/+0x100/+0x108/+0x110); unproven
  void* m118;             // 0x118 - C1 0x9d2140 stores 0
  void* m120;             // 0x120 - C1 0x9d2140 stores x1 (request param);
                          //   zeroed by D1/D0
};
}  // namespace nn::pia::local
