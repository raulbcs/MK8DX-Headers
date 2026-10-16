#pragma once

#include <cstdint>

namespace object {
// ParamNodeVtdba0 — address-anchored name (vptr 0x12bdba0, GOT cell
// composite operator new(0x538) at 0x72f404 -> ctor 0x72e4f8 embeds this base
class ParamNodeVtdba0 {
 public:
  void* vtable;          // 0x00
  uint8_t pad_8[0x530];  //0x8 — unproven gap
  // (own fields unmapped; secondary hook-band vptr at +0x30 = cell+0x108)
};
}  // namespace object
