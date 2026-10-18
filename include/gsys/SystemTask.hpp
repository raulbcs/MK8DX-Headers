#pragma once

#include <cstdint>

namespace gsys {

// Named in config/functions.csv (C1 0x7136f4 "gsys::SystemTask"); registers
// named sub-tasks ("gsys::SystemTask::PreCalc/PostCalc/DrawTV"). Owned by a
// guarded singleton factory at 0x3c71f8 (new 0x6d8).
// extent 0x6d8 - details: doc/gsys/SystemTask.md

class SystemTask {
 public:
  void* vtable;           // 0x00 - 0x12bc5c0; GOT cell 0x130e680 holds
                          // 0x12bc5b0 = vt-0x10
  uint8_t mPad08[0xc8];   // 0x08 - unproven (C1 zero-fills, see
                          // 0x7136f4..0x7139c0)
  uint8_t mFieldD0;       // 0xd0 - ctor zeroes (0x710071373c)
  uint8_t mPadD1[0x7];    // 0xd1 - unproven
  char mSubD8[0x3b0];     // 0xd8 - sub-object, C 0x7139c4 (vptr cell
                          // 0x130e678 -> 0x12bc5a0); list nodes at
                          // +0x130/+0x1c8 (+0xd8-based) etc.
  void* mVptr488;         // 0x488 - secondary vptr, cell 0x130e678
                          // (0x710071375c)
  uint8_t mPad490[0xb8];  // 0x490 - 0xb5-byte param block memcpy'd from
                          // arg+0x8 (0x7100713760); interior unproven
  uint64_t mField548;     // 0x548 - ctor 0xfff6c900 (0x710071377c)
  uint64_t mField550;     // 0x550 - ctor zeroes (0x7100713774)
  uint8_t mPad558[0x1c];  // 0x558 - unproven; ctor zeroes 0x560 and
                          // 0x565 (0x7100713780/0x7100713788)
  float mField574;        // 0x574 - ctor 1.0f (0x7100713790)
  uint8_t mPad578[0x4];   // 0x578 - unproven
  float mField57c;        // 0x57c - ctor 1.0f (0x7100713794)
  uint8_t mPad580[0x8];   // 0x580 - unproven
  void* mField588;        // 0x588 - ctor zeroes (0x71007137a0)
  void* mField590;        // 0x590 - ctor zeroes (0x710071379c)
  void* mField598;        // 0x598 - ctor zeroes (0x7100713798)
  uint8_t mPad5a0[0x10];  // 0x5a0 - unproven
  void* mVptr5b0;         // 0x5b0 - vptr, cell 0x130e688 -> 0x12bc6a8
                          // (0x71007137ac)
  float mField5b8;        // 0x5b8 - ctor 1.0f (0x71007137b0)
  float mField5bc;        // 0x5bc - ctor 1.0f (0x71007137b4)
  float mField5c0;        // 0x5c0 - ctor 1.0f (0x71007137b8)
  uint8_t mPad5c4[0x4];   // 0x5c4 - unproven
  void* mField5c8;        // 0x5c8 - heap ptr, freed by D1 (0x7100714e9c)
  uint8_t mPad5d0[0xc8];  // 0x5d0 - sub-object ctor 0x63194c
                          // (0x71007137c0); unproven interior
  uint32_t mField698;     // 0x698 - ctor zeroes (0x71007137c4)
  uint8_t mPad69c[0x4];   // 0x69c - unproven
  void* mField6a0;        // 0x6a0 - ctor zeroes (0x71007137c8)
  uint8_t mField6a8;      // 0x6a8 - ctor 4 (0x71007137dc)
  uint8_t mField6a9;      // 0x6a9 - ctor 4 (0x71007137e0)
  uint8_t mPad6aa[0x6];   // 0x6aa - unproven
  void* mVptr6b0;         // 0x6b0 - vptr, cell 0x130d6f0+0x10
                          // (0x71007137fc)
  uint64_t mField6b8;     // 0x6b8 - ctor 0x3f8000003f800000
                          // (0x71007137ec)
  void* mField6c0;        // 0x6c0 - ctor zeroes (0x71007137f4)
  float mField6c8;        // 0x6c8 - ctor 1.0f (0x71007137f0)
  float mField6cc;        // 0x6cc - ctor 1.0f (0x71007137f8)
  uint8_t mPad6d0[0x8];   // 0x6d0 - unproven
};

}  // namespace gsys
