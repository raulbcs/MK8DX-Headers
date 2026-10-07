#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt40b8 — PROVISIONAL vtable-anchored name (vptr 0x12b40b8, GOT cell
    // 0x130dbd8). Channel type of the 0x66496c cluster: built in
    // place inside the headered containers (ctor family 0x7100668528 /
    // in-place vptr store), derived from KartParamCacheChan via
    // ChanBase (0x12b3af0). No fields beyond the Chan shape (extent 0x20).
    class ParamChannelVt40b8 : public KartParamCacheChan
    {
    public:
        // (no own fields)
        // (0x20 total)
    };
}
