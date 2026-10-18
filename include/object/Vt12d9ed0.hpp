#pragma once

#include <cstdint>

// Vt12d9ed0 - PLACEHOLDER name; element-array manager over Vt12d9f50 (0x270)
// elements; vptr 0x12d9ed8, 9 accessor slots, u16 cursor/count pair.
// extent 0x18 - details: doc/object/Vt12d9ed0.md

namespace object {
class Vt12d9ed0 {
 public:
  void* vtable;       // 0x00 - 0x12d9ed8 (C1 0x932390; GOT cell 0x1312930
                      // holds 0x12d9ec8 = vt-0x8, vptr = cell+0x10)
  uint16_t mCursor8;  // 0x08 - u16 cursor (ctor zeroes; slots 4/5 index with
                      // it, slot 6 returns it, slot 8 resets it)
  uint16_t mCountA;   // 0x0a - u16 element count (C1 arg; slots 7/8 use it)
  char mPadC[0x4];    // 0x0c - unproven
  void** mElements;   // 0x10 - new[count*8] array of Vt12d9f50 element ptrs
                      // (C1 0x9323b0..0x932414; D1/D0 free it 0x93250c..0x932524)
};
}  // namespace object
