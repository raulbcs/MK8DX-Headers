#pragma once

#include <cstdint>

// nn::nex::JobAcquireAccessToken - RTTI'd (typeinfo 0x12d7460, name
// 0xf7d4a0); MI nex Job with secondary vptrs at +0x38/+0xa8/+0x190/+0x1a0/
// +0x1a8/+0x1d0/+0x1e0/+0x208.
// extent 0x560 - details: doc/object/NexJobAcquireAccessToken.md

namespace object {

class NexJobAcquireAccessToken {
 public:
  void* vtable;         // 0x00 - 0x12d70b8 (GOT cell 0x1312108 holds
                        //        0x12d70a8 = vptr-0x10 = typeinfo-slot row;
                        //        typeinfo 0x12d7460, ot = 0)
  char mPad08[0x30];    // 0x08..0x37 - unproven
  void* mVptr38;        // 0x38 - secondary vptr (cell 0x1312110), +0x38
                        //        sub-init 0x5790b4
  char mPad40[0x60];    // 0x40..0x9f - unproven
  char mPadA0[0x8];     // 0xa0 - zeroed; +0xa4 = 0x10 by factory
  void* mVptrA8;        // 0xa8 - secondary vptr (cell 0x130b618)
  char mPadB0[0xe0];    // 0xb0..0x18f - unproven (0x5790b4-style inits)
  void* mVptr190;       // 0x190 - secondary vptr (cell 0x13120f8)
  char mPad198[0x8];    // 0x198..0x19f - unproven
  void* mVptr1a0;       // 0x1a0 - secondary vptr (cell 0x1312120)
  void* mVptr1a8;       // 0x1a8 - secondary vptr (cell 0x130b4a8)
  char mPad1b0[0x20];   // 0x1b0..0x1cf - unproven
  void* mVptr1d0;       // 0x1d0 - secondary vptr (cells 0x1312118/0x1312128)
  char mPad1d8[0x8];    // 0x1d8..0x1df - unproven
  void* mVptr1e0;       // 0x1e0 - secondary vptr (0x1312120 value)
  char mPad1e8[0x20];   // 0x1e8..0x207 - unproven
  void* mVptr208;       // 0x208 - secondary vptr (cell 0x130b4a8)
  char mPad210[0x350];  // 0x210..0x55f - unproven
};

}  // namespace object
