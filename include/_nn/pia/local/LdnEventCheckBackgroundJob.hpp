#pragma once

#include <cstdint>

namespace nn::pia::local {
// LdnEventCheckBackgroundJob — RTTI-confirmed (typeinfo 0x12e1130, name
// "N2nn3pia5local26LdnEventCheckBackgroundJobE", base LocalEventCheckBackgroundJob).
// extent 0x68 - details: doc/_nn/pia/local/LdnEventCheckBackgroundJob.md
class LdnEventCheckBackgroundJob {
 public:
  void* mVtable;          // 0x00 - vptr 0x12e10f8 (GOT cell 0x1313e70 + 0x10)
  uint8_t mBase08[0x60];  // 0x08 - base subobject (LocalEventCheckBackgroundJob
                          //        C1 0x9cf3d4), unproven gap
};
}  // namespace nn::pia::local
