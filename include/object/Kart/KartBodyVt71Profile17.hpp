#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile17 — PROVISIONAL behavioral-profile name in the KartBodyVt71
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
    // Band overrides: 0x80, 0x90, 0xa0.
    // Covers 7 of the 665 family vtables; member vtable sizes n=71..71.
    // Other diff slots (members x count):
    //      0x18 x7 0xf0 x6 0xf8 x6 0x158 x6 0x1c0 x6 0x10 x2 0x1f8 x1
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (7) — vptr n cell site ctor_fn alloc:
    // - 0x11c0278 n=71 cell=0x12fd998 site=0x1a3d44 ctor=0x1a3d1c alloc=0x238
    // - 0x11e5a20 n=71 cell=0x13004a0 site=0x213618 ctor=0x213160 alloc=0x208
    // - 0x1202ec0 n=71 cell=0x1301bd8 site=0x259a88 ctor=0x25996c alloc=none
    // - 0x1252bf8 n=71 cell=0x13066f0 site=0x3553dc ctor=0x3553b4 alloc=0x208
    // - 0x1259408 n=71 cell=0x1306c58 site=0x3713c4 ctor=0x37139c alloc=0x208
    // - 0x1259dc8 n=71 cell=0x1306c50 site=0x371354 ctor=0x371324 alloc=0x298
    // - 0x125a0d8 n=71 cell=0x1306c60 site=0x371428 ctor=0x3713f8 alloc=0x208
    class KartBodyVt71Profile17 : public KartBodyVt71
    {
    };
}
