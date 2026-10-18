#pragma once

#include <cstdint>

namespace nn::pia::inet {
// nn::pia::inet::MonitoringDataSendJob — RTTI-named (typeinfo slot 0x12ddae0 ->
// 0x12ddb30, "N2nn3pia4inet21MonitoringDataSendJobE"). vptr 0x12ddae8 (GOT
// cell 0x13136f0 holds 0x12ddad8 = vt-0x10).
// extent 0x90 (lower bound; unverified) - details: doc/_nn/pia/inet/MonitoringDataSendJob.md
class MonitoringDataSendJob {
 public:
  void* vtable;      // 0x00 - 0x12ddae8 (cell 0x13136f0 + 0x10)
  char pad08[0x20];  // 0x08..0x27 - common nn base (base ctor 0x7100567cb8),
                     //   unproven
  void* m28;         // 0x28 - base subobject vptr 0x12db168 (ctor 0x7100b4a5e0)
  void* m30;         // 0x30 - base ctor zero
  void* m38;         // 0x38 - base ctor zero
  void* m40;         // 0x40 - base ctor zero
  uint8_t m48;       // 0x48 - base ctor zero (bool)
  char pad49[0x07];     // pad - unproven gap
  void* m50;         // 0x50 - base ctor zero; base ends at 0x58
  uint32_t m58;      // 0x58 - C2 zero
  char pad5c[0x04];     // pad - unproven gap
  void* m60;         // 0x60 - C2 zero
  char pad68[0x20];  // 0x68..0x87 - inline subobject: inited by 0x7100929ec0,
                     //   finalized via 0x7100929ee0; layout unproven
  char pad88[0x08];  // 0x88..0x8f - pad to lower-bound size 0x90 (derived
                     //   ctor store at +0x88)
};
}  // namespace nn::pia::inet
