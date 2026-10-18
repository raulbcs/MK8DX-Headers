#pragma once

#include <cstdint>

// Vt12b6700 - PLACEHOLDER name (network/proxy-flavored object; slot methods
// call nifm proxy APIs around 0xaec4c4). vptr installed inline at many sites
// from cell 0x130e018; no standalone C1 with allocation.
// extent 0xa0 - lower bound - details: doc/object/Vt12b6700.md

namespace object {
class Vt12b6700 {
 public:
  void* vtable;       // 0x00 - installed 0x12b6700 (cell 0x130e018)
  char mPad08[0x70];  // 0x08..0x77 - unwritten by observed ctor (unproven)
  void* mPtr_78;      // 0x78 - from [cell 0x130e148]
  uint32_t mW_80;     // 0x80 - from [cell 0x130e148 + 8] (w store)
  uint32_t mZero_84;  // 0x84 - zeroed by ctor
  char mPad88[8];     // 0x88..0x8f - embedded subobject (own dtor 0x60b984)
  uint64_t mZero_90;  // 0x90 - zeroed by ctor
  uint32_t mZero_98;  // 0x98 - zeroed by ctor
  uint32_t mPad9c;    // 0x9c - padding (tail)
};
}  // namespace object
