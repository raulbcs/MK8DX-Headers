#pragma once

#include <cstdint>

namespace object {

// Vt12ba840 - PLACEHOLDER name; flag/config record with a float-defaults
// table pointer at +0x40 and member vptrs at +0x50/+0x98 (0x12bac68); heap
// buffer at +0x60 freed by D1. Derived ctors 0x732620 and 0x6abf6c extend
// it. extent 0xa8+ (lower bound) - details: doc/object/Vt12ba840.md

class Vt12ba840 {
 public:
  void* vtable;          // 0x00 - 0x12ba840; GOT cell 0x130e418 holds
                         // 0x12ba830 = vt-0x10
  uint8_t mField08;      // 0x08 - ctor zeroes (0x71006ebb58); bit1 gates
                         // the +0x60 free in D1 (0x71006ebc14)
  uint8_t mField09;      // 0x09 - ctor zeroes (0x71006ebb88)
  uint8_t mField0a;      // 0x0a - ctor sets 1 (0x71006ebb90)
  uint8_t mPad0b[1];     // 0x0b - unproven
  uint16_t mField0c;     // 0x0c - ctor 0xffff (0x71006ebb60)
  uint8_t mField0e;      // 0x0e - ctor 0xff (0x71006ebb70)
  uint8_t mField0f;      // 0x0f - ctor zeroes (0x71006ebb98)
  uint32_t mField10;     // 0x10 - ctor 0x00100000 (0x71006ebb78)
  uint16_t mField14;     // 0x14 - ctor 0xffff (0x71006ebb84)
  uint8_t mPad16[0x2a];  // 0x16 - ctor zero-fills through 0x3f
                         // (0x71006ebb9c..0x71006ebbb4; unaligned zero
                         // stores at 0x2e/0x36)
  void* mField40;        // 0x40 - copy of [0x12fb148] = 0xf57b7c
                         // (1.0f-filled float defaults table)
                         // (0x71006ebbc0..0x71006ebbc4)
  uint32_t mField48;     // 0x48 - word copy of [0x12fb150]
                         // (0x71006ebbbc)
  uint32_t mField4c;     // 0x4c - ctor zeroes (0x71006ebbc8)
  void* mVptr50;         // 0x50 - member vptr, cell 0x130e420 ->
                         // 0x12bac68 (0x71006ebbd0..0x71006ebbd4)
  void* mField58;        // 0x58 - ctor zeroes (0x71006ebbd0)
  uint8_t mPad60[0x30];  // 0x60 - ctor zero-fills; +0x60 is the heap
                         // pointer freed by D1 when +0x8 bit1 set
                         // (0x71006ebc14..0x71006ebc34)
  uint64_t mField90;     // 0x90 - ctor zeroes (0x71006ebbec)
  void* mVptr98;         // 0x98 - member vptr 0x12bac68
                         // (0x71006ebbec..0x71006ebbf0)
  uint32_t mFielda0;     // 0xa0 - ctor sets 1 (0x71006ebbe4)
  uint8_t mPada4[0x4];   // 0xa4 - unproven
};

}  // namespace object
