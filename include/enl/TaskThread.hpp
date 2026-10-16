#pragma once

#include <cstdint>

namespace enl {
// TaskThread — nn::ae-style applet-thread subclass; vptr 0x128a8e0 (cell
// 0x130b0f0, n=20); ctor 0x557c0c (new 0x2c0 at 0x556e04/0x90f7a4).
class TaskThread {
 public:
  void* vptr;               // 0x00 — cell 0x130b0f0
  uint8_t mOwn08[0xf0];     // 0x08 — shared applet-thread base interior, own fields unmapped
  uint32_t mRingHeadF8;     // 0xf8 — ctor zero
  uint32_t mRingTailFc;     // 0xfc — ctor zero
  uint8_t mRing108[0x18];   // 0x108 — 2-node ring, 0x10 per node (init 0x60b918)
  uint8_t mNodes120[0xc0];  // 0x120 — 10-node free list, 0x10 per node (init 0x60b918)
  uint8_t mSub1e0[0x40];    // 0x1e0 — member sub-object (ctor 0x628628)
  uint8_t pad220[0x40];     // 0x220 — member sub-object (ctor 0x628628)
  void* mMsgQueue260;       // 0x260 — created via 0x6157b4 (ctor zero first)
  uint32_t mZero268;        // 0x268 — ctor zero
  uint64_t mPeriod270;      // 0x270 — config[0x24] * global ticks / 100
  uint8_t mSub278[0x30];    // 0x278 — sub-object (ctor 0x62872c)
  uint64_t mPeriod2a8;      // 0x2a8 — config[0x34] * global ticks / 100
  uint32_t mConf2b0;        // 0x2b0 — config[0x38]
  uint32_t mConf2b4;        // 0x2b4 — config[0x18]
  uint32_t mConf2b8;        // 0x2b8 — config[0x3c]
  uint8_t pad2bc[4];        // 0x2bc — to alloc size
                            // (0x2c0 total)
                            // extent 0x2c0 (prior-survey 0x2c0 total; cross-checked: alloc 0x2c0 @0x71002700d8 → ctor 0x71002700fc stores 0x2c0)
  uint8_t mGap100[8];       // 0x100 — unproven gap
  uint8_t mGap26c[4];       // 0x26c — unproven gap
};
}  // namespace enl
