#pragma once

#include <cstdint>

namespace object
{
    // ParamMultiChanVtba40 — PROVISIONAL vtable-anchored name (vptr 0x12bba40). Multi-channel
    // class of the 0x647f40 hook-band cluster: channel-pair members
    // (ctor 0x7100662f30/0x7100662f70) at 0x1f8, 0x218, 0x238, 0x258, 0x278, 0x298,
    // constructed in place at 0x7058ac. EXTENT APPROXIMATE: last channel
    // + 0x20 = 0x2b8 (no factory alloc; per-field map pending).
    class ParamMultiChanVtba40
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[0x28];   // 0x08
        char mChan30[0x20];    // 0x30 — first channel-pair member
        char mMid50[0x1a8];   // 0x50 — fields/channel region
        char mTail1f8[0xc0]; // 0x1f8 — channel array region (to 0x2b8)
        // (~0x2b8 total, APPROXIMATE)
    };
}
