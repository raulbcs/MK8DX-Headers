#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile6 — PROVISIONAL behavioral-profile name in the KartBodyVt71
    // family.
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are dump-relative VMAs (runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
    //
    // Band overrides: 0x80, 0x90.
    // Covers 32 of the 665 family vtables; member vtable sizes n=71..72.
    // Other diff slots (members x count):
    //      0x18 x32 0x1c0 x30 0x1e0 x16 0x170 x6 0x10 x4 0x1f0 x3 0x0 x2 0x8 x2 0x78 x2 0xb0 x2
    //     0xb8 x1
    // MI offset-to-top: 2 of 32 members carry a secondary base
    // (slots 0x0/0x8 differ from the base vtable).
    //
    // Members (32) — vptr n cell site ctor_fn alloc:
    // - 0x11c1158 n=71 cell=0x12fdb28 site=0x1a9308 ctor=0x1a92cc alloc=none
    // - 0x11e5598 n=71 cell=0x1300430 site=0x212b1c ctor=0x212698 alloc=0x218
    // - 0x11f8fc8 n=71 cell=0x1301390 site=0x242f9c ctor=0x242f74 alloc=0x2a0
    // - 0x11f95e8 n=71 cell=0x1301398 site=0x238bbc ctor=0x238988 alloc=none
    // - 0x11f98f8 n=71 cell=0x1301400 site=0x238d74 ctor=0x238d64 alloc=none
    // - 0x11f9c08 n=71 cell=0x1301408 site=0x23936c ctor=0x239358 alloc=none
    // - 0x11ff680 n=71 cell=0x1301830 site=0x24f5cc ctor=0x24f5a4 alloc=0x240
    // - 0x1201040 n=71 cell=0x1301958 site=0x254760 ctor=0x25472c alloc=0x2a0
    // - 0x1201408 n=71 cell=0x13019c8 site=0x256098 ctor=0x256070 alloc=none
    // - 0x1201718 n=71 cell=0x13019d8 site=0x2391d8 ctor=0x2391b0 alloc=none
    // - 0x1201a28 n=71 cell=0x13019d0 site=0x256100 ctor=0x2560d4 alloc=none
    // - 0x1201d38 n=71 cell=0x13019e0 site=0x2561d0 ctor=0x2561a0 alloc=none
    // - 0x1215390 n=71 cell=0x1303078 site=0x291310 ctor=0x29107c alloc=0x248
    // - 0x1236df8 n=71 cell=0x1304f90 site=0x308aa4 ctor=0x308270 alloc=0x208
    // - 0x1238430 n=71 cell=0x1305120 site=0x30fc58 ctor=0x30fbb4 alloc=0x220
    // - 0x1242400 n=71 cell=0x1305968 site=0x325e90 ctor=0x325e68 alloc=0x250
    // - 0x1242830 n=72 cell=0x1305970 site=0x325ebc ctor=0x325e68 alloc=0x250
    // - 0x1242b48 n=72 cell=0x1305978 site=0x325f54 ctor=0x325f00 alloc=0x250
    // - 0x12578f0 n=71 cell=0x1306b10 site=0x369b8c ctor=0x369b64 alloc=0x218
    // - 0x1257c00 n=71 cell=0x1306b18 site=0x369c28 ctor=0x369be8 alloc=0x218
    // - 0x125b7d8 n=72 cell=0x1306d90 site=0x3767fc ctor=0x3767cc alloc=none
    // - 0x125baf0 n=72 cell=0x1306d98 site=0x376864 ctor=0x376834 alloc=none
    // - 0x125be08 n=72 cell=0x1306da0 site=0x3768cc ctor=0x37689c alloc=none
    // - 0x125c430 n=71 cell=0x1306e38 site=0x37767c ctor=0x377664 alloc=0x218
    // - 0x125ca58 n=72 cell=0x1306e18 site=0x3774f4 ctor=0x3774c4 alloc=0x218
    // - 0x125cd70 n=72 cell=0x1306e20 site=0x37755c ctor=0x37752c alloc=0x218
    // - 0x125d088 n=72 cell=0x1306e28 site=0x3775c4 ctor=0x377594 alloc=0x218
    // - 0x125d3a0 n=72 cell=0x1306e30 site=0x37762c ctor=0x3775fc alloc=0x218
    // - 0x125d6b8 n=72 cell=0x1306eb0 site=0x37856c ctor=0x3784fc alloc=0x218
    // - 0x125d9d0 n=72 cell=0x1306eb8 site=0x37860c ctor=0x37859c alloc=0x218
    // - 0x125dce8 n=72 cell=0x1306ec0 site=0x3786ac ctor=0x37863c alloc=0x218
    // - 0x125e000 n=72 cell=0x1306ec8 site=0x37874c ctor=0x3786dc alloc=0x218
    class KartBodyVt71Profile6 : public KartBodyVt71
    {
    };
}
