#pragma once

#include <cstdint>

namespace object
{
    // ParamMultiChanVtbb50 — address-anchored name (vptr 0x12bbb50). Multi-channel
    // class of the 0x647f40 hook-band cluster: channel-pair members
    // (ctor 0x7100662f30/0x7100662f70) at 0x4a8, 0x4c8, 0x4e8, 0x508, 0x528, 0x548,
    // constructed in place at 0x705c4c. EXTENT APPROXIMATE: last channel
    class ParamMultiChanVtbb50
    {
    public:
        void* vtable;         // 0x00
        uint8_t pad08[0x28];  // 0x08 — unproven padding
        char mChan30[0x20];   // 0x30 — first channel-pair member
        char mMid50[0x458];   // 0x50 — fields/channel region
        char mTail4a8[0xc0];  // 0x4a8 — channel array region (to 0x568)
        // (~0x568 total, APPROXIMATE)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
