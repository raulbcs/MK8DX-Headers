#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile12 — PROVISIONAL behavioral-profile name in the KartBodyVt71
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
    // Band overrides: 0xa0.
    // Covers 15 of the 665 family vtables; member vtable sizes n=71..72.
    // Other diff slots (members x count):
    //      0x18 x15 0x28 x15 0xb8 x15 0x1c0 x14 0x1e0 x5 0x220 x3 0x78 x2 0x1b0 x2 0xc0 x1
    //     0x138 x1 0x170 x1
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (15) — vptr n cell site ctor_fn alloc:
    // - 0x11bb8d0 n=71 cell=0x1303090 site=0x291a34 ctor=0x2918ac alloc=0x370
    // - 0x11c6638 n=71 cell=0x12fe320 site=0x1bfe64 ctor=0x1bfe3c alloc=none
    // - 0x11e9a28 n=71 cell=0x1300778 site=0x21de38 ctor=0x21de10 alloc=none
    // - 0x11e9d38 n=71 cell=0x1300780 site=0x21de98 ctor=0x21de70 alloc=none
    // - 0x11edd08 n=71 cell=0x1300ae8 site=0x22757c ctor=0x227554 alloc=none
    // - 0x11f8678 n=71 cell=0x13012c0 site=0x241690 ctor=0x241648 alloc=none
    // - 0x11f89a0 n=71 cell=0x13012f8 site=0x2429e4 ctor=0x24299c alloc=none
    // - 0x120c108 n=71 cell=0x1302508 site=0x271354 ctor=0x27132c alloc=none
    // - 0x1211fc0 n=71 cell=0x1302df8 site=0x28c064 ctor=0x28b274 alloc=none
    // - 0x1213248 n=71 cell=0x1302e70 site=0x28c90c ctor=0x28b274 alloc=none
    // - 0x12190b8 n=71 cell=0x1303518 site=0x2a5664 ctor=0x2a563c alloc=none
    // - 0x12193c8 n=71 cell=0x1303520 site=0x2a56c4 ctor=0x2a569c alloc=none
    // - 0x1237108 n=72 cell=0x1304fa8 site=0x308e2c ctor=0x308270 alloc=0x208
    // - 0x12528e8 n=71 cell=0x13066d8 site=0x355134 ctor=0x3550f4 alloc=none
    // - 0x12545b0 n=71 cell=0x13068f0 site=0x361124 ctor=0x3610fc alloc=none
    class KartBodyVt71Profile12 : public KartBodyVt71
    {
    };
}
