#pragma once

#include <cstdint>

namespace object
{
    // ParamMultiChanVtda50 — address-anchored name (vptr 0x12bda50). Multi-channel
    // class of the 0x647f40 hook-band cluster: channel-pair members
    // (ctor 0x7100662f30/0x7100662f70) at 0x2c8, 0x2f0, 0x318, 0x340, 0x360,
    // constructed in place at 0x72cd5c. EXTENT APPROXIMATE: last channel
    class ParamMultiChanVtda50
    {
    public:
        void* vtable;         // 0x00
        uint8_t pad08[0x28];  // 0x08
        char mChan30[0x20];   // 0x30 — first channel-pair member
        char mMid50[0x278];   // 0x50 — fields/channel region
        char mTail2c8[0xb8];  // 0x2c8 — channel array region (to 0x380)
        // (~0x380 total, APPROXIMATE)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash, not statically resolvable. Address-anchored name retained.
