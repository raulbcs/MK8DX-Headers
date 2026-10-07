#pragma once

#include <cstdint>

namespace object
{
    // ParamMultiChanVt2da0 — PROVISIONAL vtable-anchored name (vptr 0x12b2da0). Multi-channel
    // class of the 0x647f40 hook-band cluster: channel-pair members
    // (ctor 0x7100662f30/0x7100662f70) at 0x110, 0x138, 0x160, 0x188,
    // constructed in place at 0x64d7e4. EXTENT APPROXIMATE: last channel
    // + 0x20 = 0x1a8 (no factory alloc; per-field map pending).
    class ParamMultiChanVt2da0
    {
    public:
        void* vtable;          // 0x00
        uint8_t pad08[0x28];   // 0x08
        char mChan30[0x20];    // 0x30 — first channel-pair member
        char mMid50[0xc0];   // 0x50 — fields/channel region
        char mTail110[0x98]; // 0x110 — channel array region (to 0x1a8)
        // (~0x1a8 total, APPROXIMATE)
    };
}
