#pragma once

#include <cstdint>

namespace enl
{
    // TaskThread — nn::ae-style applet-thread subclass (vptr 0x128a8e0,
    // cell 0x130b0f0, n=20; ctor 0x557c0c, alloc sites 0x556e04 /
    // 0x90f7a4 / 0x91d...: new 0x2c0). Constructed by enl::Framework's
    // setup (ctor arg x1 is the framework config block).
    //
    // Ctor field map: 0x00 vptr; 0xf8 {u32 head=0, u32 tail=0}; ring of
    // 2 nodes x 0x10 at 0x108 (init 0x60b918) with the 0x200-byte message
    // pool allocated in the ctor helper 0x557db0; free-node array of
    // 10 nodes x 0x10 at 0x120 (init 0x60b918, self-linked 0x140..0x1b8);
    // 0x1e0 member sub-object (ctor 0x628628); 0x220 member sub-object
    // (ctor 0x628628); 0x260 message-queue ptr (created via 0x6157b4);
    // 0x268 u32 = 0; 0x270 u64 = config[0x24] * global ticks (0x12fc688)
    // / 100 (period); 0x278 sub-object (ctor 0x62872c); 0x2a8 u64 =
    // config[0x34] * ticks / 100; 0x2b0 u32 = config[0x38];
    // 0x2b4 u32 = config[0x18]; 0x2b8 u32 = config[0x3c].
    class TaskThread
    {
    public:
        void* vptr;              // 0x00 — cell 0x130b0f0
        uint8_t mOwn08[0xf0];    // 0x08 — shared applet-thread base interior, map pending
        uint32_t mRingHeadF8;    // 0xf8 — ctor zero
        uint32_t mRingTailFc;    // 0xfc — ctor zero
        uint8_t mRing108[0x18];  // 0x108 — 2-node ring, 0x10 per node (init 0x60b918)
        uint8_t mNodes120[0xc0]; // 0x120 — 10-node free list, 0x10 per node (init 0x60b918)
        uint8_t mSub1e0[0x40];   // 0x1e0 — member sub-object (ctor 0x628628)
        uint8_t pad220[0x40];    // 0x220 — member sub-object (ctor 0x628628)
        void* mMsgQueue260;      // 0x260 — created via 0x6157b4 (ctor zero first)
        uint32_t mZero268;       // 0x268 — ctor zero
        uint64_t mPeriod270;     // 0x270 — config[0x24] * global ticks / 100
        uint8_t mSub278[0x30];   // 0x278 — sub-object (ctor 0x62872c)
        uint64_t mPeriod2a8;     // 0x2a8 — config[0x34] * global ticks / 100
        uint32_t mConf2b0;       // 0x2b0 — config[0x38]
        uint32_t mConf2b4;       // 0x2b4 — config[0x18]
        uint32_t mConf2b8;       // 0x2b8 — config[0x3c]
        uint8_t pad2bc[4];       // 0x2bc — to alloc size
        // (0x2c0 total)
    };
}
