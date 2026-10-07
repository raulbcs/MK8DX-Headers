#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt3cd8 — address-anchored name (vptr 0x12b3cd8, GOT cell
    // 0x130db70). Channel type of the 0x66496c cluster, built in
    // place inside the headered param-cache containers. factory alloc 0x28 (site 0x71006652b0).
    // Extent 0x28.
    class ParamChannelVt3cd8 : public KartParamCacheChan
    {
    public:
        char mOwn20[0x8];      // 0x20 — own-field region (factory alloc 0x28)
        // (0x28 total)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
