#pragma once

#include <cstdint>

// Vt12c11d0 - PLACEHOLDER name (identity not proven). Long vtable (40+ slots,
// typeinfo NULL); GOT cell 0x130ef48 holds vt-0x10; vptr 0x12c11d0 installed
// at +0x00 by C1 0x751754. Secondary subtable group at slot 28
// (offset-to-top -0x60). Serves as primary base of a larger derived class
// (derived C1 0x89b30, size 0x180).
// extent 0x180 (derived 0x180 proven; base subobject 0x88) - details: doc/object/Vt12c11d0.md

class Vt12c11d0 {
 public:
  void* vtable;       // 0x00 - 0x12c11d0 (C1 0x751754 at 0x751798)
  uint32_t mField08;  // 0x08 - zeroed by C1
  uint8_t mField0C;   // 0x0C - flag, reset by D-tails 0x7517cc/0x751844
  uint8_t mPad0D[0x3];  // 0x0d - unproven gap
  void* mField10;    // 0x10 - owned ptr, destroyed via vtable slot 7 (0x38)
  uint8_t mField18;  // 0x18 - flag, zeroed by C1
  uint8_t mPad19[0x7];  // 0x19 - unproven gap
  void* mField20;        // 0x20 - zeroed by C1
  uint8_t mPad28[0x18];  // 0x28 - 0x3F - embedded obj (init 0x75481c, f32 x3 + u32)
  uint8_t mPad40[0x20];  // 0x40 - 0x5F - embedded obj (ctor 0x628998 / dtor 0x6289d4)
  uint8_t mPad60[0x20];  // 0x60 - 0x7F - secondary subobject region (unverified)
  uint8_t mField80;      // 0x80 - set to 1 by C1
  uint8_t mPad81[0x7];   // 0x81 - 0x87 - unproven
  uint8_t mPad88[0xF8];  // 0x88 - unproven (extent 0x180 from derived proof)
};
