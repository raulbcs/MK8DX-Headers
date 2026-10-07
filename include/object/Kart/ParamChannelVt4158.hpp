#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt4158 — address-anchored name (vptr 0x12b4158, GOT cell
    // 0x130dbe0). Channel type of the 0x66496c cluster: built in
    // place inside the headered containers (ctor family 0x7100668528 /
    // in-place vptr store), derived from KartParamCacheChan via
    // ChanBase (0x12b3af0). Byte flag at 0x24 (extent 0x28).
    class ParamChannelVt4158 : public KartParamCacheChan
    {
    public:
        uint8_t mFlag24;       // 0x24 — zeroed on init
        // (0x28 total)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
