#pragma once

#include <cstdint>

namespace object {
// NetworkSendThread — an nn::ae::AppletThread subclass (vptr 0x12cca48, cell 0x1310a40, n=18, site 0x838c10, ctor 0x835608, alloc 0x28).
class NetworkSendThread {
 public:
  void* vptr;           // 0x00 — passed by the caller (cell+0x10)
  uint8_t pad_8[0x20];  //0x8 — unproven gap
                        // (own fields unmapped)
};
}  // namespace object
