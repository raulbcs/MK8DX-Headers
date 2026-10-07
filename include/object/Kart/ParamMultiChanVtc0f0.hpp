#pragma once

#include <cstdint>

namespace object
{
    // ParamMultiChanVtc0f0 — PROVISIONAL vtable-anchored name (vptr 0x12bc0f0). Multi-channel
    // class of the 0x647f40 hook-band cluster: channel-pair members
    // (ctor 0x7100662f30/0x7100662f70) at 0x270, 0x290, 0x2b0, 0x2d0, 0x2f0, 0x310,
    // constructed in place at 0x711730. EXTENT APPROXIMATE: last channel
    class ParamMultiChanVtc0f0
    {
    public:
        void* vtable;         // 0x00
        uint8_t pad08[0x28];  // 0x08
        char mChan30[0x20];   // 0x30 — first channel-pair member
        char mMid50[0x220];   // 0x50 — fields/channel region
        char mTail270[0xc0];  // 0x270 — channel array region (to 0x330)
        // (~0x330 total, APPROXIMATE)
    };
}
