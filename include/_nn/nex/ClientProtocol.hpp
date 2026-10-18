#pragma once

#include <cstdint>

namespace nn::nex {

// RTTI-confirmed (typeinfo mangled name: N2nn3nex14ClientProtocolE, ti object
// 0x12e62e0). Base protocol class; protocol id stored at +0x60 by C1.
// extent 0x90 - details: doc/_nn/nex/ClientProtocol.md

class ClientProtocol {
 public:
  void* vtable;          // 0x00 - 0x12e59c0 (row: offset-to-top 0 at
                         // 0x12e59b0, typeinfo 0x12e62e0 at 0x12e59b8;
                         // GOT cell 0x1314930 holds 0x12e59b0 = vptr-0x10)
  uint8_t mPad08[0x40];  // 0x08 - unproven
  uint16_t mField48;     // 0x48 - ctor zeroes (0x7100a27ee4)
  uint8_t mPad4a[0x6];   // 0x4a - unproven
  void* mField50;        // 0x50 - ctor zeroes (0x7100a27ef0)
  void* mField58;        // 0x58 - ctor zeroes (0x7100a27ef0)
  void* mField60_pad;    // 0x60 - ctor stores w1 protocol id
                         //        (0x7100a27ee8); upper half unproven
  void* mField68;        // 0x68 - ctor zeroes (0x7100a27ef4)
  uint8_t mField70;      // 0x70 - ctor zeroes (0x7100a27ef8)
  uint8_t mPad71[0x7];   // 0x71 - unproven
  void* mField78;        // 0x78 - ctor zeroes (0x7100a27efc)
  uint32_t mField80;     // 0x80 - ctor zeroes (0x7100a27f00)
  uint8_t mPad84[0x4];   // 0x84 - unproven
  void* mField88;        // 0x88 - refcounted handle; dtor atomically
                         //        decrements [ptr+8] and deletes at 0
                         //        (0x7100a27f44..0x7100a27f6c)
};

}  // namespace nn::nex
