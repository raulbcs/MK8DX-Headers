#pragma once

#include <cstdint>

namespace object
{
    // ParamMultiChanVtc200 — address-anchored name (vptr 0x12bc200). Multi-channel
    // class of the 0x647f40 hook-band cluster: channel-pair members
    // (ctor 0x7100662f30/0x7100662f70) at 0x4a8, 0x4d0, 0x4f0, 0x510, 0x530,
    // constructed in place at 0x711a24. EXTENT APPROXIMATE: last channel
    class ParamMultiChanVtc200
    {
    public:
        void* vtable;         // 0x00
        uint8_t pad08[0x28];  // 0x08 — unproven padding
        char mChan30[0x20];   // 0x30 — first channel-pair member
        char mMid50[0x458];   // 0x50 — fields/channel region
        char mTail4a8[0xa8];  // 0x4a8 — channel array region (to 0x550)
        // (~0x550 total, APPROXIMATE)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
