#pragma once

#include "object/Kart/KartBodyVt71.hpp"

namespace object
{
    // KartBodyVt71Profile10 — PROVISIONAL behavioral-profile name in the KartBodyVt71
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
    // Band overrides: 0x98.
    // Covers 18 of the 665 family vtables; member vtable sizes n=71..74.
    // Other diff slots (members x count):
    //      0x18 x18 0xc0 x17 0x108 x16 0x1c0 x16 0x0 x10 0x8 x10 0xf8 x10 0x100 x6 0x1e0 x2
    //     0x1b0 x1
    // MI offset-to-top: 10 of 18 members carry a secondary base
    // (slots 0x0/0x8 differ from the base vtable).
    //
    // Members (18) — vptr n cell site ctor_fn alloc:
    // - 0x11be2c8 n=73 cell=0x12fd888 site=0x1a096c ctor=0x1a0944 alloc=0x208
    // - 0x11be628 n=73 cell=0x12fd8a8 site=0x1a0bf0 ctor=0x1a0bc8 alloc=0x208
    // - 0x11be948 n=73 cell=0x12fd8c0 site=0x1a0ecc ctor=0x1a0ea4 alloc=0x208
    // - 0x11bec68 n=73 cell=0x12fd8d8 site=0x1a11a8 ctor=0x1a1180 alloc=0x208
    // - 0x11bef88 n=73 cell=0x12fd8e0 site=0x1a121c ctor=0x1a11f4 alloc=0x208
    // - 0x11bf2a8 n=73 cell=0x12fd908 site=0x10560c ctor=0x1055f4 alloc=none
    // - 0x11bfc08 n=73 cell=0x12fd950 site=0x1a1edc ctor=0x1a1ec4 alloc=0x210
    // - 0x11d2108 n=71 cell=0x12ff0c0 site=0x1df32c ctor=0x1df2ec alloc=none
    // - 0x11e69a8 n=73 cell=0x1300538 site=0x213bd8 ctor=0x213b38 alloc=0x228
    // - 0x11ead88 n=73 cell=0x13008b8 site=0x222904 ctor=0x2228dc alloc=0x208
    // - 0x1200d30 n=71 cell=0x1301950 site=0x254700 ctor=0x2546d8 alloc=0x2a0
    // - 0x124f118 n=73 cell=0x13064d8 site=0x350c10 ctor=0x350be8 alloc=0x208
    // - 0x124f758 n=73 cell=0x13064e8 site=0x350cb8 ctor=0x350c90 alloc=0x208
    // - 0x124fd88 n=73 cell=0x1306518 site=0x350ee0 ctor=0x350eb8 alloc=0x240
    // - 0x12503b8 n=73 cell=0x13064e0 site=0x350c64 ctor=0x350c3c alloc=0x208
    // - 0x1251008 n=73 cell=0x1306520 site=0x350f34 ctor=0x350f0c alloc=0x240
    // - 0x1251328 n=73 cell=0x1306528 site=0x350f88 ctor=0x350f60 alloc=0x240
    // - 0x1259098 n=74 cell=0x1306c00 site=0x36fc80 ctor=0x36ec38 alloc=0x208
    class KartBodyVt71Profile10 : public KartBodyVt71
    {
    };
}
