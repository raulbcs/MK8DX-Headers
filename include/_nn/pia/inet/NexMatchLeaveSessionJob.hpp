#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::NexMatchLeaveSessionJob — RTTI-named (typeinfo 0x12db150,
// name string 0xf7f820 "N2nn3pia4inet23NexMatchLeaveSessionJobE"; base ti
// 0x12ddf40 = nn::pia::session::LeaveSessionJob). vptr 0x12db0c8 (GOT cell
// 0x1313010 holds vt-0x10); 17 slots. size 0x140 proven (new 0x140 at
// 0x931c00). extent 0x140 - details:
// doc/_nn/pia/inet/NexMatchLeaveSessionJob.md
class NexMatchLeaveSessionJob {
 public:
  void* vtable;           // 0x00 — 0x12db0c8 (cell 0x1313010 + 0x10)
  uint8_t mBase08[0x90];  // 0x08 — nn::pia::session::LeaveSessionJob base
                          //   region (base ctor 0x985060); unproven
  uint8_t mZero98[0x80];  // 0x98 — ctor zeroes (16 u32 stores, w-stride-8,
                          //   0x94de58-0x94de74; gap bytes unproven)
  uint8_t mByte118;       // 0x118 — ctor zeroes; success flag written by
                          //   slot6 (0x94deac)
  uint8_t mArr119[0x20];  // 0x119 — ctor zeroes (b-stride-2 loop); slot6
                          //   re-zeroes [+0x119 .. +0x119+count)
  uint8_t mPad139[7];     // 0x139 — unproven tail to 0x140
};
}  // namespace nn::pia::inet
