#pragma once

#include <cstdint>

namespace nn::pia::local {
// LdnForceDisconnectNetworkJob — RTTI-confirmed (typeinfo 0x12e1190, name
// "N2nn3pia5local28LdnForceDisconnectNetworkJobE", base LocalForceDisconnectNetworkJob).
// extent 0x68 - details: doc/_nn/pia/local/LdnForceDisconnectNetworkJob.md
class LdnForceDisconnectNetworkJob {
 public:
  void* mVtable;          // 0x00 - vptr 0x12e1158 (GOT cell 0x1313e78 + 0x10)
  uint8_t mBase08[0x60];  // 0x08 - base subobject (LocalForceDisconnectNetworkJob
                          //        C1 0x9cf894), unproven gap
};
}  // namespace nn::pia::local
