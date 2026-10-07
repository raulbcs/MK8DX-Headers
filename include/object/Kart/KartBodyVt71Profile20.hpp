#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile20 — PROVISIONAL behavioral-profile name in the KartBodyVt71
    // family (census cluster kartbody_665, wip/vtable_census.json in mk8dx-400).
    // Profile = the set of band slots 0x80/0x88/0x90/0x98/0xa0 a member overrides
    // vs the family base 0x11bb5c0 (census slot_diff); per-slot semantics are
    // documented in KartBodyVt71.hpp. No layout beyond the base is implied: the
    // per-combo behavior lives in each member's vtable, not in new fields.
    //
    // All addresses are census VMA (dump-relative; runtime = +0x7100000000).
    // alloc=none: no alloc call adjacent to the construction site was found by
    // the census (in-place or other alloc path).
    //
    // Band overrides: 0x88, 0x90.
    // Covers 4 of the 665 family vtables; member vtable sizes n=71..71.
    // Other diff slots (members x count):
    //      0x18 x4 0x1c0 x4 0x138 x2
    // MI offset-to-top: none (no secondary base in this profile).
    //
    // Members (4) — vptr n cell site ctor_fn alloc:
    // - 0x11d6c00 n=71 cell=0x12ff6f8 site=0x1ed620 ctor=0x1ed5f8 alloc=0x208
    // - 0x11ee018 n=71 cell=0x1300b00 site=0x227738 ctor=0x227710 alloc=none
    // - 0x1214370 n=71 cell=0x1302f90 site=0x28f274 ctor=0x28dff0 alloc=none
    // - 0x123f090 n=71 cell=0x13056b8 site=0x320acc ctor=0x320aa4 alloc=0x208
    class KartBodyVt71Profile20 : public KartBodyVt71
    {
    };
}
