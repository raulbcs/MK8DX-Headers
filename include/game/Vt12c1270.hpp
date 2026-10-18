#pragma once

#include <cstdint>

// Vt12c1270 — PLACEHOLDER name; vptr 0x12c1270, 8 slots, MI secondary
// 0x12c12c0 at +0x60. C1 0x75289c (base C1 0x5edf44, base vptr
// 0x12ae2b8). new(0x1a8) in factory FUN_71007514ac.
// extent 0x1a8 - details: doc/game/Vt12c1270.md
namespace game {
class Vt12c1270 {
 public:
  void* mVtable;      // 0x00 - primary vptr 0x12c1270 (GOT cell 0x130ef88
                      //   holds vptr-0x10; C1 adds 0x10)
  uint8_t mBase08[0x58];  // 0x08 - base subobject (base C1 0x5edf44, base
                      //   vptr 0x12ae2b8 via cell 0x130cd68)
  void* mVtable60;    // 0x60 - secondary vptr 0x12c12c0 (row ot -0xa0)
  uint32_t mCount68;  // 0x68 - zeroed by C1; loop bound in D2 (0x7529d4)
  uint8_t mFlag6c;    // 0x6c - zeroed by C1; D2 frees array only if != 0
  uint8_t mPad6d[0x3]; // 0x6d - unproven gap
  uint64_t mZero70;   // 0x70 - zeroed by C1
  uint8_t mZero78;    // 0x78 - zeroed by C1
  uint8_t mPad79[0x7]; // 0x79 - unproven gap
  void* mArray80;     // 0x80 - zeroed by C1; entry array freed by D2
  uint64_t mZero88;   // 0x88 - zeroed by C1
  uint64_t mZero90;   // 0x90 - zeroed by C1
  uint64_t mConst98;  // 0x98 - ctor stores 0x006046fa'00000000 (0x7528d4)
  uint8_t mPadA0[8];  // 0xa0 - unproven gap
  uint8_t mSubA8[0x8];    // 0xa8 - zeroed by C1 (0xa0 qword, 0xa8 const)
  uint32_t mB0;       // 0xb0 - copied from *x1 by C1
  uint32_t mB4;       // 0xb4 - copied from *x2 by C1
  uint64_t mZeroB8;   // 0xb8 - zeroed by C1
  uint64_t mZeroC0;   // 0xc0 - zeroed by C1 (and by D2 at 0x752a20)
  uint8_t mFlagC8;    // 0xc8 - zeroed by C1
  uint8_t mPadC9[0x7]; // 0xc9 - unproven gap
  uint64_t mZeroD0;   // 0xd0 - zeroed by C1
  uint8_t mSubD8[0x40];   // 0xd8 - embedded subobject (C1 0x628998)
  uint8_t mFlag118;   // 0x118 - zeroed by C1
  uint8_t mPad119[0x7]; // 0x119 - unproven gap
  uint64_t mZero120;  // 0x120 - zeroed by C1
  uint8_t mSub128[0x78];  // 0x128 - embedded subobject (C1 0x61cc48);
                      //   its vptr (this+0x130) ends as 0x11ad270
                      //   (cell 0x12fb728 + 0x10)
  uint16_t mH1a0;     // 0x1a0 - zeroed by C1 (last store, 0x752988)
  uint8_t mPad1a2[6]; // 0x1a2 - unproven gap
};
}  // namespace game
