#pragma once

#include <cstdint>

namespace nn::pia::inet {
// MonitoringDataProtocol — RTTI-named (typeinfo 0x12dba00, name
// "N2nn3pia4inet22MonitoringDataProtocolE"). 11 slots, all inherited from the
// abstract pia protocol base (base C1 0x9a79c8); GOT cell 0x13131f0 holds
// vptr-0x10 (vptr 0x12db9a8).
// extent 0x20 - details: doc/_nn/pia/inet/MonitoringDataProtocol.md
class MonitoringDataProtocol {
 public:
  void* mVtable;   // 0x00 - vptr 0x12db9a8 (cell 0x13131f0 + 0x10); base C1
                   //   installs the base vptr (cell 0x1313b90), C1
                   //   0x964628 swaps in 0x12db9a8
  uint64_t m08;    // 0x08 - zeroed by base C1 (0x9a79d4 stp xzr)
  uint64_t m10;    // 0x10 - zeroed by base C1 (0x9a79e0)
  uint16_t m18;    // 0x18 - max payload size, base C1 copies from u16 at
                   //   cell 0x1313b98 (0x9a79e4-0x9a79ec)
  uint8_t mPad1a[0x6];  // 0x1a - tail padding to 0x20
};
}  // namespace nn::pia::inet
