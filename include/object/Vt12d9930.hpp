#pragma once

#include <cstdint>

// Vt12d9930 - PLACEHOLDER name; nn::pia-region typed accessor over an inner
// handler object ([this+0x8]); vptr 0x12d9938, 9 slots, embedded member at
// parent+0x2078. extent 0x128 (lower bound 0x124) - details: doc/object/Vt12d9930.md

namespace object {
class Vt12d9930 {
 public:
  void* vtable;        // 0x00 - 0x12d9938 (C1 0x92ed34; GOT cell 0x13128d0
                       // holds 0x12d9928 = vt-0x8, vptr = cell+0x10)
  void* mHandler;      // 0x08 - inner handler object ptr (ctor zeroes it via
                       // base ctor 0x98324c; slot 2/4/6/7 access it)
  uint32_t mField10;   // 0x10 - u32, slot 3 setter / slot 4 getter
  uint16_t mField14;   // 0x14 - u16, slot 5 setter / slot 6 getter
  char mPad16[0x2];    // 0x16 - unproven
  void* mVtable18;     // 0x18 - second base vptr 0x12d95b8 (GOT cell 0x1312850
                       // holds 0x12d95a8; C1 0x92ed5c..0x92ed6c)
  void* mPtr20;        // 0x20 - = this+0x34 (0x92edb0)
  uint32_t mField28;   // 0x28 - ctor stores 0x80 (0x92ed70..0x92ed74)
  uint32_t mField2c;   // 0x2c - ctor zeroes
  uint32_t mField30;   // 0x30 - ctor zeroes (0x92ed60)
  char mPad34[0x84];   // 0x34 - ctor zeroed 0x81 x 3-byte-stride block
                       // (0x92ed78..0x92ed8c); +0x34 is start
  void* mVtableB8;     // 0xb8 - third vptr 0x12d99a8 (GOT cell 0x13128d8 holds
                       // 0x12d9998; 0x92edb4..0x92edb8)
  void* mPtrC0;        // 0xc0 - = this+0xd4 (0x92edf0)
  uint32_t mFieldC8;   // 0xc8 - ctor stores 0x100 (0x92eddc..0x92ede8)
  uint32_t mFieldCc;   // 0xcc - ctor zeroes
  char mPadD0[0x4];    // 0xd0 - ctor zeroes (0x92edb8)
  char mPadD4[0x44];   // 0xd4 - ctor zeroed 0x10 x 4-byte-stride block
                       // (0x92edc0..0x92edd8); +0xd4 is start
  uint16_t mField118;  // 0x118 - ctor zeroes (0x92edf8); reset slot 8 too
  uint16_t mPad11a;    // 0x11a - unproven gap
  uint32_t mField11c;  // 0x11c - ctor zeroes (0x92edfc)
  uint16_t mField120;  // 0x120 - ctor stores 0x100 (0x92ede8)
  uint8_t mField122;   // 0x122 - ctor stores 1 (0x92ee00)
  char mPad123[0x5];   // 0x123 - unproven padding to 0x128
};
}  // namespace object
