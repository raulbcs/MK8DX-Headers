#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelFilterAA — named from ctor string evidence: ctor 0x651ae4 emits the 'aglfila' tag + FXAA param block (0xef9661-0xef97a3); channel member of the FilterAA cache (was PROVISIONAL vtable-anchored ParamChannelVt3218) (vptr 0x12b3218, cell 0x130daa0, n=18, site 0x651b90, ctor 0x651ae4).
    // Channel type of the 0x66496c cluster (per-site reads pending; same
    // 0x7100662f30/0x7100662f70 channel-pair mechanism as the headered
    // siblings). Extent unmapped.
    class ParamChannelFilterAA : public KartParamCacheChan
    {
    public:
        // (no own fields beyond the Chan shape — see note)
    };
}
