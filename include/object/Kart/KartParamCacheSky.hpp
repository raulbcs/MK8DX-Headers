#pragma once

#include <cstdint>

#include "object/Kart/KartParamCache.hpp"

namespace object
{
    // KartParamCacheSky — named from ctor string evidence: ctor string tag 'aglsky' + params sun_indensity/rayleigh (0xf02b5f-0xf1bfea) (was PROVISIONAL vtable-anchored KartParamCacheVt2fb8) (vptr 0x12f2fb8, cell 0x1315270, n=13, site 0xaae038, ctor 0xaadfec).
    // Variant of the 0x63c6f8 param-cache cluster.
    class KartParamCacheSky : public KartParamCache
    {
    public:
        uint8_t mPad40[0x208];   // 0x40 — unproven gap
        uint64_t mField248;      // 0x248 — ctor-written
        uint8_t mPad250[0x330];  // 0x250 — unproven gap
        uint64_t mField580;      // 0x580 — ctor-written
        uint8_t mPad588[0x690];  // 0x588 — unproven gap
        uint64_t mFieldc18;      // 0xc18 — ctor-written
        uint8_t mPadc20[0x30];   // 0xc20 — unproven gap
        uint64_t mFieldc50;      // 0xc50 — ctor-written
        uint8_t mPadc58[0x30];   // 0xc58 — unproven gap
        uint64_t mFieldc88;      // 0xc88 — ctor-written
        uint8_t mPadc90[0x38];   // 0xc90 — unproven gap
        uint32_t mZerocc8;       // 0xcc8 — ctor zero
        uint8_t mPadccc[0x4];    // 0xccc — unproven gap
        uint64_t mZerocd0;       // 0xcd0 — ctor zero
        uint64_t mZerocd8;       // 0xcd8 — ctor zero
        uint32_t mZeroce0;       // 0xce0 — ctor zero
        uint8_t mPadce4[0x4];    // 0xce4 — unproven gap
        uint64_t mZeroce8;       // 0xce8 — ctor zero
        uint64_t mZerocf0;       // 0xcf0 — ctor zero
        uint32_t mZerocf8;       // 0xcf8 — ctor zero
        uint8_t mPadcfc[0x4];    // 0xcfc — unproven gap
        uint64_t mZerod00;       // 0xd00 — ctor zero
        uint64_t mZerod08;       // 0xd08 — ctor zero
        uint32_t mZerod10;       // 0xd10 — ctor zero
        uint8_t mPadd14[0x4];    // 0xd14 — unproven gap
        uint64_t mZerod18;       // 0xd18 — ctor zero
        uint64_t mZerod20;       // 0xd20 — ctor zero
        uint32_t mZerod28;       // 0xd28 — ctor zero
        uint8_t mPadd2c[0x4];    // 0xd2c — unproven gap
        uint64_t mZerod30;       // 0xd30 — ctor zero
        uint64_t mZerod38;       // 0xd38 — ctor zero
        uint32_t mZerod40;       // 0xd40 — ctor zero
        uint8_t mPadd44[0x4];    // 0xd44 — unproven gap
        uint64_t mZerod48;       // 0xd48 — ctor zero
        uint64_t mZerod50;       // 0xd50 — ctor zero
        uint32_t mZerod58;       // 0xd58 — ctor zero
        uint8_t mPadd5c[0x4];    // 0xd5c — unproven gap
        uint64_t mZerod60;       // 0xd60 — ctor zero
        uint64_t mZerod68;       // 0xd68 — ctor zero
        uint32_t mZerod70;       // 0xd70 — ctor zero
        uint8_t mPadd74[0x4];    // 0xd74 — unproven gap
        uint64_t mZerod78;       // 0xd78 — ctor zero
        uint64_t mZerod80;       // 0xd80 — ctor zero
        uint32_t mZerod88;       // 0xd88 — ctor zero
        uint8_t mPadd8c[0x4];    // 0xd8c — unproven gap
        uint64_t mZerod90;       // 0xd90 — ctor zero
        uint64_t mZerod98;       // 0xd98 — ctor zero
        uint32_t mZeroda0;       // 0xda0 — ctor zero
        uint8_t mPadda4[0x4];    // 0xda4 — unproven gap
        uint64_t mZeroda8;       // 0xda8 — ctor zero
    };
}
