#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexMatchCommunityManagementJob - RTTI-named (record 0x12dad80,
// name ref 0xf7f0f0 exact); in-place facade, base subobject +0x00..+0x60.
// extent 0xa8 lower bound - details: doc/_nn/pia/inet/NexMatchCommunityManagementJob.md
class NexMatchCommunityManagementJob {
 public:
  void* vtable;      // 0x00 - 0x12dad18 (GOT cell 0x1312c00 holds 0x12dad08 =
                     //   vt-0x10; installed = cell+0x10)
  char pad08[0x50];  // 0x08..0x57 - base subobject (base C1 0x97dfc0 installs
                     //   base vptr 0x12dd878 = cell 0x1313690 + 0x10, zeroes
                     //   +0x58, tail-calls 0x929ec0 at this+0x60); unproven
  void* m58;         // 0x58 - base ctor zero
  char pad60[0x28];  // 0x60..0x87 - region reached by base ctor tail 0x929ec0;
                     //   unproven
  uint32_t m88;      // 0x88 - ctor 0
  char pad8C[0x04];  // 0x8c..0x8f - unproven gap
  void* m90;         // 0x90 - ctor 0
  void* m98;         // 0x98 - ctor 0
  uint8_t mA0;       // 0xa0 - ctor 1
  char padA1[0x07];  // 0xa1..0xa7 - tail slack to the 0xa8 last-store bound;
                     //   unproven
};
}  // namespace nn::pia::inet
