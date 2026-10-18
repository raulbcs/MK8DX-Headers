#pragma once

#include <cstdint>

// Vt12da130 - PLACEHOLDER name; nn::pia-region job object over an opaque
// event/base (fields to +0x58) + 0xa2bf88-class member at +0x60; vptr
// 0x12da138. extent 0x120 (lower bound) - details: doc/object/Vt12da130.md

namespace object {
class Vt12da130 {
 public:
  void* vtable;        // 0x00 - 0x12da138 (C1 0x93296c; GOT cell 0x1312948
                       // holds 0x12da128 = vt-0x8, vptr = cell+0x10)
  char mPad8[0x50];    // 0x08 - base region (base member ctor 0xb4a5e0 runs on
                       // this at C1 entry; slot 2/3 touch flag +0x48 and pair
                       // +0x30/+0x38)
  void* mPtr58;        // 0x58 - ctor nulls (0x93297c)
  char mPad60[0xC0];   // 0x60 - member of the 0xa2bf88 class (~0xc0, init
                       // 0x932998 tail-calls 0xa2bf88(this+0x60, 0); dtor
                       // 0xa2c1e8 at +0x60)
};
}  // namespace object
