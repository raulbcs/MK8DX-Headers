#pragma once

#include <cstdint>

namespace nn::nex {
// RTTI-confirmed (typeinfo 0x12e63c0: nn::nex::MD5KeyDerivation). Refcount-
// style member installed inline at singleton 0x13671a0+0x10 (init fn
// 0xa322cc): two u32 counters = 1 at +0x08/+0x10; slot2 combines virtuals
// slot3+slot4.
// size >= 0x18 - details: doc/_nn/nex/MD5KeyDerivation.md
class MD5KeyDerivation {
 public:
  void* vtable;           // 0x00 - vptr 0x12e5be0 (GOT cell 0x1314b18 holds
                          // 0x12e5bd0 = vptr-0x10; typeinfo slot 0x12e5bd8)
  uint32_t mField08;      // 0x08 - init writes 1
  uint32_t mField0c;      // 0x0c - init writes 1 (single 64-bit store)
  uint32_t mField10;      // 0x10 - init writes 1
  char mPad14[0x4];       // 0x14..0x17 - unproven
};
}  // namespace nn::nex
