#pragma once

#include <cstdint>

namespace object {
// UILoadThread — an nn::ae::AppletThread subclass (vptr 0x1265c50, cell 0x1308988, n=18, site 0x402528, ctor 0x401dd8, alloc 0xa0).
class UILoadThread {
 public:
  void* vptr;           // 0x00 — passed by the caller (cell+0x10)
  uint8_t pad_8[0x98];  //0x8 — unproven gap
                        // (own fields unmapped)
};
}  // namespace object
