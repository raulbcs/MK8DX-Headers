#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile11 — PROVISIONAL behavioral-profile name in the KartBodyVt71
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
    // Band overrides: 0x98, 0xa0.
    // Covers 16 of the 665 family vtables; member vtable sizes n=71..72.
    // Other diff slots (members x count):
    //      0x18 x16 0x28 x15 0xb8 x15 0x1c0 x14 0xc0 x13 0x108 x13 0x1b0 x1
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (16) — vptr n cell site ctor_fn alloc:
    // - 0x11ca2f0 n=71 cell=0x12fe688 site=0x1c89ac ctor=0x1c8964 alloc=none
    // - 0x11dbca0 n=72 cell=0x12ffb18 site=0x1f9cd8 ctor=0x1f9cb0 alloc=none
    // - 0x11dbfb8 n=72 cell=0x12ffb20 site=0x1f9d2c ctor=0x1f9d04 alloc=none
    // - 0x11dc2d0 n=72 cell=0x12ffb28 site=0x1f9d80 ctor=0x1f9d58 alloc=none
    // - 0x11dc5e8 n=72 cell=0x12ffb30 site=0x1f9dd4 ctor=0x1f9dac alloc=none
    // - 0x11dc900 n=72 cell=0x12ffb38 site=0x1f9e28 ctor=0x1f9e00 alloc=none
    // - 0x11dcc18 n=72 cell=0x12ffb40 site=0x1f9e7c ctor=0x1f9e00 alloc=none
    // - 0x1216cb0 n=71 cell=0x1303228 site=0x293728 ctor=0x2936e8 alloc=none
    // - 0x123d168 n=72 cell=0x13055e0 site=0x31f7a8 ctor=0x31f790 alloc=none
    // - 0x123d480 n=72 cell=0x13055b0 site=0x315fe0 ctor=0x315f50 alloc=0x2a8
    // - 0x123d798 n=72 cell=0x13055b8 site=0x31f5a8 ctor=0x31f580 alloc=none
    // - 0x123dab0 n=72 cell=0x13055c0 site=0x31f608 ctor=0x31f5e0 alloc=none
    // - 0x123ddc8 n=72 cell=0x13055c8 site=0x31f668 ctor=0x31f640 alloc=none
    // - 0x123e0e0 n=72 cell=0x13055d0 site=0x31f6c8 ctor=0x31f6a0 alloc=none
    // - 0x123e3f8 n=72 cell=0x13055d8 site=0x31f728 ctor=0x31f700 alloc=none
    // - 0x123ea30 n=71 cell=0x1305660 site=0x320034 ctor=0x32000c alloc=0x208
    class KartBodyVt71Profile11 : public KartBodyVt71
    {
    };
}
