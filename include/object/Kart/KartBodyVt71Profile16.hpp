#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile16 — PROVISIONAL behavioral-profile name in the KartBodyVt71
    // family.
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (slot-diff analysis); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are dump-relative VMAs (runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site (in-place or other alloc path).
    //
    // Band overrides: 0x88, 0x90, 0xa0.
    // Covers 10 of the 665 family vtables; member vtable sizes n=72..74.
    // Other diff slots (members x count):
    //      0x18 x10 0x1c0 x9 0x198 x7 0xc0 x5 0x138 x5 0x10 x3 0x148 x2 0x158 x2
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (10) — vptr n cell site ctor_fn alloc:
    // - 0x11d01b8 n=72 cell=0x12fed80 site=0x1db398 ctor=0x1db374 alloc=0x68
    // - 0x11f6820 n=72 cell=0x1301290 site=0x23f6a4 ctor=0x23f688 alloc=0x210
    // - 0x11f74f0 n=72 cell=0x1301270 site=0x23f4b8 ctor=0x23f484 alloc=0x208
    // - 0x11f7808 n=72 cell=0x1301278 site=0x23863c ctor=0x2385f8 alloc=0x208
    // - 0x11f7e70 n=72 cell=0x1301288 site=0x23f648 ctor=0x23f61c alloc=0x210
    // - 0x1213bb8 n=73 cell=0x1302f18 site=0x28eb20 ctor=0x28dff0 alloc=0x210
    // - 0x1213f00 n=73 cell=0x1302f20 site=0x28eba0 ctor=0x28dff0 alloc=0x210
    // - 0x121c110 n=72 cell=0x13037e8 site=0x2afe68 ctor=0x2afbb8 alloc=0x208
    // - 0x12538c8 n=74 cell=0x1306868 site=0x360210 ctor=0x3601b8 alloc=0x230
    // - 0x125e6d0 n=72 cell=0x1306f58 site=0x379e94 ctor=0x379e3c alloc=0x230
    class KartBodyVt71Profile16 : public KartBodyVt71
    {
    };
}
