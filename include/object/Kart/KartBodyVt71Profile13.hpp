#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile13 — PROVISIONAL behavioral-profile name in the KartBodyVt71
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
    // Band overrides: 0x90, 0x98.
    // Covers 14 of the 665 family vtables; member vtable sizes n=71..74.
    // Other diff slots (members x count):
    //      0x18 x14 0xc0 x13 0x1c0 x13 0x0 x12 0x8 x12 0xf8 x12 0x108 x12 0x230 x6 0xd0 x1
    //     0x190 x1 0x1b0 x1
    // MI offset-to-top: 12 of 14 members carry a secondary base
    // (slots 0x0/0x8 differ from the base vtable).
    //
    // Members (14) — vptr n cell site ctor_fn alloc:
    // - 0x11f92d8 n=71 cell=0x1301380 site=0x242ea0 ctor=0x242e78 alloc=none
    // - 0x123e710 n=73 cell=0x1305648 site=0x31fd9c ctor=0x31fd74 alloc=0x208
    // - 0x123f3a0 n=73 cell=0x13056d0 site=0x320f70 ctor=0x320f34 alloc=0x210
    // - 0x123f6c0 n=73 cell=0x13056d8 site=0x321170 ctor=0x321148 alloc=0x210
    // - 0x124d4e8 n=73 cell=0x1306430 site=0x34ee60 ctor=0x34ee48 alloc=0x208
    // - 0x124d808 n=73 cell=0x1306410 site=0x34eca4 ctor=0x34ec7c alloc=0x208
    // - 0x124de48 n=73 cell=0x1306428 site=0x34ee10 ctor=0x34ede8 alloc=0x208
    // - 0x124e168 n=73 cell=0x1306418 site=0x34ed14 ctor=0x34ecec alloc=0x208
    // - 0x124e488 n=73 cell=0x1306478 site=0x347228 ctor=0x3471f0 alloc=0x358
    // - 0x124e7a8 n=74 cell=0x1306490 site=0x34f738 ctor=0x34f710 alloc=0x208
    // - 0x124edf8 n=73 cell=0x13064c0 site=0x3509b4 ctor=0x35098c alloc=0x208
    // - 0x125ae88 n=71 cell=0x1306d48 site=0x375910 ctor=0x3758e8 alloc=none
    // - 0x125b198 n=73 cell=0x1306d60 site=0x375d78 ctor=0x375d50 alloc=0x208
    // - 0x125b4b8 n=73 cell=0x1306d78 site=0x37602c ctor=0x376004 alloc=0x208
    class KartBodyVt71Profile13 : public KartBodyVt71
    {
    };
}
