#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt20e8 — address-anchored name (vptr 0x12b20e8, GOT cell
    // 0x130d938). Channel type of the 0x66496c cluster: built in
    // place inside the headered containers (ctor family 0x7100668528 /
    // in-place vptr store), derived from KartParamCacheChan via
    // ChanBase (0x12b3af0). No fields beyond the Chan shape (extent 0x20).
    class ParamChannelVt20e8 : public KartParamCacheChan
    {
    public:
        // (no own fields)
        // (0x20 total)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
