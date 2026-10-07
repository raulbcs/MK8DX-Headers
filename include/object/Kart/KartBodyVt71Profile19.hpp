#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile19 — PROVISIONAL behavioral-profile name in the KartBodyVt71
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
    // Band overrides: none (band identical to the base vtable).
    // Covers 6 of the 665 family vtables; member vtable sizes n=71..72.
    // Other diff slots (members x count):
    //      0x18 x5 0x1c0 x5
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (6) — vptr n cell site ctor_fn alloc:
    // - 0x11bb5c0 n=71 cell=0x12fd6a8 site=0x1988b8 ctor=0x198888 alloc=none
    // - 0x11c8430 n=72 cell=0x12fe520 site=0x1c5438 ctor=0x1c5410 alloc=none
    // - 0x11cf140 n=71 cell=0x12fecb0 site=0x1c6220 ctor=0x1c6150 alloc=none
    // - 0x12506d8 n=71 cell=0x1306500 site=0x348e4c ctor=0x348e14 alloc=none
    // - 0x12509e8 n=71 cell=0x1306508 site=0x350e38 ctor=0x350e10 alloc=0x240
    // - 0x1250cf8 n=71 cell=0x1306510 site=0x350e8c ctor=0x350e64 alloc=0x240
    class KartBodyVt71Profile19 : public KartBodyVt71
    {
    };
}
