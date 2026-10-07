#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt29b0 — address-anchored name (vptr 0x12b29b0, GOT cell
    // 0x130d9c8). Channel type of the 0x66496c cluster, built in
    // place inside the headered param-cache containers. channel at parent+0x198: same trailing fields as 0x12b2910.
    // Extent 0x1c0.
    class ParamChannelVt29b0 : public KartParamCacheChan
    {
    public:
        char mOwn20[0x1a0];  // 0x20 — own-field region
        // (0x1c0 total)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
