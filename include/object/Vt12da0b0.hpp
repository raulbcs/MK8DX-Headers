#pragma once

#include <cstdint>

// Vt12da0b0 - PLACEHOLDER name; element-array manager over 0x688-byte pia
// elements; vptr 0x12da0b8, 9 accessor slots, u32 cursor/count pair.
// extent 0x18 - details: doc/object/Vt12da0b0.md

namespace object {
class Vt12da0b0 {
 public:
  void* vtable;       // 0x00 - 0x12da0b8 (C1 0x9326b8; GOT cell 0x1312940
                      // holds 0x12da0a8 = vt-0x8, vptr = cell+0x10)
  uint32_t mCursor8;  // 0x08 - u32 cursor (slots 4/5 index with it, slot 6
                      // returns it, slot 8 resets it)
  uint32_t mCountC;   // 0x0c - u32 element count (C1 u8 arg zero-extended;
                      // slots 7/8 use it)
  void** mElements;   // 0x10 - new[count*8] array of 0x688-byte element ptrs
                      // (C1 0x9326d0..0x93273c; D1/D0 free it)
};
}  // namespace object
