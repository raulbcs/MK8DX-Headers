#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile8 — PROVISIONAL behavioral-profile name in the KartBodyVt71
    // family.
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (census slot_diff); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are census VMA (dump-relative; runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site was found by
    // the census (in-place or other alloc path).
    //
    // Band overrides: 0x80, 0x90, 0x98.
    // Covers 19 of the 665 family vtables; member vtable sizes n=71..76.
    // Other diff slots (members x count):
    //      0x18 x19 0xc0 x17 0x1c0 x17 0x0 x15 0x8 x15 0xf8 x15 0x108 x15 0x10 x6 0x170 x4 0x78 x3
    //     0x158 x3 0x168 x3 0x120 x2 0x128 x2 0x138 x2 0x140 x2 0x160 x2 0x198 x2 0x1b0 x2
    //     0x230 x2 0xc8 x1 0xd0 x1 0xf0 x1 0x1e0 x1
    // MI offset-to-top: 15 of 19 members carry a secondary base
    // (slots 0x0/0x8 differ from the base vtable).
    //
    // Members (19) — vptr n cell site ctor_fn alloc:
    // - 0x11bcfd8 n=73 cell=0x12fd768 site=0x19e128 ctor=0x19e0c0 alloc=0x270
    // - 0x11c1d00 n=73 cell=0x12fdc20 site=0x1ab09c ctor=0x1ab034 alloc=0x230
    // - 0x11c2020 n=73 cell=0x12fdc28 site=0x1ab128 ctor=0x1ab0c4 alloc=0x230
    // - 0x11ea3a0 n=76 cell=0x1300800 site=0x21f710 ctor=0x21f6b0 alloc=0x268
    // - 0x11ea6d8 n=76 cell=0x1300808 site=0x21f7b4 ctor=0x21f754 alloc=0x268
    // - 0x11ec1b0 n=73 cell=0x1300a20 site=0x22590c ctor=0x2258dc alloc=0x240
    // - 0x11f56a8 n=73 cell=0x1301138 site=0x238294 ctor=0x2381b0 alloc=0x208
    // - 0x12006e0 n=74 cell=0x1301948 site=0x254630 ctor=0x254604 alloc=0x2a0
    // - 0x1200a08 n=74 cell=0x1301940 site=0x2545cc ctor=0x25452c alloc=0x2a0
    // - 0x120ffb0 n=71 cell=0x1302c28 site=0x285ff8 ctor=0x285fd0 alloc=none
    // - 0x12102c0 n=71 cell=0x1302c38 site=0x286880 ctor=0x286868 alloc=none
    // - 0x1218778 n=73 cell=0x13034d0 site=0x2a4eb0 ctor=0x2a4994 alloc=0x218
    // - 0x1224a38 n=74 cell=0x1304088 site=0x2d5978 ctor=0x2d5928 alloc=0x240
    // - 0x12251c0 n=74 cell=0x1304170 site=0x2d9090 ctor=0x2d905c alloc=0x258
    // - 0x12254e8 n=74 cell=0x1304178 site=0x2d90fc ctor=0x2d90d4 alloc=0x218
    // - 0x12334c0 n=73 cell=0x1304d10 site=0x2fcbb8 ctor=0x2fcaf0 alloc=0x228
    // - 0x1233b30 n=73 cell=0x1304d18 site=0x2fcc1c ctor=0x2fcaf0 alloc=0x218
    // - 0x124db28 n=73 cell=0x1306420 site=0x34ed84 ctor=0x34ed5c alloc=0x218
    // - 0x124ead0 n=74 cell=0x13064a8 site=0x34fd54 ctor=0x34fd14 alloc=0x230
    class KartBodyVt71Profile8 : public KartBodyVt71
    {
    };
}
