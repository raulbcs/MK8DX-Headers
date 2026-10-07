#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt2910 — PROVISIONAL vtable-anchored name (vptr 0x12b2910, GOT cell
    // 0x130d9d0). Channel type of the 0x66496c cluster, built in
    // place inside the headered param-cache containers. channel at parent+0x198: zero at +0x1b0, float -3.0f at +0x1b8 (fn 0x710064c970).
    // Extent 0x1c0.
    class ParamChannelVt2910 : public KartParamCacheChan
    {
    public:
        char mOwn20[0x1a0];    // 0x20 — own-field region (map pending)
        // (0x1c0 total)
    };
}
