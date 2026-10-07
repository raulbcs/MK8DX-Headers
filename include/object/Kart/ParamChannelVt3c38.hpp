#pragma once

#include <cstdint>

#include "object/Kart/ParamChannelVt38f8.hpp"

namespace object
{
    // ParamChannelVt3c38 — PROVISIONAL vtable-anchored name (vptr 0x12b3c38, GOT cell
    // 0x130db68). LAZY-resolver channel type of the 0x66496c cluster (sibling of
    // ParamChannelVt38f8/0x12b38f8): no static vptr store — initialized
    // at runtime by the shared lazy-init method 0x7100646850(this, ctx).
    // Same proven layout (extent >= 0x170); see Vt38f8 for the full
    // resolver map. Shares the ctor region 0x710065e178 with Vt38f8.
    class ParamChannelVt3c38 : public ParamChannelVt38f8
    {
        // (same shape; extent >= 0x170, tail unmapped)
    };
}
