#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexMatchJointSessionJob — RTTI-named (typeinfo name at
// 0xf7f7a0, base nn::pia::session::JointSessionJob); vptr 0x12dafd8 (GOT cell
// 0x1312e00 holds 0x12dafc8 = vt-0x10); ctor cluster 0x941190.
// extent >= 0x2da (lower bound, unverified) - details: doc/_nn/pia/inet/NexMatchJointSessionJob.md
class NexMatchJointSessionJob {
 public:
  void* vtable;         // 0x00 - 0x12dafd8 (cell 0x1312e00 + 0x10)
  char pad08[0x110];    // 0x08..0x117 - unproven gap
  char mBase118[0x78];  // 0x118..0x18f - nn::pia::session::JointSessionJob base
                        //   subobject (base ctor 0x9b1fe8, base D2 0x9b20b4)
  char pad190[0x70];    // 0x190..0x1ff - ctor zeroes via 8x stp xzr,xzr
  char pad200[0x36];    // 0x200..0x235 - unproven gap
  uint8_t m236;         // 0x236 - ctor writes 1 (strb w9)
  char pad237[0x81];    // 0x237..0x2b7 - unproven gap
  uint8_t m2b8;         // 0x2b8 - ctor writes 0 (strb wzr)
  char pad2b9[0x1];     // 0x2b9 - unproven gap
  char m2ba[0x20];      // 0x2ba..0x2d9 - ctor zero loop (unroll-4, cmp #0x20)
};
}  // namespace nn::pia::inet
