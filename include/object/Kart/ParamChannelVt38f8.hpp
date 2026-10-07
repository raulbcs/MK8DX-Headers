#pragma once

#include <cstdint>

#include "object/Kart/KartParamCacheChan.hpp"

namespace object
{
    // ParamChannelVt38f8 — address-anchored name (vptr 0x12b38f8, GOT cell
    // 0x130db18). LAZY-resolver channel type of the 0x66496c cluster: the
    // cell has no static vptr store — instances are initialized at runtime
    // by the shared lazy-init method 0x7100646850(this, ctx), called
    // in-place at many parent offsets (0x20/0x28/0x38/0x208/0x3e8/0x580/
    // 0xb68/0xd30/0xd48/0xf28 of their containers).
    //
    // Extent >= 0x170 — proven by the resolver's writes; the tail beyond
    // 0x170 is unmapped (no static ctor evidence exists for this type).
    //
    // Resolver 0x7100646850 map (x0 = this, x1 = ctx):
    //   x19 = [ctx+0xc0] (source blob)
    //   indirect fn [GOT 0x130c3f0]([x19], 0x10, this+0x11c) — 16-byte
    //     block copy ctx+0xc0 -> this+0x11c
    //   indirect fn [GOT 0x130c3f8]([x19], 0x10, this+0x160) — same blob
    //     -> this+0x160
    //   w22 = [this+0x108] (count); loop over ptr array [this+0x110]:
    //     ret = indirect fn [GOT 0x1307020 -> bss 0x1347c18](elem+0x8)
    //     indirect fn [GOT 0x130c408]([x19], idx, ret, [elem+0x118])
    //   (0x170 total, tail unmapped)
    class ParamChannelVt38f8 : public KartParamCacheChan
    {
    public:
        char mOwn20[0xe8];       // 0x20 — own-field region
        uint32_t mCount108;      // 0x108 — element count
        uint8_t pad10c[4];       // 0x10c — unproven padding
        void** mElems110;        // 0x110 — element pointer array
        uint8_t mBlob11c[0x10];  // 0x11c — copied from ctx+0xc0
        uint8_t pad12c[0x34];    // 0x12c — unproven padding
        uint8_t mBlob160[0x10];  // 0x160 — copied from ctx+0xc0
        // (0x170 total, tail unmapped)
    };
}

// Naming closure: generic shared ctor ('default'/'param'/'name'/'type' strings only); per-class identity is a runtime param-id hash (dictionary via 0x710062fd48), not statically resolvable. Address-anchored name retained.
