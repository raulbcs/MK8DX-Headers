#pragma once

#include <cstdint>

namespace gear {
// UINFPThread — nn::ae::AppletThread subclass (vptr 0x126f470, cell 0x1309f58, ctor 0x485390, alloc 0x240)
class UINFPThread {
 public:
  void* vptr;            // 0x00 — passed by the caller (cell+0x10)
  uint8_t pad_8[0x238];  //0x8 — unproven gap
                         // (own fields unmapped)
};
}  // namespace gear
