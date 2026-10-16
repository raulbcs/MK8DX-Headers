#pragma once

#include <cstdint>

namespace object {
// UINFPArchiveThread — an nn::ae::AppletThread subclass (vptr 0x1265d70, cell 0x1308d18, n=18, site 0x4062f4, ctor 0x4060dc, alloc 0x170).
class UINFPArchiveThread {
 public:
  void* vptr;            // 0x00 — passed by the caller (cell+0x10)
  uint8_t pad_8[0x168];  //0x8 — unproven gap
                         // (own fields unmapped)
};
}  // namespace object
