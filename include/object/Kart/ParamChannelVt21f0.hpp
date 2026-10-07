#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt21f0 — address-anchored name. Channel type of the
    // 0x66496c cluster, built in place inside the headered param-cache
    // containers. channel at parent+0x40, tail byte +0x58 (fn 0x7100646dac).
    // Extent 0x20. NOTE (binary-verified): the earlier claim of vptr
    // 0x12b21f0 was wrong — 0x12b21f0 is the first vtable-entry SLOT of the
    // KartParamCacheChan vtable (holds fn 0x64733c), never a vptr. GOT cell
    // 0x130d908 relocates to 0x12b21e0 = KartParamCacheChan's vptr, so this
    // shape shares the base vtable (no own fields).
    class ParamChannelVt21f0 : public KartParamCacheChan
    {
    public:
        // (no own fields beyond the Chan shape)
        // (0x20 total)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
